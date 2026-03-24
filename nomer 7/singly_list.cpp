#include "singly_list.h"
#include <iostream>

SinglyLinkedList::~SinglyLinkedList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void SinglyLinkedList::pushBack(int val) {
    Node* node = new Node(val);
    if (!head) {
        head = node;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

void SinglyLinkedList::print() const {
    for (Node* cur = head; cur; cur = cur->next)
        std::cout << cur->value << (cur->next ? " -> " : "\n");
    if (!head) std::cout << "(empty)\n";
}

Node* removeAllThrees(Node* head) {
    while (head && head->value == 3) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->value == 3) {
            Node* toDelete = cur->next;
            cur->next = toDelete->next;
            delete toDelete;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}