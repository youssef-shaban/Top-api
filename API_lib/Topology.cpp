//
// Created by youss on 5/15/2022.
//

#include "Topology.h"

Topology::Topology() {

}

Topology::Topology(string id, vector<Component> comps) {
    this->id=id;
    this->Components=comps;

}

void Topology::set_id(string id) {
    this->id=id;

}

void Topology::set_comp_list(vector<Component> comps) {
    this->Components=comps;

}

string Topology::get_id() {
    return this->id;
}

vector<Component> Topology::get_comp_list() {
    return this->Components;
}

bool Topology::operator==(string top2) {
    if(this->id==top2){
        return true;
    }else{
        return false;
    }
}
