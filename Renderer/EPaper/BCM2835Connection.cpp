#include "iostream"
#include "stdexcept"
#include "BCM2835Connection.h"

BCM2835Connection::BCM2835Connection() = default;

BCM2835Connection::~BCM2835Connection() {
    disconnect();
}

void BCM2835Connection::connect() {
    std::cout << "Establishing BCM2835 connection...\n";
    if(DEV_Module_Init()!=0) {
        throw std::runtime_error("bcm2835_init failed. Are you running as root??");
    }
    isConnected = true;
}

void BCM2835Connection::disconnect() {
    if (isConnected) {
        std::cout << "Disconnecting from BCM2835...\n";
        DEV_Module_Exit();
        isConnected = false;
    }
}