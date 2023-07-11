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
    Graph<Airport, float> gr = factory.makeGraph();

    // Test graph methods
    test_graph_methods();

    // Test A*
    test_astar();
    // Test BFS
    test_bfs();
    // Test Dijkstra
    test_dijkstra();
    // Test Kruskal
    test_kruskal();

    return 0;
}
