//israelmor555@gmail.com
//206508954
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}



// TEST_CASE("Invalid operations")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1, 1},
//         {1, 0, 2, 1},
//         {1, 2, 0, 1}};
//     g2.loadGraph(weightedGraph);
//     ariel::Graph g5;
//     vector<vector<int>> graph2 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g5.loadGraph(graph2);
//     CHECK_THROWS(g5 * g1);
//     CHECK_THROWS(g1 * g2);

//     // Addition of two graphs with different dimensions
//     ariel::Graph g6;
//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g6.loadGraph(graph3);
//     CHECK_THROWS(g1 + g6);
// }

TEST_CASE("Test multiplication by scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1 *= -2;
    CHECK(g1.printGraph() == "[0, -2, 0]\n[-2, 0, -2]\n[0, -2, 0]");
}

// TEST_CASE("Test division by scalar")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);

//     g1 /= -2;
//     CHECK(g1.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
// }

TEST_CASE("Test empty graph")
{
    ariel::Graph g1;
    CHECK(g1.printGraph() == "Graph is empty.");
}

TEST_CASE("Test single vertex graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {{0}};
    g1.loadGraph(graph);
    CHECK(g1.printGraph() == "[0]");
}

TEST_CASE("Test large graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph(100, vector<int>(100, 0)); // 100x100 zero-filled graph
    g1.loadGraph(graph);
    // Check if the dimensions are correct
    CHECK(g1.getNumVertices() == 100);
}

TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1; // Create a copy of g1
    CHECK(g1 == g2);
}

TEST_CASE("Test graph equality and inequality") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 == g2);
    CHECK(!(g1 != g2));

    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph3);

    CHECK(g1 != g2);
    CHECK(!(g1 == g2));
}

// TEST_CASE("Test graph comparison operators") {
//     Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);

//     Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 1},
//         {1, 1, 0}};
//     g2.loadGraph(graph2);

//     CHECK(g1 < g2);
//     CHECK(g2 > g1);
//     CHECK(g1 <= g2);
//     CHECK(g2 >= g1);
//     CHECK(!(g1 > g2));
//     CHECK(!(g2 < g1));

//     Graph g3;
//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0},
//         {1, 0, 1, 0},
//         {0, 1, 0, 1},
//         {0, 0, 1, 0}};
//     g3.loadGraph(graph3);

//     CHECK(g1 < g3);
//     CHECK(g3 > g1);
//     CHECK(g1 <= g3);
//     CHECK(g3 >= g1);
//     CHECK(!(g1 > g3));
//     CHECK(!(g3 < g1));
// }

// TEST_CASE("Test division by scalar") {
//     Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);

//     g1 /= -2;
//     CHECK(g1.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
//     CHECK_THROWS(g1 /= 0); // Division by zero
// }

TEST_CASE("Test empty graph") {
    Graph g1;
    CHECK(g1.printGraph() == "Graph is empty.");
}

TEST_CASE("Test single vertex graph") {
    Graph g1;
    vector<vector<int>> graph = {{0}};
    g1.loadGraph(graph);
    CHECK(g1.printGraph() == "[0]");
}

TEST_CASE("Test large graph") {
    Graph g1;
    vector<vector<int>> graph(100, vector<int>(100, 0)); // 100x100 zero-filled graph
    g1.loadGraph(graph);
    // Check if the dimensions are correct
    CHECK(g1.getNumVertices() == 100);
}

TEST_CASE("Test graph equality") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2 = g1; // Create a copy of g1
    CHECK(g1 == g2);
}

TEST_CASE("Test graph inequality") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("Test edge weight") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g1.loadGraph(graph);
    
    CHECK(g1.getEdgeWeight(0, 1) == 2);
    CHECK(g1.getEdgeWeight(1, 2) == 3);
}

TEST_CASE("Test edge weight with non-existent edge") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g1.loadGraph(graph);
    
    CHECK(g1.getEdgeWeight(0, 2) == 0); // Non-existent edge, weight should be 0
}

// TEST_CASE("Test graph addition") {
//     // Create two graphs with different dimensions
//     Graph g1;
//     vector<vector<int>> graph1 = {{0, 1}, {1, 0}};
//     g1.loadGraph(graph1);
    
//     Graph g2;
//     vector<vector<int>> graph2 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
//     g2.loadGraph(graph2);
    
