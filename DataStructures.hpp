//israelmor555@gmail.com
#pragma once

namespace graph {

    class Queue {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int d) : data(d), next(nullptr) {}
        };

        Node *front, *rear;
        int capacity;
        int currentSize;

    public:
        Queue(int size);
        Queue();
        ~Queue();

        void push(int value);
        int pop();
        bool empty() const;
        bool full() const;
    };
//////////////////////////////////////////////////////////////////////
    class Stack {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int d) : data(d), next(nullptr) {}
        };

        Node* topNode;
        int capacity;
        int currentSize;

    public:
        Stack();
        Stack(int size);
        ~Stack();

        void push(int value);
        int pop();
        bool empty() const;
        bool full() const;
    };

////////////////////////////////////////////////////////////////////////
    class PriorityQueue {
    private:
        struct Node {
            int data;
            int priority;
            Node* next;
            Node(int d, int p) : data(d), priority(p), next(nullptr) {}
        };

        Node* head;
        int capacity;
        int currentSize;

    public:
        PriorityQueue();
        PriorityQueue(int size);
        ~PriorityQueue();

        void push(int value, int priority);
        int pop();
        bool empty() const;
        bool full() const;
    };
    ////////////////////////////////////////////////////////////////////////
    class UnionFind {
    private:
        int* parent;
        int* rank;
        int size;
    public:
        UnionFind(int n);
        ~UnionFind();
        int find(int v);
        void unite(int u, int v);
    };

} // namespace graph
