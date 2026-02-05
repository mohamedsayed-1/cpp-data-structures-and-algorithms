#include "graph.h"
#include <iostream>
#include <stdexcept>


ds::Graph::Graph(int v, bool d): directed(d){
    if (v <= 0) throw std::runtime_error("number of vertices must be greater than zero");
    vertices = v;
    adj.resize(vertices);
}
