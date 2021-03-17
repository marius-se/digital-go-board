#ifndef DIGITAL_GO_BOARD_TERMINALRENDERER_H
#define DIGITAL_GO_BOARD_TERMINALRENDERER_H

#include "Renderer.h"
#include "../Goban.h"

struct TerminalRenderer : Renderer {
    void render(const Goban& goban) const override {
        const auto currentGobanState = goban.getCurrentState();
        std::cout << "###########" << std::endl;
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                switch (currentGobanState[i][j]) {
                    case none:
                        std::cout << '0';
                        break;
                    case black:
                        std::cout << 'b';
                        break;
                    case white:
                        std::cout << 'w';
                        break;
                }
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "###########" << std::endl;
    }
};

#endif