//     // Check that adding graphs with different dimensions throws an exception
//     CHECK_THROWS(g1 + g2);

//     // Test adding two empty graphs
//     Graph g3;
//     Graph g4;
//     Graph g5 = g3 + g4;
//     CHECK(g5.printGraph() == "Graph is empty.");
// }


// TEST_CASE("Test graph multiplication") {
//     // Create two graphs with different dimensions
//     Graph g1;
//     vector<vector<int>> graph1 = {{0, 1}, {1, 0}};
//     g1.loadGraph(graph1);
    
//     Graph g2;
//     vector<vector<int>> graph2 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
//     g2.loadGraph(graph2);
    
//     // Check that multiplying graphs with different dimensions throws an exception
//     CHECK_THROWS(g1 * g2);

//     // Test multiplying a graph by the identity matrix
//     Graph g3;
//     vector<vector<int>> graph3 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
//     g3.loadGraph(graph3);
//     Graph g4 = g2 * g3;
//     CHECK(g4 == g2); // Result should be the same as g2

//     // Test multiplying two empty graphs
//     Graph g5;
//     Graph g6;
//     Graph g7 = g5 * g6;
//     CHECK(g7.printGraph() == "Graph is empty.");
// }

TEST_CASE("Test multiplication by scalar") {
    // Test multiplying a graph by a positive scalar
    Graph g1;
    vector<vector<int>> graph1 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    g1.loadGraph(graph1);
    g1 *= 2;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");

    // Test multiplying a graph by a negative scalar
    Graph g2;
    vector<vector<int>> graph2 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    g2.loadGraph(graph2);
    g2 *= -2;
    CHECK(g2.printGraph() == "[0, -2, 0]\n[-2, 0, -2]\n[0, -2, 0]");

    // Test multiplying a graph by zero
    Graph g3;
    vector<vector<int>> graph3 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    g3.loadGraph(graph3);
    g3 *= 0;
    CHECK(g3.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Test division by scalar") {
    // Test dividing a graph by a positive scalar
    Graph g1;
    vector<vector<int>> graph1 = {{0, 2, 0}, {2, 0, 4}, {0, 4, 0}};
    g1.loadGraph(graph1);
    g1 /= 2;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 2]\n[0, 2, 0]");

    // Test dividing a graph by a negative scalar
    Graph g2;
    vector<vector<int>> graph2 = {{0, 2, 0}, {2, 0, 4}, {0, 4, 0}};
    g2.loadGraph(graph2);
    g2 /= -2;
    CHECK(g2.printGraph() == "[0, -1, 0]\n[-1, 0, -2]\n[0, -2, 0]");
}

TEST_CASE("Test graph equality and inequality") {
    // Test graph equality with different graphs
    Graph g1;
    vector<vector<int>> graph1 = {{0, 1}, {1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {{0, 1}, {1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 == g2);

    // Test graph inequality with identical graphs
    Graph g3;
    vector<vector<int>> graph3 = {{0, 1}, {1, 0}};
    g3.loadGraph(graph3);

    CHECK(!(g1 != g3));
}

TEST_CASE("Test edge weight") {
    // Test getting the weight of an existing edge
    Graph g1;
    vector<vector<int>> graph1 = {{0, 2, 0}, {2, 0, 3}, {0, 3, 0}};
    g1.loadGraph(graph1);
    CHECK(g1.getEdgeWeight(0, 1) == 2);
    CHECK(g1.getEdgeWeight(1, 2) == 3);

    // Test getting the weight of a non-existent edge
    CHECK(g1.getEdgeWeight(0, 2) == 0);
}

TEST_CASE("Test edge weight") {
    // Test retrieving the weight of an existing edge in a graph
    Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g1.loadGraph(graph);
    
    CHECK(g1.getEdgeWeight(0, 1) == 2);
    CHECK(g1.getEdgeWeight(1, 2) == 3);
}

TEST_CASE("Test graph inequality") {
    // Test the inequality operator between two different graphs
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("Test graph equality") {
    // Test the equality operator between two identical graphs
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2 = g1; // Create a copy of g1
    CHECK(g1 == g2);
}

// TEST_CASE("Test graph multiplication")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(weightedGraph);
//     ariel::Graph g4 = g1 * g2;
//     CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");
// }