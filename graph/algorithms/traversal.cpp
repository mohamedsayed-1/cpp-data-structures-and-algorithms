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

    static void DFSHelper(size_t start, std::vector<bool>& visited, 
                            const std::vector<std::vector<ds::Edge>>& adj,
                            std::vector<size_t>& DFSResult){
        if(visited[start]) return;
        DFSResult.push_back(start);
        visited[start] = true;
            for(const auto& i : adj[start]){
            if (!visited[i.to]) DFSHelper(i.to, visited, adj, DFSResult);
        }
    }

    std::vector<size_t> DFS(const ds::Graph& g, size_t start){
        size_t vertices = g.verticesCount();
        if(start >= vertices) throw std::out_of_range("start vertex out of range");
        std::vector<bool> visited(vertices, false);
        std::vector<size_t> DFSResult;
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        DFSHelper(start, visited, adj, DFSResult);
        return DFSResult;
    }
    
    size_t countConnectedComponents(const ds::Graph& g){
        if(g.isDirected()) 
            throw std::logic_error("connected components defined for undirected graph only");
        size_t vertices = g.verticesCount();
        std::vector<bool> visited(vertices, false);
        std::vector<size_t> DFSResult;
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        size_t count = 0;
        for(size_t i = 0; i < vertices; i++){
            if(!visited[i]){ 
                DFSHelper(i, visited, adj, DFSResult);
                count++;
            }
        }
        return count;
    }
    
    static void timerHelper(size_t start, size_t& timer,std::vector<int>& discovery, 
                            std::vector<int>& finish,std::vector<bool>& visited, 
                            const std::vector<std::vector<ds::Edge>>& adj,
                            std::vector<size_t>& DFSResult){
        DFSResult.push_back(start);
        visited[start] = true;
        discovery[start] = ++timer;
        for(const auto& i : adj[start]){
            if (!visited[i.to]) timerHelper(i.to, timer, discovery, finish, visited, adj, DFSResult);
        }
        finish[start] = ++timer;
    }

    TraversalTimestamps DFSWithTimestamps(const ds::Graph& g){
        size_t vertices = g.verticesCount();
        const std::vector<std::vector<ds::Edge>>& adj = g.getAdj();
        std::vector<bool> visited(vertices, false);
        std::vector<int> discovery(vertices, -1), finish(vertices, -1);
        size_t timer = 0;
        std::vector<size_t> DFSResult;
        for(size_t i = 0; i < (size_t)vertices; i++){
            if(!visited[i])
                timerHelper(i, timer, discovery, finish, visited, adj, DFSResult);
        }
        TraversalTimestamps result;
        result.discovery = discovery;
        result.finish = finish;
        return result; 
    }
}