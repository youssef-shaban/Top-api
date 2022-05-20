//
// Created by youss on 5/15/2022.
//

#ifndef TOPAPI_RESISTANCE_H
#define TOPAPI_RESISTANCE_H
#include "Device.h"

class Resistance: public Device{
public:
    Resistance();
    Resistance(string name, float def, float min, float max);

};


#endif //TOPAPI_RESISTANCE_H
