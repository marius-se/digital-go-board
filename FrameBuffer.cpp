#include "FrameBuffer.h"

FrameBuffer::FrameBuffer(size_t size, uint8_t bitsPerPixel, uint16_t width, uint16_t height) :bitsPerPixel{bitsPerPixel} {
    frameBuffer = new uint8_t[size]{};
    Paint_NewImage(frameBuffer, width, height, 0, BLACK);
    Paint_SelectImage(frameBuffer);
    Paint_SetBitsPerPixel(bitsPerPixel);
    Paint_Clear(WHITE);
}

FrameBuffer::~FrameBuffer() {
    delete[] frameBuffer;
}

void FrameBuffer::drawLine(
        uint16_t startX,
        uint16_t startY,
        uint16_t endX,
        uint16_t endY,
        uint16_t color,
        DOT_PIXEL lineWidth,
        LINE_STYLE lineStyle
        ) {
    Paint_SelectImage(frameBuffer);
    Paint_DrawLine(startX, startY, endX, endY, color, lineWidth, lineStyle);
}