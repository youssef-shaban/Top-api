//
// Created by youssef on 5/15/2022.
//

#include "Component.h"

Component::Component(string id, string type, Device *device, std::unordered_map<string, string> map) {
    this->id=id;
    this->type=type;
    this->device=device;
    this->netlist=map;
}

Component::Component() {

}

void Component::set_type(string type) {
    this->type=type;
}

void Component::set_id(string id) {
    this->id=id;
}

void Component::set_device(Device *device) {
    this->device=device;

}

void Component::set_netlist(std::unordered_map<string, string> netlist) {
    this->netlist=netlist;

}

string Component::get_type() {
    return this->type;
}

string Component::get_id() {
    return this->id;
}

Device *Component::get_device() {
    return this->device;
}

unordered_map<string, string> Component::get_netList() {
    return this->netlist;
}


