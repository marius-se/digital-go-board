#ifndef DIGITAL_GO_BOARD_EPAPERDISPLAY_H
#define DIGITAL_GO_BOARD_EPAPERDISPLAY_H

#include "BCM2835Connection.h"

class EPaperDisplay {
private:
    BCM2835Connection bcm2835Connection;
    double vcom;
};


#endif //DIGITAL_GO_BOARD_EPAPERDISPLAY_H
