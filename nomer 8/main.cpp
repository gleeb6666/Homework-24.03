#include <iostream>
#include "doubly_list.h"

int main() {
    DoublyLinkedList list;
    int values[] = { 5, 3, 8, 1, 9, 2, 7, 4, 6 };
    for (int v : values) list.pushBack(v);

    std::cout << "Initial: ";
    list.print();

    bubbleSort(list.head);

    std::cout << "Sorted:  ";
    list.print();

    return 0;
}
