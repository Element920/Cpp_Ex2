//israelmor555@gmail.com
// Created by israel on 3/23/25.
//
#include "DataStructures.hpp"
#include <stdexcept>
#include <climits>


namespace graph {

// ---------------- תור (Queue) ----------------
    Queue::Queue() : front(nullptr), rear(nullptr), capacity(INT_MAX), currentSize(0) {}

    Queue::Queue(int size) : front(nullptr), rear(nullptr), capacity(size), currentSize(0) {
        if (size <= 0) throw std::invalid_argument("Queue size must be greater than 0");
    }

    Queue::~Queue() {
        while (!empty()) pop();
    }

    void Queue::push(int value) {
        if (full()) throw std::overflow_error("Queue is full");

        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
    }

    int Queue::pop() {
        if (empty()) throw std::underflow_error("Queue is empty");

        Node* temp = front;
        int data = temp->data;
        front = front->next;
        if (!front) rear = nullptr;

        delete temp;
        currentSize--;
        return data;
    }

    bool Queue::empty() const {
        return front == nullptr;
    }

    bool Queue::full() const {
        return currentSize >= capacity;
    }
// ---------------- מחסנית (Stack) ----------------
    Stack::Stack() : topNode(nullptr), capacity(INT_MAX), currentSize(0) {}

    Stack::Stack(int size) : topNode(nullptr), capacity(size), currentSize(0) {
        if (size <= 0) throw std::invalid_argument("Stack size must be greater than 0");
    }

    Stack::~Stack() {
        while (!empty()) pop();
    }

    void Stack::push(int value) {
        if (full()) throw std::overflow_error("Stack is full");

        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        currentSize++;
    }

    int Stack::pop() {
        if (empty()) throw std::underflow_error("Stack is empty");

        Node* temp = topNode;
        int data = temp->data;
        topNode = topNode->next;
        delete temp;
        currentSize--;
        return data;
    }

    bool Stack::empty() const {
        return topNode == nullptr;
    }

    bool Stack::full() const {
        return currentSize >= capacity;
    }

// ---------------- תור עדיפויות (Priority Queue) ----------------
    PriorityQueue::PriorityQueue() : head(nullptr), capacity(INT_MAX), currentSize(0) {}

    PriorityQueue::PriorityQueue(int size) : head(nullptr), capacity(size), currentSize(0) {
        if (size <= 0) throw std::invalid_argument("PriorityQueue size must be greater than 0");
    }

    PriorityQueue::~PriorityQueue() {
        while (!empty()) pop();
    }

    void PriorityQueue::push(int value, int priority) {
        if (full()) throw std::overflow_error("PriorityQueue is full");

        Node* newNode = new Node(value, priority);

        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        currentSize++;
    }

    int PriorityQueue::pop() {
        if (empty()) throw std::underflow_error("PriorityQueue is empty");

        Node* temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        currentSize--;
        return data;
    }

    bool PriorityQueue::empty() const {
        return head == nullptr;
    }

    bool PriorityQueue::full() const {
        return currentSize >= capacity;
    }

// ---------------- Union-Find ----------------
UnionFind::UnionFind(int n) : size(n) {
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

int UnionFind::find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void UnionFind::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

} // namespace graph
