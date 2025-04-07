//israelmor555@gmail.com

//
// Created by israel on 3/23/25.
//
#include "Graph.hpp"
#include <stdexcept>
#include "iostream"

namespace graph {

    Graph::Graph(int vertices) : numVertices(vertices) {
        adjList = new Node[vertices]();
        for (int i = 0; i < vertices; ++i) {
            adjList[i].head = nullptr;
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            Edge* current = adjList[i].head;
            while (current) {
                Edge* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex index");
        }
        Edge* newEdge1 = new Edge{dest, weight, adjList[src].head};
        adjList[src].head = newEdge1;
        Edge* newEdge2 = new Edge{src, weight, adjList[dest].head};
        adjList[dest].head = newEdge2;
    }

    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex index");
        }
        adjList[src].head = removeEdgeHelper(adjList[src].head, dest);
        adjList[dest].head = removeEdgeHelper(adjList[dest].head, src);
    }

    Graph::Edge* Graph::removeEdgeHelper(Edge* head, int dest) {
        if (!head) return nullptr;
        if (head->dest == dest) {
            Edge* next = head->next;
            delete head;
            return next;
        }
        head->next = removeEdgeHelper(head->next, dest);
        return head;
    }

    void Graph::print_graph() const {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << ": ";
            for (Edge* e = adjList[i].head; e; e = e->next) {
                std::cout << "(" << e->dest << ", " << e->weight << ") ";
            }
            std::cout << std::endl;
        }
    }
     int Graph::size() const {
        return numVertices;
    }

    void Graph::print_edge() const {
		const Edge* current = adjList[0].head;
                while (current) {
                  std::cout << "(" << current->dest << ") ";
                }
    }

    void Graph::print_total_weight() const {
      int totalWeight = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (Edge* e = adjList[i].head; e; e = e->next) {
                totalWeight += e->weight;
            }
        }
        std::cout << totalWeight << std::endl;
    }
}