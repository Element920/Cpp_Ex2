// israelmor555@gmail.com
// 206508954

#ifndef ALGORITHMS_H
#define ALGORITHMS_H


#include "Graph.hpp"

namespace ariel
{
    class Algorithms
    {
    public:
        static bool isConnected(Graph g);
        static bool isContainsCycle(Graph g);
        static std::string shortestPath(Graph g, unsigned int startNode, unsigned int endNode);
        static std::string isBipartite(Graph g);
        static bool negativeCycle(const Graph g);
    };
}

#endif
