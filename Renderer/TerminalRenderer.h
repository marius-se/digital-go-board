#ifndef DIGITAL_GO_BOARD_TERMINALRENDERER_H
#define DIGITAL_GO_BOARD_TERMINALRENDERER_H


#include "Renderer.h"

struct TerminalRenderer : Renderer {
public:
    void render(const Goban& goban) const override;
};


#endif
