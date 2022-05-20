//
// Created by youss on 5/15/2022.
//

#ifndef TOPAPI_API_H
#define TOPAPI_API_H
#include <vector>
#include "Topology.h"
#include <string>
#include "Device.h"
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Topology.h"
#include "Component.h"
#include <vector>
#include "Resistance.h"
#include "Transistor.h"
class API {

public:
    vector<Topology> TopologyList;
    API();
    bool ReadJson(string FileName);
    bool writeJSON(string TopologyID, string fileName);
    vector<Topology> queryTopologies();
    bool deleteTopology(string TopologyID);
    vector<Component> queryDevices(string TopologyID);
    vector<Component> queryDevicesWithNetlistNode(string TopologyID,string NetlistNodeID);
};


#endif //TOPAPI_API_H
