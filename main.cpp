#include "Graph/graph.h"
#include <iostream>
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/bfs.h"
#include "Graph/Algorithms/astar.h"
using namespace std;

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

    return 0;
}
