//
// Created by youss on 5/15/2022.
//

#ifndef TOPAPI_TOPOLOGY_H
#define TOPAPI_TOPOLOGY_H

#include "Component.h"
#include <string>
#include <vector>
using namespace std;

class Topology {
private:
    string id;
    vector<Component> Components;
public:
    Topology();
    Topology(string id, vector<Component> comps);
    void set_id(string id);
    void set_comp_list(vector<Component> comps);
    string get_id();
    vector<Component> get_comp_list();
    bool operator==(string top2);

};


#endif //TOPAPI_TOPOLOGY_H
