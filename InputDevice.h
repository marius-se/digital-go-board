//
// Created by Onur on 17.03.2021.
//

#ifndef DIGITAL_GO_BOARD_INPUTDEVICE_H
#define DIGITAL_GO_BOARD_INPUTDEVICE_H


#include "Coordinate.h"

class InputDevice {
protected:
    Coordinate c;
public:
    InputDevice();
    virtual void waitForInput(Coordinate& c);
};

class Keyboard : public InputDevice {
public:
    void waitForInput(Coordinate& c);
};


#endif //DIGITAL_GO_BOARD_INPUTDEVICE_H
