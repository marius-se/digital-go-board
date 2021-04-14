//
// Created by Onur on 22.03.2021.
//

#include "EPaperRenderer.h"

EPaperRenderer::EPaperRenderer() {
    bcm2835Connection = BCM2835Connection();
    bcm2835Connection.connect();

    // ePaperDisplay = EPaperDisplay(vcom: 1.48);
    // ePaperDisplay.connect();
    // ePaperDisplay.fullRefresh();

    const uint16_t vcom = 1.48 * 1000;
    deviceInfo = EPD_IT8951_Init(vcom);
    panelWidth = deviceInfo.Panel_W;
    panelHeight = deviceInfo.Panel_H;
    initTargetMemoryAddress = deviceInfo.Memory_Addr_L | (deviceInfo.Memory_Addr_H << 16);
    lutVersion = (char*)deviceInfo.LUT_Version;

    if (strcmp(lutVersion, "M841_TFA5210") == 0 ){
        //10.3inch e-Paper HAT(1872,1404)
        a2Mode = 6;
    } else {
        EPD_IT8951_Sleep();
        throw std::runtime_error("Unsupported E Paper display.");
    }

    EPD_IT8951_Init_Refresh(deviceInfo, initTargetMemoryAddress);
}

void EPaperRenderer::render(const Goban &goban) const {
    const uint16_t stoneSizeInPixel = 120;
    const uint8_t gameSize = 9;
    const uint16_t boardSizeInPixel = (gameSize - 1) * stoneSizeInPixel;
    const uint16_t displayWidth = 1872;
    const uint16_t displayHeight = 1404;
    const uint8_t bitsPerPixel = 4;
    const auto currentBoardState = goban.getCurrentState();
    uint16_t Display_Area_Width = deviceInfo.Panel_W;
    uint16_t Display_Area_Height = deviceInfo.Panel_H;

    const uint16_t startPointX = (displayWidth / 2) - (boardSizeInPixel / 2);
    const uint16_t startPointY = (displayHeight / 2) - (boardSizeInPixel / 2);

    uint32_t imageSize = ((deviceInfo.Panel_W * bitsPerPixel % 8 == 0) ? (deviceInfo.Panel_W * bitsPerPixel / 8 ) : (deviceInfo.Panel_W * bitsPerPixel / 8 + 1)) * deviceInfo.Panel_H;
    auto* refreshFrameBuffer = new uint8_t[imageSize]{};

    Paint_NewImage(refreshFrameBuffer, deviceInfo.Panel_W, deviceInfo.Panel_H, 0, BLACK);
    Paint_SetBitsPerPixel(bitsPerPixel);
    Paint_Clear(WHITE);
    for (int x = 0; x <= boardSizeInPixel; x += stoneSizeInPixel) {
        Paint_DrawLine(startPointX + x, startPointY, startPointX + x, startPointY + boardSizeInPixel, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
    }
    for (int y = 0; y <= boardSizeInPixel; y += stoneSizeInPixel) {
        Paint_DrawLine(startPointX, startPointY + y, startPointX + boardSizeInPixel, startPointY + y, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
    }

    for (int x = 0; x < gameSize; ++x) {
        for (int y = 0; y < gameSize; ++y) {
            switch (currentBoardState[x][y]) {
                case none:
                    break;
                case black:
                    Paint_DrawCircle(startPointX + x * stoneSizeInPixel, startPointY + y * stoneSizeInPixel, stoneSizeInPixel / 2, BLACK, DOT_PIXEL_2X2, DRAW_FILL_FULL);
                    break;
                case white:
                    Paint_DrawCircle(startPointX + x * stoneSizeInPixel, startPointY + y * stoneSizeInPixel, stoneSizeInPixel / 2, BLACK, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
                    Paint_DrawCircle(startPointX + x * stoneSizeInPixel, startPointY + y * stoneSizeInPixel, stoneSizeInPixel / 2 - 1, WHITE, DOT_PIXEL_2X2, DRAW_FILL_FULL);
                    break;
            }
        }
    }

    EPD_IT8951_4bp_Refresh(refreshFrameBuffer, 0, 0, Display_Area_Width, Display_Area_Height, false, initTargetMemoryAddress, false);
    delete[] refreshFrameBuffer;
}

EPaperRenderer::~EPaperRenderer() {
    EPD_IT8951_Init_Refresh(deviceInfo, initTargetMemoryAddress);
    EPD_IT8951_Sleep();
}
