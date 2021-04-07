#ifndef DIGITAL_GO_BOARD_RENDERER_H
#define DIGITAL_GO_BOARD_RENDERER_H

#include "../Goban.h"

struct Renderer { virtual void render(const Goban& goban) const = 0; };

#endif