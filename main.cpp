#include "Graph/graph.h"
#include <iostream>
#include <fstream>
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/bfs.h"
#include "Graph/Algorithms/astar.h"
#include "Graph/Algorithms/Dijkstra.h"
#include "Graph/graph_factory.h"
#include "Parser/nlohmann/json.hpp"
#include "Graph/Models/airport.h"
#include "Graph/Algorithms/dfs.h"

using json = nlohmann::json;
#include "tester.h"

using namespace std;

void from_json(const json& j, Airport& a) {
    j.at("Airport ID").get_to(a.id);
    j.at("City").get_to(a.city);
    j.at("Country").get_to(a.country);
    j.at("Latitude").get_to(a.latitude);
    j.at("Longitude").get_to(a.longitude);
    j.at("Name").get_to(a.name);
}

void readFromJSON() {
    ifstream f("Parser/Data/pe.json");
    json data = json::parse(f);
    std::cout << data.dump(2) << std::endl;
    vector<Airport> airports;
    for (json::iterator it = data.begin(); it != data.end(); ++it) {
        Airport airport;
        from_json(*it, airport);
        airports.push_back(airport);
    }
    std::cout << "Vector size: " << airports.size() << std::endl;
    std::cout << "First Airport" << std::endl;
    std::cout << "Airport ID: " << airports[0].id << std::endl;
    std::cout << "City: " << airports[0].city << std::endl;
    std::cout << "Country: " << airports[0].country << std::endl;
    std::cout << "Latitude: " << airports[0].latitude << std::endl;
    std::cout << "Longitude: " << airports[0].longitude << std::endl;
    std::cout << "Name: " << airports[0].name << std::endl;
}

int main() {
    GraphFactory factory;
    Graph<Airport, float> graph = factory.makeGraph();

    // A*
    // string startId = "6067";
    // string endId = "6066";
    // vector<Vertex<Airport, float>*> pathVertices = exec_astar(graph, startId, endId);
    // std::cout << "Camino corto usando A* de " << startId << " a " << endId << ": " << std::endl;
    // for (int i = 0; i < pathVertices.size(); ++i) {
    //     std::cout << pathVertices[i]->data.city;
    //     if (i != pathVertices.size() - 1) {
    //         std::cout << " -> ";
    //     }
    // }
    // std::cout << std::endl;
    // Kruskal
    // vector<Edge<Airport, float>*> result = exec_kruskal(graph);
    // cout << "Aristas del MST:" << endl;
    // for (auto edge : result) {
    //     cout << edge->vertexes[0]->data.city << " - " << edge->vertexes[1]->data.city << ", peso: " << edge->weight << endl;
    // }

    Dijkstra<Airport, float> dijkstra(graph);
    string startIdD = "6067";
    string endIdD = "6066";
    std::cout << "Dijkstra: From: 6067 To: 6066 " << std::endl;
    vector<Vertex<Airport, float>*> result= dijkstra.shortestPath(startIdD, endIdD);
    for (auto vert : result) {
        cout << "Aeropuerto :" << vert->data.city << endl;
    }
    std::cout << std::endl;


    string startIdBSF = "6067";
    cout << "BFS busqueda desde 6067:" << endl;
    vector<Vertex<Airport, float>*> resultBSF= BFS(graph, startIdBSF);
    for (auto vert : resultBSF) {
        cout << "Aeropuerto :" << vert->data.city << endl;
    }
    cout << endl;

    string startIdDSF = "6067";
    cout << "DFS busqueda desde 6067:" << endl;
    vector<Vertex<Airport, float>*> resultDFS = DFS(graph,startIdDSF);
    cout << "BFS busqueda desde F" << endl;
    for (auto vert : resultDFS) {
        cout << "Aeropuerto :" << vert->data.city << endl;
    }

    cout << endl;

    // Test graph methods
    // test_graph_methods();

    // Test A*
    // test_astar();
    // Test BFS
    // test_bfs();
    // Test Dijkstra
    // test_dijkstra();
    // Test Kruskal
    // test_kruskal();

    //test_dfs();

    return 0;
}
