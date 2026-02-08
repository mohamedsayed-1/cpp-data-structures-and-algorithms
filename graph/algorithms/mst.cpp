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
}