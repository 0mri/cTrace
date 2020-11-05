#include <iostream>
// #include "Session.h"
#include <fstream>
#include <json.hpp>
using json = nlohmann::json;

using namespace std;

int main(int argc, char **argv)
{
    // if (argc != 2)
    // {
    //     cout << "usage cTrace <config_path>" << endl;
    //     return 0;
    // }
    std::ifstream i("config1.json");
    json j;
    i >> j;
    cout << j["students"]["omer"] << endl;
    // Session sess(argv[1]);
    return 0;
};