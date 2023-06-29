#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>
#include "graph.h"

template<typename TV, typename TE>
struct DisjointSet {
    std::unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> parent;
    std::unordered_map<Vertex<TV, TE>*, int> rank;

    void makeSet(std::vector<Vertex<TV, TE>*>& vertices) {
        for (auto vertex : vertices) {
            parent[vertex] = vertex;
            rank[vertex] = 0;
        }
    }

    Vertex<TV, TE>* findSet(Vertex<TV, TE>* vertex) {
        if (vertex != parent[vertex]) {
            parent[vertex] = findSet(parent[vertex]);
        }
        return parent[vertex];
    }

    void unionSets(Vertex<TV, TE>* vertex1, Vertex<TV, TE>* vertex2) {
        Vertex<TV, TE>* root1 = findSet(vertex1);
        Vertex<TV, TE>* root2 = findSet(vertex2);

        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root1] = root2;
            if (rank[root1] == rank[root2]) {
                rank[root2]++;
            }
        }
    }
};

template<typename TV, typename TE>
bool compareEdges(Edge<TV, TE>* edge1, Edge<TV, TE>* edge2) {
    return edge1->weight < edge2->weight;
}

template<typename TV, typename TE>
std::vector<Edge<TV, TE>*> exec_kruskal(Graph<TV, TE>& graph) {
    std::vector<Edge<TV, TE>*> result;

    
    std::vector<Vertex<TV, TE>*> vertices = graph.getVertices();

    // Crear una lista con todas las aristas del grafo
    std::vector<Edge<TV, TE>*> allEdges;
    for (auto& vertex : vertices) {
        for (auto& edge : vertex->edges) {
            allEdges.push_back(edge);
        }
    }

    std::sort(allEdges.begin(), allEdges.end(), compareEdges<TV, TE>);

    DisjointSet<TV, TE> disjointSet;
    disjointSet.makeSet(vertices);

    for (auto& edge : allEdges) {
        Vertex<TV, TE>* root1 = disjointSet.findSet(edge->vertexes[0]);
        Vertex<TV, TE>* root2 = disjointSet.findSet(edge->vertexes[1]);
      
        if (root1 != root2) {
            result.push_back(edge);
            disjointSet.unionSets(root1, root2);
        }
    }

    return result;
}

#endif
