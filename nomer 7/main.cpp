#include <iostream>
#include "singly_list.h"

int main() {
    SinglyLinkedList list;
    int values[] = { 3, 1, 3, 3, 2, 3, 4, 3 };
    for (int v : values) list.pushBack(v);

    std::cout << "Initial: ";
    list.print();

    list.head = removeAllThrees(list.head);

    std::cout << "After:   ";
    list.print();

    return 0;
}
