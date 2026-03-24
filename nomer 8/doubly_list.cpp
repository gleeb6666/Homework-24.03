#include "doubly_list.h"
#include <iostream>

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

void bubbleSort(Node* head) {
    if (!head) return;

    bool swapped;
    do {
        swapped = false;
        Node* cur = head;
        while (cur->next) {
            if (cur->value > cur->next->value) {
                int tmp = cur->value;
                cur->value = cur->next->value;
                cur->next->value = tmp;
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}