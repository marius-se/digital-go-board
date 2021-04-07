//
// Created by Onur on 22.03.2021.
//

#include "Goban.h"

Goban::Goban()  {
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            state[i][j] = none;
        }
    }
}

void Goban::setStone(const Coordinate targetCoordinate, const Stone stone)  {
    state[targetCoordinate.y - 1][targetCoordinate.x - 1] = stone;
}

Stone Goban::getStone(const Coordinate coordinate) {
    return state[coordinate.y - 1][coordinate.x - 1];
}

/*decltype(auto) Goban::getCurrentState() const  {
    return state;
}*/
