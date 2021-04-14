#ifndef DIGITAL_GO_BOARD_EPAPERRENDERER_H
#define DIGITAL_GO_BOARD_EPAPERRENDERER_H

#include "Renderer.h"
#include "./EPaper/EPaperDisplay.h"
#include "../FrameBuffer.h"

class EPaperRenderer : public Renderer {
private:
    EPaperDisplay ePaperDisplay;
public:
    EPaperRenderer(const double ePaperVCOM);

    EPaperRenderer(EPaperDisplay ePaperDisplay);

    ~EPaperRenderer();
    void render(const Goban &goban) const override;
};


#endif
