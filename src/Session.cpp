#include <iostream>
#include "Session.h"
#include <json.hpp>
#include <fstream>
#include <vector>

using namespace std;
using json = nlohmann::json;


Session::Session(const string& path){
    cout << "im here" << endl;
    std::ifstream i(path);
    json j;
    i >> j;

    json output;

    // vector<vector<int>> vect{
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}};

    // Graph g = new Graph(j["graph"]);
    // Graph g(j["graph"]);
    // g.print();

    output["graph"] = j["graph"];
    // cout << j["students"]["omer"] << endl;
    // Session sess(argv[1]);

    ofstream r("output.json");
    output >> r;
}