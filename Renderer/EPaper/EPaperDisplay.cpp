#include "iostream"
#include "stdexcept"
#include "EPaperDisplay.h"

EPaperDisplay::EPaperDisplay(const double vcom) :vcom(vcom) { }

EPaperDisplay::~EPaperDisplay() {
    if (it8951DeviceInfo) {
        std::cout << "Putting E-Paper display to sleep...";
        EPD_IT8951_Sleep();
    }
}

uint32_t EPaperDisplay::getMemoryAddress() const {
    if (it8951DeviceInfo) {
        return it8951DeviceInfo.value().Memory_Addr_L | (it8951DeviceInfo.value().Memory_Addr_H << 16);
    } else {
        throw std::runtime_error("EPaperDisplay connection is not established");
    }
}

uint8_t EPaperDisplay::getA2Mode() const {
    if (it8951DeviceInfo) {
        const auto lutVersion = (char*)it8951DeviceInfo.value().LUT_Version;
        if (strcmp(lutVersion, "M841_TFA5210") == 0 ) {
            return 6;
        } else {
            throw std::runtime_error("Unsupported E-Paper display");
        }
    }
}

FrameBuffer EPaperDisplay::createFrameBuffer(uint8_t bitsPerPixel) const {
    const size_t size = ((it8951DeviceInfo.value().Panel_W * bitsPerPixel % 8 == 0) ? (it8951DeviceInfo.value().Panel_W * bitsPerPixel / 8 ) : (it8951DeviceInfo.value().Panel_W * bitsPerPixel / 8 + 1)) * it8951DeviceInfo.value().Panel_H;
    return FrameBuffer(size, bitsPerPixel, getDisplayWidth(), getDisplayHeight());
}

void EPaperDisplay::connect() {
    if (!it8951DeviceInfo) {
        bcm2835Connection.connect();
        std::cout << "Connecting with E-Paper display...";
        it8951DeviceInfo = EPD_IT8951_Init(vcom * 1000);
    }
}

void EPaperDisplay::clearAndRefresh() const {
    if (it8951DeviceInfo) {
        std::cout << "Clearing and refreshing E-Paper display...";
        EPD_IT8951_Init_Refresh(it8951DeviceInfo.value(), getMemoryAddress());
    }
}

void EPaperDisplay::refresh(uint8_t* frameBuffer, uint8_t bitsPerPixel) const {
    if (it8951DeviceInfo) {
        switch (bitsPerPixel) {
            case 1:
                EPD_IT8951_1bp_Refresh(
                        frameBuffer,
                        0,
                        0,
                        getDisplayWidth(),
                        getDisplayHeight(),
                        getA2Mode(),
                        getMemoryAddress(),
                        false
                );
                break;
            case 4:
                EPD_IT8951_4bp_Refresh(
                        frameBuffer,
                        0,
                        0,
                        getDisplayWidth(),
                        getDisplayHeight(),
                        false,
                        getMemoryAddress(),
                        false
                        );
            default:
                break;
        }
    }
}

uint16_t EPaperDisplay::getDisplayWidth() const {
    return it8951DeviceInfo.value().Panel_W;
}

uint16_t EPaperDisplay::getDisplayHeight() const {
    return it8951DeviceInfo.value().Panel_H;
}