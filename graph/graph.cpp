#include "graph.h"
#include <iostream>
#include <stdexcept>


ds::Graph::Graph(int v, bool d): directed(d){
    if (v <= 0) throw std::runtime_error("number of vertices must be greater than zero");
    vertices = v;
    adj.resize(vertices);
}

void ds::Graph::addEdge(int from, int to, int weight){
    if (from < 0 || from >= vertices || to < 0 || to >= vertices) 
        throw std::runtime_error("vertex is not found");
    adj[from].push_back({to, weight});
    if(!directed) adj[to].push_back({from, weight});
}