#ifndef DFS_H
#define DFS_H

#include <stack>
#include <unordered_set>
#include "../graph.h"

template<typename TV, typename TE>
std::vector<Vertex<TV, TE>*>  DFS(Graph<TV, TE>& graph, string startVertexId) {

    std::vector<Vertex<TV, TE>*> result;

    if (graph.empty()) {
        throw out_of_range("Graph is empty");        
    }

    Vertex<TV, TE>* start = graph.getVertex(startVertexId);
    if (start == nullptr) {        
        throw out_of_range("Start vertex doesn't found");
        
    }

    stack<Vertex<TV, TE>*> vertexStack;
    vertexStack.push(start);

    unordered_set<Vertex<TV, TE>*> visitedVertices;
    visitedVertices.insert(start);


    while (!vertexStack.empty()){

        Vertex<TV, TE>* verticeActual = vertexStack.top();
        vertexStack.pop();

        result.push_back(verticeActual);

        //cout << "Vertice Visitado " << verticeActual->data << endl;

        for (Edge<TV, TE>* edge : verticeActual->edges) {
            Vertex<TV, TE>* adjacentVertex = edge->vertexes[0] == verticeActual ? edge->vertexes[1] : edge->vertexes[0];
            
            if (visitedVertices.find(adjacentVertex) == visitedVertices.end()) {
                visitedVertices.insert(adjacentVertex);
                vertexStack.push(adjacentVertex);                
            }

        }

    }
    return result;
    
};

#endif
