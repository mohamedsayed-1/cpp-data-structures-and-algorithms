#pragma once
#include "../graph.h"
#include <vector>

namespace ds{
    struct BFSTraversalResult{ 
        std::vector<int> distance;
        std::vector<int> parent; 
        std::vector<int> result; 
    };

    BFSTraversalResult BFS(const ds::Graph& g, size_t start);
    std::vector<size_t> DFS(const ds::Graph& g, size_t start);
}