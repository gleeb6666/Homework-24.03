#pragma once

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList();

    void pushBack(int val);
    void print() const;
};

void bubbleSort(Node* head);