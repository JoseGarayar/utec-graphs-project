// Archivo de tests
// Imagenes de los grafos de prueba en el archivo README.md

#include "Graph/graph.h"
#include "Graph/Algorithms/astar.h"
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/Dijkstra.h"
#include "Graph/Algorithms/dfs.h"


using namespace std;

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
    // graph_dijkstra.insertVertex("I", "I");
    // graph_dijkstra.createEdge("A", "B", 2);
    Dijkstra<string, float> dijkstra(graph_dijkstra);
    // dijkstra.shortestPath("2792", "2796");
}

void test_astar() {
    // Graph<string,float> graph_astar;
    // graph_astar.insertVertex("I", "I");
    // graph_astar.createEdge("A", "B", 2);
    // string startId = "2792";
    // string endId = "2796";
    // vector<Vertex<string, float>*> pathVertices = exec_astar(graph_astar, startId, endId);
    // std::cout << "Camino corto de " << startId << " a " << endId << ": " << std::endl;
    // for (int i = pathVertices.size() - 1; i >= 0; --i) {
    //     std::cout << pathVertices[i]->data;
    //     if (i != 0) {
    //         std::cout << " -> ";
    //     }
    // }
    // std::cout << std::endl;
}

void test_bfs() {
    Graph<string,float> graph_bfs;
    // graph_bfs.insertVertex("I", "I");
    // graph_bfs.createEdge("A", "B", 2);
    string startId = "2792";
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
