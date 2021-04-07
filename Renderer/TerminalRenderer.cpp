//
// Created by Onur on 22.03.2021.
//

#include <iostream>
#include "TerminalRenderer.h"

void TerminalRenderer::render(const Goban &goban) const {
    //system("clear"); //Fuer Linux
    //system("cls"); //Fuer Windows
    //system("printf '\\33c\\e[3J'"); //Fuer MacOS
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
