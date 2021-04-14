#ifndef DIGITAL_GO_BOARD_EPAPERRENDERER_H
#define DIGITAL_GO_BOARD_EPAPERRENDERER_H

extern "C" {
#include "../libs/IT8951/Config/DEV_Config.h"
#include "../libs/IT8951/e-Paper/EPD_IT8951.h"
#include "../libs/IT8951/GUI/GUI_Paint.h"
}
#include "Renderer.h"

class EPaperRenderer : public Renderer {
private:
    IT8951_Dev_Info deviceInfo;
    uint16_t panelWidth;
    uint16_t panelHeight;
    uint32_t initTargetMemoryAddress;
    char* lutVersion;
    uint8_t a2Mode;

public:
    EPaperRenderer();
    ~EPaperRenderer();
    void render(const Goban &goban) const override;
};


#endif
