#ifndef DIGITAL_GO_BOARD_COORDINATE_H
#define DIGITAL_GO_BOARD_COORDINATE_H


struct Coordinate {
public:
    unsigned x;
    unsigned y;

    bool isValid();

    friend std::istream& operator >> (std::istream& is, Coordinate& c);
};


#endif
