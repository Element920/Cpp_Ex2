//israelmor555@gmail.com

//
// Created by israel on 3/23/25.
//
#include "Algorithms.hpp"
#include "DataStructures.hpp"
#include "Graph.hpp"
#include <climits>
#include <stdexcept>
#include "iostream"

namespace graph {

    Graph Algorithms::bfs(const Graph& g, int start) {
        int n = g.size();
        Graph tree(n);

        bool* visited = new bool[n]();
        Queue q(n);

        visited[start] = true;
        q.push(start);

        int* order = new int[n];
        int orderIndex = 0;

        while (!q.empty()) {
            int v = q.pop();
            order[orderIndex++] = v;  // שומר את הקודקודים לפי סדר הביקור
            const Graph::Node* adjList = g.getAdjList();
            for (Graph::Edge* e = adjList[v].head; e; e = e->next) {
                if (!visited[e->dest]) {
                    visited[e->dest] = true;
                    tree.addEdge(v, e->dest, e->weight);
                    q.push(e->dest);
                }
            }
        }

        std::cout << "BFS: ";
        for (int i = 0; i < orderIndex; ++i) {
            std::cout << order[i] << (i == orderIndex - 1 ? "" : ", ");
        }
        std::cout << std::endl;

        delete[] visited;
        delete[] order;
        return tree;
    }


    Graph Algorithms::dfs(const Graph& g, int start) {
        int n = g.size();
        Graph tree(n);

        bool* visited = new bool[n]();
        Stack s(n);

        s.push(start);
        visited[start] = true;

        int* order = new int[n];
        int orderIndex = 0;

        while (!s.empty()) {
            int v = s.pop();
            order[orderIndex++] = v;
            const Graph::Node* adjList = g.getAdjList();
            for (Graph::Edge* e = adjList[v].head; e; e = e->next) {
                if (!visited[e->dest]) {
                    visited[e->dest] = true;
                    tree.addEdge(v, e->dest, e->weight);
                    s.push(e->dest);
                }
            }
        }

        std::cout << "DFS: ";
        for (int i = 0; i < orderIndex; ++i) {
            std::cout << order[i] << (i == orderIndex - 1 ? "" : ", ");
        }
        std::cout << std::endl;

        delete[] visited;
        delete[] order;
        return tree;
    }


    Graph Algorithms::dijkstra(const Graph& g, int start) {
    int n = g.size();
    Graph shortestPathTree(n);

    const Graph::Node* adjList = g.getAdjList();
    for (int i = 0; i < n; ++i) {
        for (Graph::Edge* e = adjList[i].head; e; e = e->next) {
            if (e->weight < 0) {
                throw std::invalid_argument("Error: Negative edge weight detected. Dijkstra's algorithm cannot handle negative edges.");
            }
        }
    }

    int* dist = new int[n];
    bool* visited = new bool[n]();
    PriorityQueue pq(n);

    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    pq.push(start, 0);

    while (!pq.empty()) {
        int u = pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (Graph::Edge* e = adjList[u].head; e; e = e->next) {
            if (dist[u] + e->weight < dist[e->dest]) {
                dist[e->dest] = dist[u] + e->weight;
                pq.push(e->dest, dist[e->dest]);
                shortestPathTree.addEdge(u, e->dest, e->weight);
            }
        }
    }

    delete[] dist;
    delete[] visited;
    return shortestPathTree;
}
    Graph Algorithms::prim(const Graph& g) {
    int V = g.size();
    Graph mst(V);

    int* parent = new int[V];       // Store constructed MST
    int* key = new int[V];          // Minimum edge weight
    bool* inMST = new bool[V];

    PriorityQueue pq(V);

    // Initialize all keys as INFINITE and inMST to false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;
    pq.push(0, 0); // Push root node to priority queue

    while (!pq.empty()) {
        int u = pq.pop();
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        const Graph::Node* adjList = g.getAdjList();
        for (Graph::Edge* e = adjList[u].head; e; e = e->next) {
            int v = e->dest;
            int weight = e->weight;

            // Check if v is not in MST and weight is smaller
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(v, key[v]);
            }
        }
    }

    // Build the MST using parent array
    for (int i = 1; i < V; i++) {
        mst.addEdge(parent[i], i, key[i]);
    }


    delete[] parent;
    delete[] key;
    delete[] inMST;

    return mst;
}

    Graph Algorithms::kruskal(const Graph& g) {
    int n = g.size();
    Graph mst(n);
    UnionFind uf(n);

    struct EdgeData {
        int src, dest, weight;
    };

    EdgeData* edges = new EdgeData[n * n];
    int edgeCount = 0;

    // מעתיקים את כל הקשתות למערך edges
    for (int i = 0; i < n; i++) {
        Graph::Edge* e = g.getAdjList()[i].head;
        while (e != nullptr) {
            if (i < e->dest) { // נמנע מכפילויות
                edges[edgeCount++] = {i, e->dest, e->weight};
            }
            e = e->next;
        }
    }

    // מיון הבועות על המערך edges לפי המשקל
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                EdgeData temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // הוספת הקשתות עם Union-Find
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            mst.addEdge(u, v, edges[i].weight);
        }
    }

    delete[] edges;
    return mst;
}
}  // namespace graph

