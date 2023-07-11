// Archivo de tests
// Imagenes de los grafos de prueba en el archivo README.md

#include "Graph/graph.h"
#include "Graph/Algorithms/astar.h"
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/Dijkstra.h"
#include "Graph/Algorithms/dfs.h"


using namespace std;

void test_graph_methods() {
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
    cout << "Density: " << graph.density() << endl;
    cout << "Is dense: " << graph.isDense() << endl;
    // // Operator
    cout << "Operator: " << graph("2792","2796") << endl;
    // // Find by ID
    cout << "Find by ID: " << graph.findById("2792") << endl;
    // // delete edge
    cout << "Deleting edge" << endl;
    graph.deleteEdge("2792", "2796");
    graph.displayVertex("2792");
    graph.displayVertex("2796");
    graph.display();
    // delete vertex
    cout << "Deleting vertex" << endl;
    graph.deleteVertex("2792");
    graph.displayVertex("2792");
    graph.displayVertex("2796");
    graph.display();
    // clear graph
    cout << "Clearing graph" << endl;
    graph.clear();
    graph.display();
}

void test_kruskal() {
    
    Graph<string,float> graph_kruskal;
    graph_kruskal.insertVertex("A", "A");
    graph_kruskal.insertVertex("B", "B");
    graph_kruskal.insertVertex("C", "C");
    graph_kruskal.insertVertex("D", "D");
    graph_kruskal.insertVertex("E", "E");
    graph_kruskal.insertVertex("F", "F");
    graph_kruskal.insertVertex("G", "G");
    graph_kruskal.insertVertex("H", "H");
    graph_kruskal.insertVertex("I", "I");
    graph_kruskal.createEdge("A", "B", 2);
    graph_kruskal.createEdge("A", "G", 3);
    graph_kruskal.createEdge("A", "F", 7);
    graph_kruskal.createEdge("B", "C", 4);
    graph_kruskal.createEdge("B", "G", 6);
    graph_kruskal.createEdge("G", "I", 1);
    graph_kruskal.createEdge("G", "H", 3);
    graph_kruskal.createEdge("F", "I", 5);
    graph_kruskal.createEdge("I", "H", 4);
    graph_kruskal.createEdge("H", "C", 2);
    graph_kruskal.createEdge("F", "E", 6);
    graph_kruskal.createEdge("I", "E", 2);
    graph_kruskal.createEdge("H", "D", 8);
    graph_kruskal.createEdge("C", "D", 2);
    graph_kruskal.createEdge("E", "D", 1);
    vector<Edge<string, float>*> result = exec_kruskal(graph_kruskal);

    cout << "Aristas del MST:" << endl;
    for (auto edge : result) {
        cout << edge->vertexes[0]->data << " - " << edge->vertexes[1]->data << ", peso: " << edge->weight << endl;
    }
}

void test_dijkstra() {
    Graph<string,float> graph_dijkstra;
    graph_dijkstra.insertVertex("A", "A");
    graph_dijkstra.insertVertex("B", "B");
    graph_dijkstra.insertVertex("C", "C");
    graph_dijkstra.insertVertex("D", "D");
    graph_dijkstra.insertVertex("E", "E");
    graph_dijkstra.insertVertex("F", "F");
    graph_dijkstra.insertVertex("G", "G");
    graph_dijkstra.insertVertex("H", "H");
    graph_dijkstra.createEdge("A", "C", 4);
    graph_dijkstra.createEdge("A", "F", 7);
    graph_dijkstra.createEdge("C", "F", 2);
    graph_dijkstra.createEdge("C", "D", 3);
    graph_dijkstra.createEdge("C", "G", 9);
    graph_dijkstra.createEdge("F", "G", 8);
    graph_dijkstra.createEdge("D", "G", 7);
    graph_dijkstra.createEdge("D", "E", 3);
    graph_dijkstra.createEdge("G", "E", 2);
    graph_dijkstra.createEdge("G", "H", 3);
    graph_dijkstra.createEdge("E", "H", 7);
    graph_dijkstra.createEdge("E", "B", 9);
    graph_dijkstra.createEdge("H", "B", 3);
    Dijkstra<string, float> dijkstra(graph_dijkstra);
    
    
    vector<Vertex<string, float>*> result= dijkstra.shortestPath("A", "B");
    for (auto vert : result) {
        cout << "Vertice Visitado " << vert->data << endl;
    }
    std::cout << std::endl;

}

