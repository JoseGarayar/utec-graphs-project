#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include "../graph.h"

template<typename TV, typename TE>
// funcion exec_astar pero con un parametro adicional para testear
std::vector<Vertex<TV, TE>*> exec_astar(Graph<TV, TE>& graph, const std::string& startId, const std::string& goalId) {
    Vertex<TV, TE>* start = graph.getVertex(startId);
    Vertex<TV, TE>* goal = graph.getVertex(goalId);

    // Priority queue for open set (min-heap based on f_score)
    std::priority_queue<
        std::pair<TE, Vertex<TV, TE>*>,
        std::vector<std::pair<TE, Vertex<TV, TE>*> >,
        std::greater<std::pair<TE, Vertex<TV, TE>*> > > openSet;

    std::unordered_map<Vertex<TV, TE>*, TE> gScore;  // Cost from start node
    std::unordered_map<Vertex<TV, TE>*, TE> fScore;  // Estimated total cost to goal node
    std::unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> cameFrom;

    std::vector<Vertex<TV, TE>*> vertices = graph.getVertices();

    for (auto& vertex : vertices) {
        gScore[vertex] = std::numeric_limits<TE>::max();
        fScore[vertex] = std::numeric_limits<TE>::max();
    }

    gScore[start] = 0;
    fScore[start] = heuristic(start, goal);
    openSet.push(std::make_pair(fScore[start], start));

    while (!openSet.empty()) {
        Vertex<TV, TE>* current = openSet.top().second;
        openSet.pop();

        if (current == goal) {
            std::vector<Vertex<TV, TE>*> path;
            while (current) {
                path.push_back(current);
                current = cameFrom[current];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (Edge<TV, TE>* edge : current->edges) {
            Vertex<TV, TE>* neighbor = edge->vertexes[1];

            TE tentative_gScore = gScore[current] + edge->weight;
            if (tentative_gScore < gScore[neighbor]) {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = tentative_gScore + heuristic(neighbor, goal);

                openSet.push(std::make_pair(fScore[neighbor], neighbor));
            }
        }
    }

    return std::vector<Vertex<TV, TE>*>();
};

template<typename TV, typename TE>
TE heuristic(Vertex<TV, TE>* node, Vertex<TV, TE>* goal) {
    // unordered_map<string, float> heuristic_map = {
    //     {"A", 36},
    //     {"B", 39},
    //     {"C", 31},
    //     {"D", 30},
    //     {"E", 34},
    //     {"F", 32},
    //     {"G", 21},
    //     {"H", 19},
    //     {"I", 0},
    // };
    // return heuristic_map[node->data];

    float difLat = abs(stof(node->data.latitude) - stof(goal->data.latitude));
    float difLon = abs(stof(node->data.longitude) - stof(goal->data.longitude));

    float squareLat = difLat * difLat;
    float squareLon = difLon * difLon;

    float sum = squareLat + squareLon;
    
    return sqrt(sum);
}

#endif