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
    
    Graph<string,float> graph;
    // Testing graph methods
    // create vertex
    graph.insertVertex("2792", "Juliaca");
    graph.insertVertex("2796", "Tumbes");
    // create edge
    graph.createEdge("2792", "2796", 400);
    // graph.displayVertex("2792");
    // graph.displayVertex("2796");
    // graph.display();
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

    // Test A*
    test_astar();
    // Test BFS
    test_bfs();
    // Test Dijkstra
    test_dijkstra();
    // Test Kruskal
    test_kruskal();

    test_dfs();

    return 0;
}
