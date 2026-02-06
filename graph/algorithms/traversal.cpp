#include "traversal.h"
#include <stdexcept>
#include <queue>

namespace ds{
    BFSTraversalResult BFS(const ds::Graph& g, size_t start){
        size_t vertices = g.verticesCount();
        if(start >= vertices) throw std::out_of_range("start vertex out of range");
        std::vector<bool> visited(vertices, false);
        std::vector<int> result, distance(vertices, -1), parent(vertices, -1);
        std::queue<size_t> bfs;
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        visited[start] = true;
        distance[start] = 0;
        bfs.push(start);
        while(!bfs.empty()){
            size_t front = bfs.front();
            result.push_back(front);
            bfs.pop();
            for(const auto& i : adj[front]){
                if(!visited[i.to]){
                    visited[i.to] = true;
                    parent[i.to] = front;
                    distance[i.to] = distance[front] + 1;
                    bfs.push(i.to);
                }
            }
        }
        BFSTraversalResult r;
        r.distance = distance;
        r.parent = parent;
        r.result = result;
        return r;
    }
}