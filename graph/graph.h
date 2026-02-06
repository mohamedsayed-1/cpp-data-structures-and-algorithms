#pragma once
#include <vector>
#include <cstddef> 


namespace ds{
    struct Edge{
        size_t to;
        int weight;
    };
    class Graph{
        private:
            size_t vertices;
            bool directed;
            std::vector<std::vector<Edge>> adj;
        public:
            Graph(int v, bool d = false);
            void addEdge(size_t from, size_t to, int weight = 1);
            const std::vector<std::vector<Edge>>& getAdj() const;
            size_t verticesCount() const;
            bool isDirected() const;
            void printGraph()const;
    };
}