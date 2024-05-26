#include "Graph.hpp"
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>

namespace ariel {

    Graph::Graph() {}

    void Graph::loadGraph(const std::vector<std::vector<int>> &matrix) {
        unsigned int numVertices = matrix.size();
        if (matrix[0].size() != numVertices) {
            throw std::invalid_argument("Error: Invalid adjacency matrix dimensions.");
        }
        adjMatrix = matrix;
    }

    std::string Graph::printGraph() const {
        if (adjMatrix.empty()) {
            return "Graph is empty.";
        }

        return getGraphString(adjMatrix);
    }

    std::string Graph::getGraphString(const std::vector<std::vector<int>> &matrix) const {
        std::string result;
        for (const auto &row : matrix) {
            result += "[";
            for (size_t i = 0; i < row.size(); ++i) {
                result += std::to_string(row[i]);
                if (i < row.size() - 1) {
                    result += ", ";
                }
            }
            result += "]\n";
        }
        // Remove the trailing newline character
        if (!result.empty()) {
            result.pop_back();
        }
        return result;
    }

    std::ostream &operator<<(std::ostream &os, const Graph &graph) {
        os << graph.getGraphString(graph.adjMatrix);
        return os;
    }

    unsigned int Graph::getNumVertices() const {
        return adjMatrix.size();
    }

    int Graph::getEdgeWeight(unsigned int from, unsigned int to) const {
        return adjMatrix[from][to];
    }

    Graph Graph::operator+(const Graph &other) const {
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
            throw std::invalid_argument("Error: Graphs must have the same dimensions for addition.");
        }

        Graph result;
        std::vector<std::vector<int>> sum(adjMatrix.size(), std::vector<int>(adjMatrix[0].size(), 0));
        for (unsigned int i = 0; i < adjMatrix.size(); ++i) {
            for (unsigned int j = 0; j < adjMatrix[0].size(); ++j) {
                sum[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
            }
        }
        result.loadGraph(sum);
        return result;
    }

    Graph Graph::operator*(const Graph &other) const {
    if (adjMatrix.size() != other.adjMatrix.size()) {
        throw std::invalid_argument("Error: Graphs must have the same dimensions for multiplication.");
    }

    Graph result;
    std::vector<std::vector<int>> product(adjMatrix.size(), std::vector<int>(adjMatrix.size(), 0));
   for (unsigned int i = 0; i < adjMatrix.size(); ++i) {
    for (unsigned int j = 0; j < other.adjMatrix[0].size(); ++j) {
        for (unsigned int k = 0; k < adjMatrix.size(); ++k) {
            product[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
        }
    }
}


    result.loadGraph(product);
    return result;
}


    Graph &Graph::operator*=(int scalar) {
        for (unsigned int i = 0; i < adjMatrix.size(); ++i) {
            for (unsigned int j = 0; j < adjMatrix[0].size(); ++j) {
                adjMatrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    Graph &Graph::operator/=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Error: Division by zero.");
    }
    for (unsigned int i = 0; i < adjMatrix.size(); ++i) {
        for (unsigned int j = 0; j < adjMatrix[0].size(); ++j) {
            adjMatrix[i][j] /= scalar;
        }
    }
    return *this;
}


    bool Graph::operator==(const Graph &other) const {
        return adjMatrix == other.adjMatrix;
    }

    bool Graph::operator!=(const Graph &other) const {
        return !(*this == other);
    }

    bool Graph::operator<(const Graph &other) const {
        if (*this == other) {
            return false;
        }
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
            return false;
        }
        // Compare if g1 is contained in g2
        for (unsigned int i = 0; i < adjMatrix.size(); ++i) {
            for (unsigned int j = 0; j < adjMatrix[0].size(); ++j) {
                if (adjMatrix[i][j] > other.adjMatrix[i][j]) {
                    return false;
                }
            }
        }
        // If not contained, compare number of edges
        int edgeCount1 = 0, edgeCount2 = 0;
        for (unsigned int i = 0; i < adjMatrix.size(); ++i) {
            for (unsigned int j = 0; j < adjMatrix[0].size(); ++j) {
                if (adjMatrix[i][j] != 0) edgeCount1++;
                if (other.adjMatrix[i][j] != 0) edgeCount2++;
            }
        }
        if (edgeCount1 != edgeCount2) {
            return edgeCount1 < edgeCount2;
        }
        
        return adjMatrix < other.adjMatrix;
    }

    bool Graph::operator>(const Graph &other) const {
        return other < *this;
    }

    bool Graph::operator<=(const Graph &other) const {
        return !(*this > other);
    }

    bool Graph::operator>=(const Graph &other) const {
        return !(*this < other);
    }
}
