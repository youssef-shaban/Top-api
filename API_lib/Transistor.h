//
// Created by youss on 5/15/2022.
//

#ifndef TOPAPI_TRANSISTOR_H
#define TOPAPI_TRANSISTOR_H
#include "Device.h"

class Transistor: public Device{
public:
    Transistor();
    Transistor(string name, float def, float max, float min);
};


#endif //TOPAPI_TRANSISTOR_H
