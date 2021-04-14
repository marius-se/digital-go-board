#ifndef DIGITAL_GO_BOARD_EPAPERRENDERER_H
#define DIGITAL_GO_BOARD_EPAPERRENDERER_H

#include "Renderer.h"
#include "./EPaper/EPaperDisplay.h"
#include "../FrameBuffer.h"

class EPaperRenderer : public Renderer {
private:
    EPaperDisplay ePaperDisplay;
    uint16_t stoneSize;

    void drawEmptyGoBoard(uint16_t gameSize);
public:
    EPaperRenderer(double vcom, uint16_t stoneSize);
    ~EPaperRenderer();
    void render(const Goban &goban) const override;
};


#endif
