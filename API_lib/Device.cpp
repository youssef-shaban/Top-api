//
// Created by youss on 5/15/2022.
//

#include "Device.h"

Device::Device(string name, float def, float max, float min) {
    this->def=def;
    this->name=name;
    this->max=max;
    this->min=min;
}

Device::Device() {

}

void Device::set_Default(float def) {
    this->def=def;

}

void Device::set_Max(float max) {
    this->max=max;

}

void Device::set_Min(float min) {
    this->min=min;

}

void Device::set_name(string name) {
    this->name=name;

}

string Device::get_name() {
    return this->name;
}

float Device::get_Default() {
    return this->def;
}

float Device::get_max() {
    return this->max;
}

float Device::get_min() {
    return this->min;
}
