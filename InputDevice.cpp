//
// Created by Onur on 17.03.2021.
//

#include <iostream>
#include "InputDevice.h"

InputDevice::InputDevice() {

}

void InputDevice::waitForInput(Coordinate& c) {

}

void Keyboard::waitForInput(Coordinate& c) {
    do {
        std::cin >> c;
        if(!c.isValid()) {
            std::cout << "Invalid Coordinates, please try again" << std::endl;
        }
    } while (!c.isValid());
}
