#ifndef DIGITAL_GO_BOARD_EPAPERRENDERER_H
#define DIGITAL_GO_BOARD_EPAPERRENDERER_H

#include "Renderer.h"

#include "../libs/IT8951-ePaper/Config/DEV_Config.h"
#include "../libs/IT8951-ePaper/e-Paper/EPD_IT8951.h"

class EPaperRenderer : public Renderer {
public:
    EPaperRenderer() {
        //Init the BCM2835 Device
        if(DEV_Module_Init()!=0){
            DEV_Module_Exit();
            throw std::runtime_error("Could not initialize bcm2835.");
        }

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
            DEV_Module_Exit();
            EPD_IT8951_Sleep();
            throw std::runtime_error("Unsupported E Paper display.");
        }

        EPD_IT8951_Init_Refresh(deviceInfo, initTargetMemoryAddress);
        EPD_IT8951_Sleep();

        DEV_Delay_ms(5000);
        DEV_Module_Exit();
    }

    void render(const Goban &goban) const override {
        std::cout << "Hello E Paper Renderer!";
    }
private:
    IT8951_Dev_Info deviceInfo;
    uint16_t panelWidth;
    uint16_t panelHeight;
    uint32_t initTargetMemoryAddress;
    char* lutVersion;
    uint8_t a2Mode;
};

#endif
