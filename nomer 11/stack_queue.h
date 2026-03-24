#pragma once

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List();

    void pushFront(int val);
    void pushBack(int val);
    int popFront();
    int popBack();
    bool isEmpty() const;
};

class Stack {
private:
    List list;

public:
    void push(int val);
    int pop();
    bool isEmpty() const;
};

class Queue {
private:
    List list;

public:
    void enqueue(int val);
    int dequeue();
    bool isEmpty() const;
};