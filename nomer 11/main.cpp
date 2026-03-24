#include <iostream>
#include "stack_queue.h"

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Stack (LIFO):\n";
    while (!stack.isEmpty())
        std::cout << stack.pop() << "\n";

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue (FIFO):\n";
    while (!queue.isEmpty())
        std::cout << queue.dequeue() << "\n";

    return 0;
}
