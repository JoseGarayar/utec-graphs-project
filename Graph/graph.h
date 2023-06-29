#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////
// En este archivo se implementa un grafo no dirigido
//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
};

template<typename TV, typename TE>
class Graph{
private:    
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    
public:
    Graph() {}

    void insertVertex(string id, TV vertex) {
        Vertex<TV, TE>* new_vertex = new Vertex<TV, TE>;
        list<Edge<TV, TE>*> myList;
        new_vertex->data = vertex;
        new_vertex->edges = myList;
        vertexes.insert(make_pair(id,new_vertex));
    }

    void createEdge(string id1, string id2, TE w) {
        Edge<TV, TE>* new_edge = new Edge<TV, TE>;
        new_edge->weight = w;
        new_edge->vertexes[0] = vertexes[id1];
        new_edge->vertexes[1] = vertexes[id2];
        vertexes[id1]->edges.push_back(new_edge);
        vertexes[id2]->edges.push_back(new_edge);
    };   

    void deleteVertex(string id) {
        if (vertexes.find(id) == vertexes.end()) {
            cout << "Vertex not found" << endl;
            return;
        }
        vertexes.erase(id);
    };

    void deleteEdge(string id1, string id2) {
        if (vertexes.find(id1) == vertexes.end() || vertexes.find(id2) == vertexes.end()) {
            cout << "Vertex not found" << endl;
            return;
        }
        for (auto it = vertexes[id1]->edges.begin(); it != vertexes[id1]->edges.end(); it++) {
            if ((*it)->vertexes[0] == vertexes[id2] || (*it)->vertexes[1] == vertexes[id2]) {
                vertexes[id1]->edges.erase(it);
                break;
            }
        }
        for (auto it = vertexes[id2]->edges.begin(); it != vertexes[id2]->edges.end(); it++) {
            if ((*it)->vertexes[0] == vertexes[id1] || (*it)->vertexes[1] == vertexes[id1]) {
                vertexes[id2]->edges.erase(it);
                break;
            }
        }
    };

    TE &operator()(string id1, string id2) {
        for (auto it = vertexes[id1]->edges.begin(); it != vertexes[id1]->edges.end(); it++) {
            if ((*it)->vertexes[0] == vertexes[id2] || (*it)->vertexes[1] == vertexes[id2]) {
                return (*it)->weight;
            }
        }
        // Valor por defecto
        return vertexes[id1]->edges.front()->weight;
    };  
    
    float density() {
        if (vertexes.empty()) {
            cout << "Empty graph" << endl;
            return 0;
        }
        int num_edges = 0;
        int num_vertexes = vertexes.size();
        for (auto it = vertexes.begin(); it != vertexes.end(); it++) {
            num_edges += it->second->edges.size();
        }
        // Como estamos en un grafo no dirigido, cada arista se cuenta dos veces
        num_edges /= 2;
        // Densidad para grafo no dirigido
        return (float)num_edges / (num_vertexes * (num_vertexes - 1));
    };

    bool isDense(float threshold = 0.5) {
        return density() >= threshold;
    };
    bool isConnected() { //or StronglyConnected
        // En grafos no dirigidos, la conectividad es equivalente a que sea fuertemente conexo
        return true;
    }
    bool empty() {
        return vertexes.empty();
    };
    void clear() {
        vertexes.clear();
    };  
      
    void display() {
        if (vertexes.empty()) {
            cout << "Empty graph" << endl;
            return;
        }
        for (auto it = vertexes.begin(); it != vertexes.end(); it++) {
            cout << "Vertex: " << it->first << endl;
            cout << "Data: " << it->second->data << endl;
            cout << "Edges: " << endl;
            for (auto it2 = it->second->edges.begin(); it2 != it->second->edges.end(); it2++) {
                cout << "    Edge: " << (*it2)->vertexes[0]->data << " - " << (*it2)->vertexes[1]->data << endl;
                cout << "    Weight: " << (*it2)->weight << endl;
                cout << endl;
            }
            cout << endl;
        }
    };

    void displayVertex(string id) {
        if (vertexes.find(id) == vertexes.end()) {
            cout << "Vertex not found" << endl;
            return;
        }
        cout << "Vertex: " << id << endl;
        cout << "Data: " << vertexes[id]->data << endl;
        cout << "Edges: " << endl;
        for (auto it = vertexes[id]->edges.begin(); it != vertexes[id]->edges.end(); it++) {
            cout << "    Edge: " << (*it)->vertexes[0]->data << " - " << (*it)->vertexes[1]->data << endl;
            cout << "    Weight: " << (*it)->weight << endl;
            cout << endl;
        }
        cout << endl;
    };
    Vertex<TV, TE>* getVertex(string id) {
    if (vertexes.find(id) != vertexes.end()) {
        return vertexes[id];
    }
    return nullptr;
}
    
    TV findById(string id) {
        return vertexes[id]->data;
    };
};

#endif
