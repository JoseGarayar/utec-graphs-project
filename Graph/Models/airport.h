#include <iostream>
using namespace std;
#ifndef AIRPORT_H
#define AIRPORT_H

struct Airport {
    string id;
    string city;
    string country;
    string latitude;
    string longitude;
    string name;
    vector<string> destinations;
};

#endif