#include "shortest_path.h"
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <climits>

namespace ds{
    ShortestPathResult Dijkstra(const ds::Graph& g, size_t start){
        size_t vertices = g.verticesCount();
        if(start >= vertices) 
            throw std::out_of_range("start vertex out of range");
        if (g.hasNegativeWeights())
            throw std::runtime_error("Dijkstra's algorithm can't be performed on negative weighted edges");
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        std::vector<int> distance(vertices, INT_MAX), parent(vertices, -1);
        // the pair in priority_queue is pair<weight, to> 
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int ,int>>, std::greater<std::pair<int , int>>> dijk;
        dijk.push({0, start});
        distance[start] = 0;
        while(!dijk.empty()){
            int currWeight = dijk.top().first; 
            int front = dijk.top().second;
            dijk.pop();
            if (currWeight > distance[front]) 
                continue;
            for(const auto& i : adj[front]){
                if(distance[front] != INT_MAX && i.weight + distance[front] < distance[i.to]){
                    parent[i.to] = front;
                    distance[i.to] = i.weight + distance[front];
                    dijk.push({distance[i.to], i.to});
                }
            }
        }
        return {distance, parent};
    }
}