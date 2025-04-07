////israelmor555@gmail.com

// Created by israel on 3/24/25.
//

#include "Graph.hpp"
#include <cassert>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "iostream"
#include "stdexcept"
#include "Algorithms.hpp"



using namespace graph;

void testGraph() {

    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    std::cout << "Graph after adding edges:\n";
    g.print_graph();

    g.removeEdge(1, 2);
    std::cout << "\nGraph after removing edge (1,2):\n";
    g.print_graph();

    }

    void testBFS() {
        Graph g(5);  // Create a graph with 5 vertices
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 3, 1);
        g.addEdge(1, 4, 1);
        Graph bfsTree = Algorithms::bfs(g, 0);

    }

    void testDFS() {
        Graph g(5);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 3, 1);
        g.addEdge(1, 4, 1);

        Graph dfsTree = Algorithms::dfs(g, 0);


    }

    void testDijkstra() {
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

    void testNegativeEdges() {
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
void testPrimMST() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);

    Graph mst = Algorithms::prim(g);
    mst.print_graph();
}

void testKruskal() {
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


void testEmptyGraph() {
    std::cout << "\nTesting Empty Graph...\n";
    Graph g(0);
    try {
        Graph bfs = Algorithms::bfs(g, 0);
        std::cout << "BFS on empty graph did not throw!\n";
    } catch (const std::exception& e) {
        std::cout << "BFS correctly threw: " << e.what() << "\n";
    }

    try {
        Graph dfs = Algorithms::dfs(g, 0);
        std::cout << "DFS on empty graph did not throw!\n";
    } catch (const std::exception& e) {
        std::cout << "DFS correctly threw: " << e.what() << "\n";
    }

    try {
        Graph dijkstraTree = Algorithms::dijkstra(g, 0);
        std::cout << "Dijkstra on empty graph did not throw!\n";
    } catch (const std::exception& e) {
        std::cout << "Dijkstra correctly threw: " << e.what() << "\n";
    }
}

int main() {
    testGraph();
    std::cout << "Testing BFS..." << std::endl;
    testBFS();

    std::cout << "Testing DFS..." << std::endl;
    testDFS();

    std::cout << "Testing Dijkstra..." << std::endl;
    testDijkstra();
    testNegativeEdges();

    std::cout << "Testing Prim..." << std::endl;
    testPrimMST();

    std::cout << "Testing Kruskal..." << std::endl;
    testKruskal();

    testEmptyGraph();

    std::cout << "\nAll tests passed!\n";


    return 0;
}
