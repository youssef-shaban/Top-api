//
// Created by youss on 5/17/2022.
//

#ifndef TOPAPI_TERMINALSCREEN_H
#define TOPAPI_TERMINALSCREEN_H
#include "API.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class terminalScreen {
private:
    API api;

public:
    void readScreen();
    void writeScreen();
    void topScreen();
    void deleteScreen();
    void deviceScreen();
    void netlistScreen();
    void mainScreen();
};


#endif //TOPAPI_TERMINALSCREEN_H
