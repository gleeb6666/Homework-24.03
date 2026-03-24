#include "list.h"
#include <iostream>
#include <stdexcept>

DoublyLinkedList::~DoublyLinkedList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void DoublyLinkedList::pushBack(int val) {
    Node* node = new Node(val);
    if (!head) {
        head = node;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    node->prev = cur;
}

void DoublyLinkedList::print() const {
    for (Node* cur = head; cur; cur = cur->next)
        std::cout << cur->value << (cur->next ? " <-> " : "\n");
    if (!head) std::cout << "(empty)\n";
}

Node* swapAdjacent(Node* head, Node* first) {
    if (!first || !first->next)
        throw std::invalid_argument("node has no successor");

    Node* second = first->next;

    if (first->prev)
        first->prev->next = second;
    if (second->next)
        second->next->prev = first;

    second->prev = first->prev;
    first->next = second->next;
    second->next = first;
    first->prev = second;

    return (second->prev == nullptr) ? second : head;
}

Node* swapNodes(Node* head, Node* node1, Node* node2) {
    if (!node1 || !node2 || node1 == node2) return head;

    if (node1->next == node2) return swapAdjacent(head, node1);
    if (node2->next == node1) return swapAdjacent(head, node2);

    Node* prev1 = node1->prev;
    Node* next1 = node1->next;
    Node* prev2 = node2->prev;
    Node* next2 = node2->next;

    if (prev1) prev1->next = node2;
    if (next1) next1->prev = node2;
    if (prev2) prev2->next = node1;
    if (next2) next2->prev = node1;

    node2->prev = prev1;
    node2->next = next1;
    node1->prev = prev2;
    node1->next = next2;

    if (head == node1) return node2;
    if (head == node2) return node1;
    return head;
}