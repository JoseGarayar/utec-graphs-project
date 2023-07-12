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
#include "pantallagrafica.h"

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
    int menuOptionJSON;
    string path;
    cout << "Desde que archivo se cargará el JSON?" << endl;
    cout << "1. airports.json" << endl;
    cout << "2. pe.json" << endl;
    cout << "3. Salir de menu" << endl;
    cout << "Ingrese una opción: ";
    cin >> menuOptionJSON;
    if (menuOptionJSON == 1) {
        path = "Parser/Data/airports.json";
    } else if (menuOptionJSON == 2) {
        path = "Parser/Data/pe.json";
    } else {
        if (menuOptionJSON != 3) {
            cout << "Opción inválida" << endl;
        }
        cout << "Saliendo de menú" << endl;
        return 0;
    }

    cout << "Creando grafo..." << endl;

    GraphFactory factory(path);
    Graph<Airport, float> graph = factory.makeGraph();

    int menuOptionAlgorithm;
    string startId;
    string endId;

    while(true) {
        cout << "Cual algoritmo de busqueda usar?" << endl;
        cout << "1. A*" << endl;
        cout << "2. Kruskal" << endl;
        cout << "3. Dijkstra" << endl;
        cout << "4. BFS" << endl;
        cout << "5. DFS" << endl;
        cout << "6. Salir de menu" << endl;
        cout << "Ingrese una opción: ";
        cin >> menuOptionAlgorithm;
        if (menuOptionAlgorithm == 1) {
            // A*
            cout << "Ingrese el ID de inicio: ";
            cin >> startId;
            cout << "Ingrese el ID de fin: ";
            cin >> endId;
            // startId = "6067";
            // endId = "6066";
            vector<Vertex<Airport, float>*> pathVertices = exec_astar(graph, startId, endId);
            std::cout << "Camino corto usando A* de " << startId << " a " << endId << ": " << std::endl;
            for (int i = 0; i < pathVertices.size(); ++i) {
                std::cout << pathVertices[i]->data.city;
                if (i != pathVertices.size() - 1) {
                    std::cout << " -> ";
                }
            }
            if (pathVertices.size()>0)
                showRoute(pathVertices);            
            std::cout << std::endl;
            std::cout << std::endl;
        } else if (menuOptionAlgorithm == 2) {
            // Kruskal
            vector<Edge<Airport, float>*> resultKruskal = exec_kruskal(graph);
            cout << "Aristas del MST:" << endl;
            for (auto edge : resultKruskal) {
                cout << edge->vertexes[0]->data.city << " - " << edge->vertexes[1]->data.city << ", peso: " << edge->weight << endl;
            }
            std::cout << std::endl;

        } else if (menuOptionAlgorithm == 3) {
            Dijkstra<Airport, float> dijkstra(graph);
            cout << "Ingrese el ID de inicio: ";
            cin >> startId;
            cout << "Ingrese el ID de fin: ";
            cin >> endId;
            std::cout << "Dijkstra: From: 6067 To: 6066 " << std::endl;
            vector<Vertex<Airport, float>*> resultDijkstra= dijkstra.shortestPath(startId, endId);
            for (auto vert : resultDijkstra) {
                cout << "Aeropuerto: " << vert->data.city << endl;
            }
            std::cout << std::endl;
            if (resultDijkstra.size()>0)
                showRoute(resultDijkstra);
        } else if (menuOptionAlgorithm == 4) {
            cout << "Ingrese el ID de inicio: ";
            cin >> startId;
            cout << "BFS busqueda desde " << startId << ":" << endl;
            vector<Vertex<Airport, float>*> resultBSF= BFS(graph, startId);
            for (auto vert : resultBSF) {
                cout << "Aeropuerto: " << vert->data.city << endl;
            }
            cout << endl;
        } else if (menuOptionAlgorithm == 5) {
            cout << "Ingrese el ID de inicio: ";
            cin >> startId;
            cout << "DFS busqueda desde " << startId << ":" << endl;
            vector<Vertex<Airport, float>*> resultDFS = DFS(graph,startId);
            for (auto vert : resultDFS) {
                cout << "Aeropuerto: " << vert->data.city << endl;
            }

            cout << endl;
        } else {
            if (menuOptionAlgorithm != 6) {
                cout << "Opción inválida" << endl;
            }
            cout << "Saliendo de menú" << endl;
            return 0;
        }
    }

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
