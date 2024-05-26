// israelmor555@gmail.com
// 206508954


#include "Algorithms.hpp"
#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>

namespace ariel {

bool Algorithms::isConnected(Graph g) {
    unsigned int numNodes = g.getNumVertices();
    if (numNodes == 0) return true; // Empty graph is considered connected

    std::vector<bool> visited(numNodes, false);
    std::queue<unsigned int> q;
    unsigned int startNode = 0;

    // Mark the start node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        // Dequeue a node from the queue
        unsigned int currentNode = q.front();
        q.pop();

        // Visit all adjacent nodes of the dequeued node
        for (unsigned int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (g.getEdgeWeight(currentNode, neighbor) != 0 && !visited[neighbor]) {
                // Mark the adjacent node as visited and enqueue it
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Check if all nodes were visited
    for (bool nodeVisited : visited) {
        if (!nodeVisited) {
            return false;
        }
    }
    return true;
}

bool Algorithms::isContainsCycle(Graph g) {
    unsigned int numNodes = g.getNumVertices();
    if (numNodes == 0) return false; // Empty graph cannot have a cycle

    std::vector<bool> visited(numNodes, false);
    std::stack<unsigned int> stack;
    std::vector<int> parent(numNodes, -1);
    stack.push(0);
    visited[0] = true;

    while (!stack.empty()) {
        unsigned int currentNode = stack.top();
        stack.pop();

        for (unsigned int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (g.getEdgeWeight(currentNode, neighbor) != 0) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = static_cast<int>(currentNode); // Explicit conversion to int
                    stack.push(neighbor);
                } else if (parent[currentNode] != static_cast<int>(neighbor)) { // Explicit conversion to int
                    return true;
                }
            }
        }
    }
    return false;
}

std::string Algorithms::shortestPath(const Graph g, unsigned int startNode, unsigned int endNode) {
    unsigned int numVertices = g.getNumVertices();
    if (startNode >= numVertices || endNode >= numVertices) return "-1";

    std::vector<bool> visited(numVertices, false);
    std::vector<int> parent(numVertices, -1);

    std::queue<unsigned int> queue;
    queue.push(startNode);
    visited[startNode] = true;

    bool found = false;
    while (!queue.empty() && !found) {
        unsigned int u = queue.front();
        queue.pop();

        for (unsigned int neighbor = 0; neighbor < numVertices; neighbor++) {
            if (g.getEdgeWeight(u, neighbor) > 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = static_cast<int>(u); // Explicit conversion to int
                queue.push(neighbor);

                if (neighbor == endNode) {
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found) {
        return "-1"; // No path found between startNode and endNode
    }

    // Reconstruct path by backtracking from endNode
    std::vector<unsigned int> path;
    int current = static_cast<int>(endNode); // Explicit conversion to int
    while (current != -1) {
        path.push_back(static_cast<unsigned int>(current)); // Explicit conversion to unsigned int
        current = parent[static_cast<size_t>(current)]; // Explicit conversion to std::vector::size_type
    }

    std::stringstream ss;
    std::reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i) {
        if (i != 0) {
            ss << "->";
        }
        ss << path[i];
    }

    return ss.str();
}


std::string Algorithms::isBipartite(Graph g) {
    unsigned int numVertices = g.getNumVertices();
    if (numVertices == 0) return "The graph is bipartite: A={}, B={}";

    std::vector<int> color(numVertices, -1); // -1: uncolored, 0/1: assigned color 
    std::vector<unsigned int> set1, set2;
    unsigned int startNode = 0;
    color[startNode] = 1;

    std::queue<unsigned int> queue;
    queue.push(startNode);
    set1.push_back(startNode);

    while (!queue.empty()) {
        unsigned int u = queue.front();
        queue.pop();

        if (g.getEdgeWeight(u, u) > 0)
            return "0";

        for (unsigned int v = 0; v < numVertices; ++v) {
            if (g.getEdgeWeight(u, v) && color[v] == -1) {
                color[v] = 1 - color[u];
                if (color[v] == 1) {
                    set1.push_back(v);
                } else {
                    set2.push_back(v);
                }
                queue.push(v);
            } else if (g.getEdgeWeight(u, v) && color[v] == color[u]) {
                return "0";
            }
        }
    }

    std::stringstream ss;
    ss << "The graph is bipartite: A={";
    for (size_t i = 0; i < set1.size(); ++i) {
        if (i != 0)
            ss << ", ";
        ss << set1[i];
    }
    ss << "}, B={";
    for (size_t i = 0; i < set2.size(); ++i) {
        if (i != 0)
            ss << ", ";
        ss << set2[i];
    }
    ss << "}";
    return ss.str();
}

bool Algorithms::negativeCycle(Graph g) {
    unsigned int numVertices = g.getNumVertices();
    if (numVertices == 0) return false; // Empty graph cannot have a negative cycle

    std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
    distance[0] = 0; // Distance from source to itself is 0

    // Relaxation process (V-1 iterations)
    for (unsigned int i = 0; i < numVertices - 1; ++i) {
        for (unsigned int u = 0; u < numVertices; ++u) {
            for (unsigned int v = 0; v < numVertices; ++v) {
                // Relax if edge exists and total weight is less than current distance
                if (g.getEdgeWeight(u, v) != 0 && distance[u] != std::numeric_limits<int>::max() && distance[u] + g.getEdgeWeight(u, v) < distance[v]) {
                    distance[v] = distance[u] + g.getEdgeWeight(u, v);
                }
            }
        }
    }

    // Check for negative cycle in the Vth iteration
    for (unsigned int u = 0; u < numVertices; ++u) {
        for (unsigned int v = 0; v < numVertices; ++v) {
            if (g.getEdgeWeight(u, v) != 0 && distance[u] != std::numeric_limits<int>::max() && distance[u] + g.getEdgeWeight(u, v) < distance[v]) {
                return true; // Negative cycle detected
            }
        }
    }

    return false; // No negative cycle found
}

}
