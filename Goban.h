#ifndef DIGITAL_GO_BOARD_GOBAN_H
#define DIGITAL_GO_BOARD_GOBAN_H

#include "Coordinate.h"

enum Stone { none, black, white };

class Goban {
public:
    Goban() {
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                state[i][j] = none;
            }
        }
    }

    void setStone(const Coordinate targetCoordinate, const Stone stone) {
        state[targetCoordinate.y - 1][targetCoordinate.x - 1] = stone;
    }

    Stone getStone(const Coordinate coordinate) {
        return state[coordinate.y - 1][coordinate.x - 1];
    }

    auto getCurrentState() const {
        return state;
    }
private:
    std::array<std::array<Stone, 19>, 19> state;
};

#endif