// void test_astar() {
//     Graph<string,float> graph_astar;
//     graph_astar.insertVertex("A", "A");
//     graph_astar.insertVertex("B", "B");
//     graph_astar.insertVertex("C", "C");
//     graph_astar.insertVertex("D", "D");
//     graph_astar.insertVertex("E", "E");
//     graph_astar.insertVertex("F", "F");
//     graph_astar.insertVertex("G", "G");
//     graph_astar.insertVertex("H", "H");
//     graph_astar.insertVertex("I", "I");
//     graph_astar.createEdge("A", "B", 22);
//     graph_astar.createEdge("A", "C", 9);
//     graph_astar.createEdge("A", "D", 12);
//     graph_astar.createEdge("B", "C", 35);
//     graph_astar.createEdge("B", "H", 34);
//     graph_astar.createEdge("B", "F", 36);
//     graph_astar.createEdge("C", "D", 4);
//     graph_astar.createEdge("C", "E", 65);
//     graph_astar.createEdge("C", "F", 42);
//     graph_astar.createEdge("D", "E", 33);
//     graph_astar.createEdge("D", "I", 30);
//     graph_astar.createEdge("E", "F", 18);
//     graph_astar.createEdge("E", "G", 23);
//     graph_astar.createEdge("F", "G", 39);
//     graph_astar.createEdge("F", "H", 24);
//     graph_astar.createEdge("G", "H", 25);
//     graph_astar.createEdge("G", "I", 21);
//     graph_astar.createEdge("H", "I", 19);
//     string startId = "A";
//     string endId = "I";
//     vector<Vertex<string, float>*> pathVertices = exec_astar(graph_astar, startId, endId);
//     std::cout << "Camino corto usando A* de " << startId << " a " << endId << ": " << std::endl;
//     for (int i = 0; i < pathVertices.size(); ++i) {
//         std::cout << pathVertices[i]->data;
//         if (i != pathVertices.size() - 1) {
//             std::cout << " -> ";
//         }
//     }
//     std::cout << std::endl;
//     std::cout << std::endl;
// }

void test_bfs() {
    Graph<string,float> graph_bfs;
    graph_bfs.insertVertex("A", "A");
    graph_bfs.insertVertex("B", "B");
    graph_bfs.insertVertex("C", "C");
    graph_bfs.insertVertex("D", "D");
    graph_bfs.insertVertex("E", "E");
    graph_bfs.insertVertex("F", "F");
    graph_bfs.insertVertex("G", "G");
    graph_bfs.insertVertex("H", "H");
    graph_bfs.insertVertex("I", "I");
    graph_bfs.createEdge("A", "B", 0);
    graph_bfs.createEdge("A", "C", 0);
    graph_bfs.createEdge("A", "E", 0);
    graph_bfs.createEdge("B", "C", 0);
    graph_bfs.createEdge("B", "D", 0);
    graph_bfs.createEdge("C", "D", 0);
    graph_bfs.createEdge("C", "E", 0);
    graph_bfs.createEdge("C", "F", 0);
    graph_bfs.createEdge("E", "H", 0);
    graph_bfs.createEdge("E", "G", 0);
    graph_bfs.createEdge("H", "I", 0);
    graph_bfs.createEdge("G", "I", 0);
    string startId = "A";
    cout << "BFS busqueda desde A:" << endl;
    vector<Vertex<string, float>*> result= BFS(graph_bfs, startId);
    for (auto vert : result) {
        cout << "Vertice Visitado " << vert->data << endl;
    }
    cout << endl;
}

void test_dfs() {
    Graph<string,float> graph_dfs;
    graph_dfs.insertVertex("A", "A");
    graph_dfs.insertVertex("B", "B");
    graph_dfs.insertVertex("C", "C");
    graph_dfs.insertVertex("D", "D");
    graph_dfs.insertVertex("E", "E");
    graph_dfs.insertVertex("F", "F");
    
    graph_dfs.createEdge("A", "B", 0);
    graph_dfs.createEdge("A", "C", 0);
    graph_dfs.createEdge("A", "F", 0);
    graph_dfs.createEdge("B", "D", 0);
    graph_dfs.createEdge("B", "C", 0);
    graph_dfs.createEdge("B", "F", 0);
    graph_dfs.createEdge("C", "E", 0);
    graph_dfs.createEdge("C", "D", 0);
    graph_dfs.createEdge("D", "F", 0);
    graph_dfs.createEdge("E", "F", 0);

    
    vector<Vertex<string, float>*> result = DFS(graph_dfs,"F");

    
    cout << "BFS busqueda desde F" << endl;
    for (auto vert : result) {
        cout << "Vertice Visitado " << vert->data << endl;
    }

    cout << endl;
    
}
