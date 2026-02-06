#pragma once
#include "../graph.h"
#include <vector>

namespace ds{
    struct BFSTraversalResult{ 
        std::vector<int> distance;
        std::vector<int> parent; 
        std::vector<int> result; 
    };
    struct TraversalTimestamps{ 
        std::vector<int> discovery;
        std::vector<int> finish; 
    };

    BFSTraversalResult BFS(const ds::Graph& g, size_t start);
    std::vector<size_t> DFS(const ds::Graph& g, size_t start);
    size_t countConnectedComponents(const ds::Graph& g);
    TraversalTimestamps DFSWithTimestamps(const ds::Graph& g);
    bool isCyclic(const ds::Graph& g);
}