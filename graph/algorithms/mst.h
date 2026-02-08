#include "../graph.h"
#include <vector>
#include <cstddef> 


namespace ds{
    struct MSTEdge{
        size_t from, to;
        int weight;
    };

    struct MST{
        std::vector<MSTEdge> mst;
        long long totalCost = 0;
    };

    MST kruskal(const Graph& g);
    MST prim(const Graph& g, size_t source);
}