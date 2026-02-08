#include "../graph.h"
#include <vector>
#include <cstddef>


namespace ds{
    
    struct ShortestPathResult{
        std::vector<int> distance;
        std::vector<int> parent;
    };

    ShortestPathResult Dijkstra(const ds::Graph& g, size_t start);
    ShortestPathResult bellmanFord(const ds::Graph& g, size_t start);
    std::vector<std::vector<int>> floydWarshall(const ds::Graph& g);
    std::vector<int> findPath(size_t source, size_t destination, const std::vector<int>& parent);
}