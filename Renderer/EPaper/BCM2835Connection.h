#ifndef DIGITAL_GO_BOARD_BCM2835CONNECTION_H
#define DIGITAL_GO_BOARD_BCM2835CONNECTION_H

extern "C" {
#include "../../libs/IT8951/Config/DEV_Config.h"
}

class BCM2835Connection {
private:
    bool isConnected { false };
public:
    BCM2835Connection();
    ~BCM2835Connection();
    void connect();
    void disconnect();
};


#endif
