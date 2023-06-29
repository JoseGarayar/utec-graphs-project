#ifndef BFS_H
#define BFS_H

#include <queue>
#include <unordered_set>

template<typename TV, typename TE>
void BFS(Graph<TV, TE>& graph, string startVertexId) {
    if (graph.empty()) {
        cout << "Grafo vacio" << endl;
        return;
    }

    Vertex<TV, TE>* start = graph.getVertex(startVertexId);
    if (start == nullptr) {
        cout << "Vertice de inicio no encontrado" << endl; 
        return;
    }

    queue<Vertex<TV, TE>*> vertexQueue;
    unordered_set<Vertex<TV, TE>*> visitedVertices;
    visitedVertices.insert(start);
    vertexQueue.push(start);


    while (!vertexQueue.empty()) {
       
        Vertex<TV, TE>* currentVertex = vertexQueue.front();
        cout << "Vertice Visitado " << currentVertex->data << endl;
        vertexQueue.pop();
      
        for (Edge<TV, TE>* edge : currentVertex->edges) {
            Vertex<TV, TE>* adjacentVertex = edge->vertexes[0] == currentVertex ? edge->vertexes[1] : edge->vertexes[0];

            if (visitedVertices.find(adjacentVertex) == visitedVertices.end()) {
                visitedVertices.insert(adjacentVertex);
                vertexQueue.push(adjacentVertex);
            }
        }
    }
}

#endif
