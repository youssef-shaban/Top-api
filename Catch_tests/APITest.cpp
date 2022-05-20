//
// Created by youss on 5/17/2022.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "API.h"

TEST_CASE("ReadingJson","[APITest]"){
    API api;
    api.ReadJson(R"(C:\Users\youss\CLionProjects\TopAPI\topology.json)");
    CHECK(api.TopologyList[0].get_id()=="top1");
    CHECK(api.TopologyList[0].get_comp_list()[0].get_id()=="res1");
    CHECK(api.TopologyList[0].get_comp_list()[1].get_id()=="m1");
    CHECK(api.TopologyList[0].get_comp_list()[1].get_netList()["source"]=="vss");

}

TEST_CASE("WritingJson","[APITest]"){
    API api;
    api.ReadJson(R"(C:\Users\youss\CLionProjects\TopAPI\topology.json)");
    CHECK(api.writeJSON("top1","C:\\Users\\youss\\CLionProjects\\TopAPI\\topology1.json")==true);
}

TEST_CASE("GettingTopology","[APITest]"){
    API api;
    api.ReadJson(R"(C:\Users\youss\CLionProjects\TopAPI\topology.json)");
    vector<Topology> top= api.queryTopologies();
    CHECK(top[0].get_id()=="top1");
    CHECK(top[0].get_comp_list()[0].get_id()=="res1");
    CHECK(top[0].get_comp_list()[1].get_id()=="m1");
    CHECK(top[0].get_comp_list()[1].get_netList()["source"]=="vss");
}

TEST_CASE("GettingComps","[APITest]"){
    API api;
    api.ReadJson(R"(C:\Users\youss\CLionProjects\TopAPI\topology.json)");
    vector<Component> comps = api.queryDevices("top1");
    CHECK(comps[0].get_id()=="res1");
    CHECK(comps[1].get_id()=="m1");
    CHECK(comps[1].get_netList()["source"]=="vss");
}

TEST_CASE("GettingnetlistConnected","[APITest]"){
    API api;
    api.ReadJson(R"(C:\Users\youss\CLionProjects\TopAPI\topology.json)");
    vector<Component> comps = api.queryDevicesWithNetlistNode("top1","n1");
    CHECK(comps[0].get_id()=="res1");
    CHECK(comps[1].get_id()=="m1");

}