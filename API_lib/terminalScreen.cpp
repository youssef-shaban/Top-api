//
// Created by youss on 5/17/2022.
//

#include "terminalScreen.h"

void terminalScreen::readScreen() {
    cout<<"you are now in reading screen"<<endl;
    cout<<"please insert the absolute path of json file"<<endl;
    string path;
    cin>>path;
    if(api.ReadJson(path)){
        cout<<"file read successfully"<<endl;
    }else{
        cout<<"some thing wrong happend!"<<endl;
        cout<<"if you want to try again please enter (yes)"<<endl;
        string res;
        cin >>res;
        if(res=="yes") readScreen();
        else mainScreen();
    }
    mainScreen();

}

void terminalScreen::writeScreen() {
    cout<<"you are now in creating json file screen"<<endl;
    cout<<"please enter topology id that you want to save"<<endl;
    string top;
    cin>>top;
    cout<<"please enter the absolute path that you want to save on"<<endl;
    string path;
    cin>>path;
    if(api.writeJSON(top,path)){
        cout<<"file saved successfully"<<endl;
    }else{
        cout<<"something wrong happend while saving"<<endl;
        cout<<"if you want to try again please enter (yes)"<<endl;
        string res;
        cin >>res;
        if(res=="yes") writeScreen();
        else mainScreen();
    }
    mainScreen();
}

void terminalScreen::topScreen() {
    cout<<"you are now in topology screen"<<endl;
    vector<Topology> vec = api.queryTopologies();
    for(auto top:vec){
        cout<<top.get_id()<<endl;
        for(auto comp: top.get_comp_list()){
            cout<<"  "<<comp.get_id()<<endl;
        }

    }
    system("PAUSE");
    mainScreen();

}

void terminalScreen::deleteScreen() {
    cout<<"you are now in deleting screen"<<endl;
    cout<<"please enter topology id you want to delete"<<endl;
    string top;
    cin>>top;
    if(api.deleteTopology(top)){
        cout<<"Deleting done successfully"<<endl;
    }else{
        cout<<"Something wrong happened"<<endl;
        cout<<"if you want to try again please enter (yes)"<<endl;
        string res;
        cin >>res;
        if(res=="yes") deleteScreen();
        else mainScreen();

    }

}

void terminalScreen::deviceScreen() {
    cout<<"you are now in components screen"<<endl;
    cout<<"please enter topology id "<<endl;
    string top;
    cin>>top;
    vector<Component>comps=  api.queryDevices(top);
    for(auto comp:comps){
        cout<<comp.get_id()<<endl;
        if(comp.get_id()=="resistor"){
            cout<<"  t1:"<<comp.get_netList()["t1"]<<endl;
            cout<<"  t2:"<<comp.get_netList()["t2"]<<endl;
        }else if(comp.get_id()=="nmos"||comp.get_id()=="cmos"){
            cout<<"  drain:"<<comp.get_netList()["drain"]<<endl;
            cout<<"  gate:"<<comp.get_netList()["gate"]<<endl;
            cout<<"  source:"<<comp.get_netList()["source"]<<endl;
        }
    }
    system("PAUSE");
    mainScreen();
}

void terminalScreen::netlistScreen() {
    cout<<"you are now in netlist screen"<<endl;
    cout<<"please enter topology id "<<endl;
    string top;
    cin>>top;
    cout<<"please enter netlist id "<<endl;
    string node;
    cin>>node;
    vector<Component> comps= api.queryDevicesWithNetlistNode(top,node);
    for(auto comp:comps){
        cout<<comp.get_id()<<endl;
    }
    system("PAUSE");
    mainScreen();

}

void terminalScreen::mainScreen() {
    cout<<"welcome to topolgy API"<<endl;
    cout<<"please choose one of the following number to continue"<<endl;
    cout<<"1- read topology as json file"<<endl;
    cout<<"2- write a topology in json file"<<endl;
    cout<<"3- get all topologies in the memory"<<endl;
    cout<<"4- deleting a topology"<<endl;
    cout<<"5- showing all components in a topology"<<endl;
    cout<<"6- showing all components connected to a netlist"<<endl;
    cout<<"0- exit the program"<<endl;
    int num;
    cin>>num;
    if(num==1) readScreen();
    else if(num==2) writeScreen();
    else if(num==3) topScreen();
    else if(num==4) deleteScreen();
    else if(num==5) deviceScreen();
    else if(num==6) netlistScreen();
    else if(num==0) return ;
    else {
        cout<<"sorry you entered a wrong input, please try again"<<endl;
        mainScreen();
    }

}


