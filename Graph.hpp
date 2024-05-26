// israelmor555@gmail.com
// 206508954
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <stdexcept>
#include <vector>
#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        std::string getGraphString(const std::vector<std::vector<int>> &matrix) const;

    public:
        Graph();
        void loadGraph(const std::vector<std::vector<int>> &matrix);
        std::string printGraph() const;
        unsigned int getNumVertices() const;
        int getEdgeWeight(unsigned int from, unsigned int to) const;
        Graph operator+(const Graph &other) const;
        Graph operator*(const Graph &other) const;
        Graph &operator*=(int scalar);
        Graph &operator/=(int scalar);
        
        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator>(const Graph &other) const;
        bool operator<=(const Graph &other) const;
        bool operator>=(const Graph &other) const;

        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
    };
}

#endif

