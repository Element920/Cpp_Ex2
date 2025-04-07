//israelmor555@gmail.com

//
// Created by israel on 3/23/25.
//

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#pragma once
#include "Graph.hpp"


namespace graph {

    class Algorithms {
    public:
        static Graph bfs(const Graph& g, int start);
        static Graph dfs(const Graph& g, int start);
        static Graph dijkstra(const Graph& g, int start);
        static Graph prim(const Graph& g);
        static Graph kruskal(const Graph& g);
    };

}

#endif
