#include "Graph/graph.h"
#include <iostream>
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/bfs.h"
#include "Graph/Algorithms/astar.h"
#include "Graph/Algorithms/Dijkstra.h"
#include "Graph/graph_factory.h"
#include "tester.h"

using namespace std;

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

    return 0;
}
