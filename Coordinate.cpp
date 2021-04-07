//
// Created by Onur on 22.03.2021.
//

#include <iostream>
#include "Coordinate.h"

bool Coordinate::isValid()  {
    if(  ((1 <= x) && (x <= 19))  &&  ((1 <= y) && (y <= 19))  ) {
        return true;
    }
    else {
        return false;
    }
}

std::istream& operator >> (std::istream& is, Coordinate& c) {
    is >> c.x >> c.y;
    return is;
}
