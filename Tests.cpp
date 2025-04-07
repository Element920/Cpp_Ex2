//israelmor555@gmail.com
//
// Created by israel on 4/6/25.
//
#include "Graph.hpp"
#include <cassert>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "iostream"
#include "stdexcept"
#include "Algorithms.hpp"

using namespace graph;

using namespace std;

TEST_CASE("Test empty graph") {
    Graph g(0);
    g.print_graph();

}

TEST_CASE("Test single node graph") {
    Graph g(1);
    g.print_graph();
}

TEST_CASE("Test Graph") {

    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    std::cout << "Graph after adding edges:\n";
    g.print_graph();

    g.removeEdge(1, 2);
    std::cout << "\nGraph after removing edge (1,2):\n";
    g.print_graph();
}

TEST_CASE("Test Graph DFS") {

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);

    Graph dfsTree = Algorithms::dfs(g, 0);

}

TEST_CASE("Test Graph BFS") {

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    Graph bfsTree = Algorithms::bfs(g, 0);

}

TEST_CASE("Test Graph Dijkstra") {

    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 4);

    Graph shortestPathTree = Algorithms::dijkstra(g, 0);

    shortestPathTree.print_graph();
}

TEST_CASE("Test Graph Dijkstra With Negative Edges") {

    Graph g(3);
    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, -5);

    try {
        Graph result = Algorithms::dijkstra(g, 0);
        std::cout << "Test failed: Negative edge was not detected!\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Test passed: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Test failed: Unexpected exception type.\n";
    }


}
TEST_CASE("Test Prim's algorithm") {

    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);

    Graph mst = Algorithms::prim(g);
    mst.print_graph();

}

TEST_CASE("Test Kruskal's algorithm") {

    Graph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);


    std::cout << "Running Kruskal's Algorithm...\n";
    Graph mst = Algorithms::kruskal(g);
    std::cout << "\nThe MST:\n";
    mst.print_graph();
}


int main() {
    doctest::Context context;
    return context.run();
}