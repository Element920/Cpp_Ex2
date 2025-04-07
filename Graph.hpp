//israelmor555@gmail.com

#pragma once

namespace graph {

    class Graph {
    public:
        struct Edge {
            int dest;
            int weight;
            Edge* next;
        };

        struct Node {
            Edge* head;
        };

        Node head;
        Node* adjList;
        const int numVertices;


        Graph(int vertices);
        ~Graph();
        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph() const;
        void print_edge() const;
        void print_total_weight() const;
        int size() const;
        const Node* getAdjList() const { return adjList; };
        const Node getHead() const { return head; };

    private:
        Edge* removeEdgeHelper(Edge* head, int dest);
    };


} // namespace graph
