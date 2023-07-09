#include <iostream>
#include <fstream>
#include <cmath>
#include <tuple>
#include "graph.h"
#include "../Parser/nlohmann/json.hpp"
#include "Models/airport.h"
using json = nlohmann::json;
using namespace std;

class GraphFactory {
private:
    string path;
    vector<Airport> airports;
    void from_json(const json& j, Airport& a) {
        j.at("Airport ID").get_to(a.id);
        j.at("City").get_to(a.city);
        j.at("Country").get_to(a.country);
        j.at("Latitude").get_to(a.latitude);
        j.at("Longitude").get_to(a.longitude);
        j.at("Name").get_to(a.name);
        j.at("destinations").get_to(a.destinations);
    }
public:
    GraphFactory(): path("Parser/Data/airports.json") {
        airports = createAirportsFromJSON();
    }
    
    vector<Airport> createAirportsFromJSON() {
        ifstream f(path);
        json data = json::parse(f);
        vector<Airport> airports;
        for (json::iterator it = data.begin(); it != data.end(); ++it) {
            Airport airport;
            from_json(*it, airport);
            airports.push_back(airport);
        }
        return airports;
    }

    Airport getAirportById(string id) {
        for (auto airport: airports) {
            if (airport.id == id) {
                return airport;
            }
        }
    }

    bool existAirport(string id) {
        bool exist = false;
        for (auto airport: airports) {
            if (airport.id == id) {
                exist = true;
                break;
            }
        }
        return exist;
    }

    vector<tuple<string, string, float>> makeDestinationsTuple(const Airport airport) {
        vector<tuple<string, string, float>> tuples;
        for (auto destination: airport.destinations) {
            if (existAirport(destination)) {
                Airport airportDestination = getAirportById(destination);
                float weight = calculateWeight(airport, airportDestination);
                tuple<string, string, float> tuple = {airport.id, destination, weight};
                tuples.push_back(tuple);
            }
        }
        return tuples;
    }

    Graph<Airport, float> makeGraph() {
        Graph<Airport, float> graph;
        vector<tuple<string, string, float>> destinations;
        for (auto airport: airports) {
            graph.insertVertex(airport.id, airport);
            for (auto tuple: makeDestinationsTuple(airport)) {
                destinations.push_back(tuple);
            }
        }
        
        for (auto destination: destinations) {
            graph.createEdge(get<0>(destination), get<1>(destination), get<2>(destination));
        }

        return graph;
    }

    float calculateWeight(const Airport origin, const Airport destination) {
        float difLat = abs(stof(origin.latitude) - stof(destination.latitude));
        float difLon = abs(stof(origin.longitude) - stof(destination.longitude));

        float squareLat = difLat * difLat;
        float squareLon = difLon * difLon;

        float sum = squareLat + squareLon;
        
        return sqrt(sum);
    }

};
