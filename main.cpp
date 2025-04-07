//israelmor555@gmail.com

#include "Graph.hpp"
#include "iostream"
#include "stdexcept"
#include "Algorithms.hpp"

int main() {

using namespace graph;

    graph::Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 1);

    std::cout << "Graph representation:\n";
    g.print_graph();

    std::cout << "\nRemoving edge (1, 3)...\n";
    g.removeEdge(1, 3);
    g.print_graph();
    g.addEdge(1, 3, 4);
    Graph  dfsTree = Algorithms::dfs(g, 0);
    Graph bfsTree = Algorithms::bfs(g, 0);
    return 0;
}
