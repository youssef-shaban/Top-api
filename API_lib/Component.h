//
// Created by youssef on 5/15/2022.
//

#ifndef TOPAPI_COMPONENT_H
#define TOPAPI_COMPONENT_H
#include <string>
#include <unordered_map>
#include "Device.h"

using namespace std;
class Component {

private:
    string type;
    string id;
    Device* device;
    unordered_map<string,string> netlist;

public:
    Component(string id, string type, Device* device, std::unordered_map<string,string> map);
    Component();
    void set_type(string type);
    void set_id(string id);
    void set_device(Device* device);
    void set_netlist(std::unordered_map<string,string> netlist);
    string get_type();
    string get_id();
    Device* get_device();
    unordered_map<string, string> get_netList();
};


#endif //TOPAPI_COMPONENT_H
