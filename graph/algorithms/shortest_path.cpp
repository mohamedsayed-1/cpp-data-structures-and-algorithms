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
    
    ShortestPathResult bellmanFord(const ds::Graph& g, size_t start){
        size_t vertices = g.verticesCount();
        if(start >= vertices) 
            throw std::out_of_range("start vertex out of range");
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        ShortestPathResult result;
        std::vector<int> distance(vertices, INT_MAX), parent(vertices, -1);        
        distance[start] = 0;
        for(size_t k = 0; k < vertices - 1; k++){
            int relaxations = 0;
            for(size_t j = 0; j < vertices; j++){
                for(const auto& i : adj[j]){
                    if(distance[j] != INT_MAX && i.weight + distance[j] < distance[i.to]){
                        relaxations++;
                        parent[i.to ] = j;
                        distance[i.to] = i.weight + distance[j];
                    }
                }
            }
            if(relaxations == 0) {
                return {distance, parent};
            }
        }
        for(size_t j = 0; j < vertices; j++){
            for(const auto& i : adj[j]){
                if(distance[j] != INT_MAX && i.weight + distance[j] < distance[i.to])
                    throw std::runtime_error("Negative cycle detected...\n\tbellman-ford cannot work on a graph with a negative cycle");
            }
        }
        return {distance, parent};
    }
    
    std::vector<std::vector<int>> floydWarshall(const ds::Graph& g){
        size_t vertices = g.verticesCount();
        if(vertices > 500)
            throw std::runtime_error("Floyd-Marshall algorithm is very slow on graphs with more than 500 vertices... Exiting...");
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        std::vector<std::vector<int>> matrix(vertices, std::vector<int>(vertices, INT_MAX));
        for (size_t i = 0; i < vertices; i++){
                matrix[i][i] = 0;
            }
        for (size_t i = 0; i < vertices; i++){
            for (const auto& j : adj[i]){                
                matrix[i][j.to] = std::min(matrix[i][j.to], j.weight);
                if(!g.isDirected())
                    matrix[j.to][i] = std::min(matrix[j.to][i], j.weight);
            }
        }
        for(size_t k = 0; k < vertices; k++){
            for(size_t i = 0; i < vertices; i++){
                for(size_t j = 0; j < vertices; j++){
                    if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) 
                        continue;
                    matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        for(size_t i = 0; i < vertices; i++){
            if(matrix[i][i] < 0) 
                throw std::runtime_error("The graph contains a negative cycle");
        }
        return matrix;
    }
    
    std::vector<int> findPath(size_t source, size_t destination, const std::vector<int>& parent){
        std::vector<int> path;
        if (source >= parent.size() || destination >= parent.size()) 
            throw std::out_of_range("vertex is not found");
        int p = destination;
        while(p != -1){
            path.push_back(p);
            if(p == source) {
                std::reverse(path.begin(), path.end());
                return path;
            }
            p = parent[p];
        }
        throw std::runtime_error("these vertices are not connected");
        return path;
    }
}