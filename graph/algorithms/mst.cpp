#include "mst.h"
#include <queue>
#include <stdexcept>
#include <climits>

namespace ds{
    struct DSU{
        std::vector<size_t> parents, rank;
        
        DSU(size_t n){
            parents.resize(n);
            rank.resize(n, 0);
            for(size_t i = 0; i < n; i++) parents[i] = i;
        }

        size_t find(size_t n){
            if(parents[n] == n) return n;
            return parents[n] = find(parents[n]);
        }

        bool unite(size_t x, size_t y){
            x = find(x);
            y = find(y);
            if(x == y) return false;

            if (rank[x] > rank[y]) parents[y] = x;
            else if (rank[x] < rank[y]) parents[x] = y;
            else if (rank[x] == rank[y]){
                parents[y] = x;
                rank[x]++;
            }
            return true;
        }
    };

    MST kruskal(const Graph& g){
        size_t vertices = g.verticesCount();
        const auto& adj = g.getAdj();
        if(g.isDirected()){
            throw std::logic_error("Kruskal requires undirected graph");
        }
        MST mst;
        DSU d(vertices);
        std::priority_queue<std::pair<int, std::pair<size_t, size_t>>, 
            std::vector<std::pair<int, std::pair<size_t, size_t>>>, 
            std::greater<std::pair<int, std::pair<size_t ,size_t>>>
        > pq;

        for(size_t i = 0; i < vertices; i++){
            for(const auto& edge : adj[i]){
                int to = edge.to;
                int weight = edge.weight;
                if (i < (size_t)to) 
                    pq.push({weight , {i, to}});
            }
        }

        int selected = 0;
        while(!pq.empty() && selected < vertices - 1){

            auto top = pq.top();
            pq.pop();

            size_t u = top.second.first;
            size_t v = top.second.second;
            int w = top.first;

            if(d.unite(u, v)){ 
                mst.totalCost += w;
                selected++;
                mst.mst.push_back({u, v, w});
            }
        }
        return mst;
    }

    MST prim(const Graph& g, size_t start){
        size_t vertices = g.verticesCount();
        if(start >= vertices) 
            throw std::out_of_range("start vertex out of range");
        std::vector<bool> visited(vertices, false);
        std::vector<int> parent(vertices, -1), distance(vertices, INT_MAX);
        const auto& adj = g.getAdj();
        if(g.isDirected()){
            throw std::logic_error("prim requires undirected graph");
        }
        long long cost = 0, allVisited = 0;
        std::priority_queue<std::pair<int, std::pair<int, size_t>>,
            std::vector<std::pair<int, std::pair<int, size_t>>>, 
            std::greater<std::pair<int, std::pair<int, size_t>>>
        > pq;
        pq.push({0,{-1,start}});

        while(!pq.empty() && allVisited < vertices){
            auto top = pq.top();
            pq.pop();

            int u = top.second.first;
            int v = top.second.second;
            int w = top.first;

            if(visited[v]) continue;
            visited[v] = true;
            allVisited++;

            parent[v] = u;
            distance[v] = w;
            cost += w;

            for(const auto& edge : adj[v]){
                int to = edge.to;
                int weight = edge.weight;
                if(!visited[to])
                    pq.push({weight, {v, to}});
            }
        }
        MST mst;
        mst.totalCost = cost;
        for (size_t i = 0; i < vertices; i++){
            if(parent[i] != -1)
                mst.mst.push_back({(size_t)parent[i], i, distance[i]});
        }
        if(allVisited != vertices)
            throw std::runtime_error("Graph is disconnected; MST does not exist");
        return mst;
    }
}