#include <iostream>
// #include "Session.h"
#include <json.hpp>
using json = nlohmann::json;

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    // std::ifstream i("config.json");
    // json j;
    // i >> j;
    // Session sess(argv[1]);
    return 0;
};