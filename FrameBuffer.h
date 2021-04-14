#ifndef DIGITAL_GO_BOARD_FRAMEBUFFER_H
#define DIGITAL_GO_BOARD_FRAMEBUFFER_H

extern "C" {
#include "./libs/IT8951/GUI/GUI_Paint.h"
}

class FrameBuffer {
public:
    uint8_t* frameBuffer;
    uint8_t bitsPerPixel;
    FrameBuffer(size_t size, uint8_t bitsPerPixel, uint16_t width, uint16_t height);
    ~FrameBuffer();
    void drawLine(
            uint16_t startX,
            uint16_t startY,
            uint16_t endX,
            uint16_t endY,
            uint16_t color,
            DOT_PIXEL Line_width,
            LINE_STYLE Line_Style
            );
};


#endif
