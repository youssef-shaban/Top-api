//
// Created by youss on 5/15/2022.
//

#ifndef TOPAPI_DEVICE_H
#define TOPAPI_DEVICE_H
using namespace std;
#include <string>

class Device {
private:
    float def;
    float max;
    float min;
    string name;


public:
    Device(string name, float def, float max, float min);
    Device();
    void set_Default(float def);
    void set_Max(float max);
    void set_Min(float min);
    void set_name(string name);
    string get_name();
    float get_Default();
    float get_max();
    float get_min();
};


#endif //TOPAPI_DEVICE_H
