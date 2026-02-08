#include "../graph.h"
#include <vector>
#include <cstddef>


namespace ds{
    
    struct ShortestPathResult{
        std::vector<int> distance;
        std::vector<int> parent;
    };

    ShortestPathResult Dijkstra(const ds::Graph& g, size_t start);
}