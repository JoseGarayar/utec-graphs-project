#include "Graph/graph.h"
#include <iostream>
#include <fstream>
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/bfs.h"
#include "Graph/Algorithms/astar.h"
#include "Graph/Algorithms/Dijkstra.h"
#include "Parser/nlohmann/json.hpp"
#include "Graph/Models/airport.h"
using json = nlohmann::json;
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
    Graph<string,float> graph;
    // Testing graph methods
    // create vertex
    graph.insertVertex("2792", "Juliaca");
    graph.insertVertex("2796", "Tumbes");
    // create edge
    graph.createEdge("2792", "2796", 400);
    graph.displayVertex("2792");
    graph.displayVertex("2796");
    graph.display();
    // density
    // cout << "Density: " << graph.density() << endl;
    // cout << "Is dense: " << graph.isDense() << endl;
    // // Operator
    // cout << "Operator: " << graph("2792","2796") << endl;
    // // Find by ID
    // cout << "Find by ID: " << graph.findById("2792") << endl;
    // // delete edge
    // cout << "Deleting edge" << endl;
    // graph.deleteEdge("2792", "2796");
    // graph.displayVertex("2792");
    // graph.displayVertex("2796");
    // graph.display();
    // // delete vertex
    // cout << "Deleting vertex" << endl;
    // graph.deleteVertex("2792");
    // graph.displayVertex("2792");
    // graph.displayVertex("2796");
    // graph.display();
    // // clear graph
    // cout << "Clearing graph" << endl;
    // graph.clear();
    // graph.display();
    
    // Realizar la búsqueda BFS desde el vértice "A"
    cout << "BFS busqueda desde A:" << endl;
    BFS(graph, "2792");
    cout << endl;
    vector<Edge<string, float>*> result = exec_kruskal(graph);

    cout << "Aristas del MST:" << endl;
    for (auto edge : result) {
        cout << edge->vertexes[0]->data << " - " << edge->vertexes[1]->data << ", peso: " << edge->weight << endl;
    }

    // Realizar la búsqueda A*
    // vector<Vertex<string, float>*> path = exec_astar(graph, "2792", "2796");

    Dijkstra<string, float> dijkstra(graph);
    dijkstra.shortestPath("2792", "2796");

    cout << "Print Ariports from pe.json" << endl;
    readFromJSON();
    return 0;
}
