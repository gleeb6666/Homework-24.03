#include <iostream>
#include "list.h"

int main() {
    DoublyLinkedList list;
    for (int i = 1; i <= 5; i++) list.pushBack(i);

    std::cout << "Initial:       ";
    list.print();

    Node* node2 = list.head->next;
    list.head = swapAdjacent(list.head, node2);
    std::cout << "After 5a (swap node[2] with node[3]): ";
    list.print();

    Node* n1 = list.head;
    Node* n4 = list.head->next->next->next;
    list.head = swapNodes(list.head, n1, n4);
    std::cout << "After 5b (swap node[1] with node[4]): ";
    list.print();

    return 0;
}
