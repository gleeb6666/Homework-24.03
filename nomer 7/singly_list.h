#pragma once

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList();

    void pushBack(int val);
    void print() const;
};

Node* removeAllThrees(Node* head);