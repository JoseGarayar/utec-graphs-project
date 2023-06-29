#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../graph.h"
#include <queue>
#include <limits>

template<typename TV, typename TE>
struct PathNode {
    Vertex<TV, TE>* vertex;
    PathNode<TV, TE>* previous;
    TE weight;

    PathNode(Vertex<TV, TE>* v, PathNode<TV, TE>* prev, TE w)
        : vertex(v), previous(prev), weight(w) {}
};

template<typename TV, typename TE>
class Dijkstra {
private:
    Graph<TV, TE>& graph;
    std::unordered_map<Vertex<TV, TE>*, TE> distance;
    std::unordered_map<Vertex<TV, TE>*, PathNode<TV, TE>*> path;
    std::priority_queue<std::pair<TE, Vertex<TV, TE>*>, std::vector<std::pair<TE, Vertex<TV, TE>*> >, std::greater<std::pair<TE, Vertex<TV, TE>*> > > pq;

public:
    Dijkstra(Graph<TV, TE>& g) : graph(g) {}

    void shortestPath(string startId, string endId) {
        Vertex<TV, TE>* startVertex = graph.getVertex(startId);
        Vertex<TV, TE>* endVertex = graph.getVertex(endId);

        if (!startVertex || !endVertex) {
            std::cout << "Vertice invalido" << std::endl;
            return;
        }

        for (auto& pair : graph.getVertices()) {
            distance[pair] = std::numeric_limits<TE>::max();
        }

        distance[startVertex] = 0;

        pq.push(std::make_pair(distance[startVertex], startVertex));

        while (!pq.empty()) {
            Vertex<TV, TE>* currentVertex = pq.top().second;
            pq.pop();

            if (currentVertex == endVertex) {
                break;
            }

            for (auto& edge : currentVertex->edges) {
                Vertex<TV, TE>* neighbor = (edge->vertexes[0] != currentVertex) ? edge->vertexes[0] : edge->vertexes[1];
                TE edgeWeight = edge->weight;

                TE currentDistance = distance[currentVertex] + edgeWeight;

                if (currentDistance < distance[neighbor]) {
                    distance[neighbor] = currentDistance;
                    path[neighbor] = new PathNode<TV, TE>(neighbor, path[currentVertex], edgeWeight);
                    pq.push(std::make_pair(distance[neighbor], neighbor));
                }
            }
        }

        if (distance[endVertex] == std::numeric_limits<TE>::max()) {
            std::cout << "No se encontro camino de " << startId << " a " << endId << std::endl;
        } else {
            std::cout << "Camino corto de " << startId << " a " << endId << ": " << std::endl;
            printPath(startVertex, endVertex);
        }
    }

private:
void printPath(Vertex<TV, TE>* startVertex, Vertex<TV, TE>* endVertex) {
    std::vector<Vertex<TV, TE>*> pathVertices;
    PathNode<TV, TE>* current = path[endVertex];

    while (current) {
        pathVertices.push_back(current->vertex);
        current = current->previous;
    }

    pathVertices.push_back(startVertex);

    for (int i = pathVertices.size() - 1; i >= 0; --i) {
        std::cout << pathVertices[i]->data;
        if (i != 0) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    for (auto& pair : path) {
        delete pair.second;
    }
}
};

#endif
