//
// Created by youss on 5/15/2022.
//

#include "API.h"
using json = nlohmann::json;

API::API() {}

bool API::ReadJson(string FileName) {
   try {
        std::ifstream file(FileName);
        json data = json::parse(file);
        Topology top;
        top.set_id(data["id"]);
        vector<Component> comps;
        for (int i = 0; i < data["components"].size(); i++) {
            Component comp;
            comp.set_id(data["components"][i]["id"]);
            comp.set_type(data["components"][i]["type"]);
            if (comp.get_type() == "resistor") {
                Resistance *r = new Resistance();
                r->set_name("resistance");
                json res = data["components"][i]["resistance"];
                r->set_Default(res["default"]);
                r->set_Min(res["min"]);
                r->set_Max(res["max"]);
                json net = data["components"][i]["netlist"];
                //cout << net;
                comp.set_device(r);
                comp.set_netlist(net);
                comps.push_back(comp);
            } else if (comp.get_type() == "nmos" || comp.get_type() == "pmos") {
                Transistor *t = new Transistor();;
                t->set_name("m(l)");
                json res = data["components"][i]["m(l)"];
                t->set_Default(res["default"]);
                t->set_Min(res["min"]);
                t->set_Max(res["max"]);
                json net = data["components"][i]["netlist"];
                comp.set_device(t);
                comp.set_netlist(net);
                comps.push_back(comp);
            }
        }
        top.set_comp_list(comps);
        TopologyList.push_back(top);
        return true;
    }
   catch(...) {
       return false;
   }

}

bool API::writeJSON(string TopologyID,string fileName) {
    json outJson;
    ofstream output(fileName);
    Topology top;
    int index=find(TopologyList.begin(), TopologyList.end(), TopologyID)-TopologyList.begin();
    if(index+TopologyList.begin()!=TopologyList.end()){
        top=TopologyList[index];
        outJson["id"]=top.get_id();
        vector<json> comps;
        for(int i=0;i<top.get_comp_list().size();i++){
            json comp;
            comp["id"]=top.get_comp_list()[i].get_id();
            comp["type"]=top.get_comp_list()[i].get_type();
            auto netlist= top.get_comp_list()[i].get_netList();
            if(comp["type"]=="resistor"){
                comp["resistance"]={
                        {"default", top.get_comp_list()[i].get_device()->get_Default()},
                        {"min", top.get_comp_list()[i].get_device()->get_min()},
                        {"max", top.get_comp_list()[i].get_device()->get_max()}

                };
                comp["netlist"]={
                        {"t1",netlist["t1"]},
                        {"t2",netlist["t2"]}
                };
            }else if(comp["type"]=="nmos"||comp["type"]=="pmos"){
                comp["m(l)"]={
                        {"default", top.get_comp_list()[i].get_device()->get_Default()},
                        {"min", top.get_comp_list()[i].get_device()->get_min()},
                        {"max", top.get_comp_list()[i].get_device()->get_max()}
                };
                comp["netlist"]={
                        {"drain",netlist["drain"]},
                        {"gate",netlist["gate"]},
                        {"source",netlist["source"]}
                };
            }

            comps.push_back(comp);
        }
        outJson["components"]=comps;
        output<<outJson;
        return true;
    }
    else{
        return false;
    }

}

vector<Topology> API::queryTopologies() {
    return TopologyList;
}

bool API::deleteTopology(string TopologyID) {
    auto index=find(TopologyList.begin(), TopologyList.end(), TopologyID);
    if(index!=TopologyList.end()){
        TopologyList.erase(index);
        return true;
    }
    return false;
}

vector<Component > API::queryDevices(string TopologyID) {
    vector<Device*> devices;
    Topology top;
    auto index=find(TopologyList.begin(), TopologyList.end(), TopologyID);
    if(index!=TopologyList.end()){
        top=TopologyList[index-TopologyList.begin()];

    }
    return top.get_comp_list();

}

vector<Component> API::queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID) {
    vector<Component> devices;
    Topology top;
    auto index=find(TopologyList.begin(), TopologyList.end(), TopologyID);
    if(index!=TopologyList.end()){
        top=TopologyList[index-TopologyList.begin()];

    }
    vector<Component>comps= top.get_comp_list();
    for(auto comp:comps){
        auto netlist=comp.get_netList();
        bool connected=false;
        for (auto it = netlist.begin(); it != netlist.end(); it++)
        {
            if(it->second==NetlistNodeID){
                connected=true;

            }
        }
        if(connected)
            devices.push_back(comp);

    }
    return devices;
}

