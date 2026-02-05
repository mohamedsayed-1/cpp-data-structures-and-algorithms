#pragma once
#include <vector>
#include <cstddef> 


namespace ds{
    struct Edge{
        int to, weight;
    };
    class Graph{
        private:
            size_t vertices;
            bool directed;
            std::vector<std::vector<Edge>> adj;
        public:
            Graph(int v, bool d = false);
            void addEdge(int from, int to, int weight = 1);
    };
}