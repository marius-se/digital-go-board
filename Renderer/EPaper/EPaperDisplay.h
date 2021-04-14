#ifndef DIGITAL_GO_BOARD_EPAPERDISPLAY_H
#define DIGITAL_GO_BOARD_EPAPERDISPLAY_H

extern "C" {
#include "../../libs/IT8951/e-Paper/EPD_IT8951.h"
}

#include "optional"
#include "BCM2835Connection.h"
#include "../../FrameBuffer.h"

class EPaperDisplay {
private:
    const double vcom;
    BCM2835Connection bcm2835Connection = BCM2835Connection();
    std::optional<IT8951_Dev_Info> it8951DeviceInfo;

    uint32_t getMemoryAddress() const;
    uint8_t getA2Mode() const;
public:
    explicit EPaperDisplay(double vcom);
    ~EPaperDisplay();
    void connect();
    void clearAndRefresh() const;
    FrameBuffer createFrameBuffer() const;
    void refresh(uint8_t* frameBuffer) const;
};


#endif
