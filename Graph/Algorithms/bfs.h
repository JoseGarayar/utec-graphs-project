#ifndef BFS_H
#define BFS_H

#include <queue>
#include <unordered_set>

template<typename TV, typename TE>
std::vector<Vertex<TV, TE>*>  BFS(Graph<TV, TE>& graph, string startVertexId) {

    std::vector<Vertex<TV, TE>*> result;

    if (graph.empty()) {
        throw out_of_range("Graph is empty");  
    }

    Vertex<TV, TE>* start = graph.getVertex(startVertexId);
    if (start == nullptr) {
        throw out_of_range("Start vertex doesn't found");
    }

    queue<Vertex<TV, TE>*> vertexQueue;
    unordered_set<Vertex<TV, TE>*> visitedVertices;
    visitedVertices.insert(start);
    vertexQueue.push(start);


    while (!vertexQueue.empty()) {
       
        Vertex<TV, TE>* currentVertex = vertexQueue.front();

        result.push_back(currentVertex);
        //cout << "Vertice Visitado " << currentVertex->data << endl;
        vertexQueue.pop();
      
        for (Edge<TV, TE>* edge : currentVertex->edges) {
            Vertex<TV, TE>* adjacentVertex = edge->vertexes[0] == currentVertex ? edge->vertexes[1] : edge->vertexes[0];

            if (visitedVertices.find(adjacentVertex) == visitedVertices.end()) {
                visitedVertices.insert(adjacentVertex);
                vertexQueue.push(adjacentVertex);
            }
        }
    }
    return result;
}

#endif
