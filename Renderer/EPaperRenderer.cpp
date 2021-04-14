//
// Created by Onur on 22.03.2021.
//

#include "EPaperRenderer.h"

EPaperRenderer::EPaperRenderer(const double ePaperVCOM) :ePaperDisplay(EPaperDisplay(ePaperVCOM)) {
    ePaperDisplay.connect();
    ePaperDisplay.clearAndRefresh();
}

void EPaperRenderer::render(const Goban &goban) const {
    auto frameBuffer = ePaperDisplay.createFrameBuffer();
    frameBuffer.drawLine(0, 0, 800, 800, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
    ePaperDisplay.refresh(frameBuffer.frameBuffer);
}

EPaperRenderer::~EPaperRenderer() { }

EPaperRenderer::EPaperRenderer(EPaperDisplay ePaperDisplay) : ePaperDisplay(ePaperDisplay) {
    ePaperDisplay.connect();
}

/*
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
*/