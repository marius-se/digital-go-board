#ifndef DIGITAL_GO_BOARD_GOBAN_H
#define DIGITAL_GO_BOARD_GOBAN_H


#include <array>
#include "Coordinate.h"

enum Stone { none, black, white };

class Goban {
private:
    std::array<std::array<Stone, 19>, 19> state;
public:
    Goban();
    void setStone(const Coordinate targetCoordinate, const Stone stone);
    Stone getStone(const Coordinate coordinate);
    decltype(auto) getCurrentState() const  {
        return state;
    }
};


#endif
