#include "stack_queue.h"
#include <stdexcept>

List::~List() {
    while (!isEmpty()) popFront();
}

void List::pushFront(int val) {
    Node* node = new Node(val);
    node->next = head;
    head = node;
    if (!tail) tail = head;
    size++;
}

void List::pushBack(int val) {
    Node* node = new Node(val);
    if (!tail) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    size++;
}

int List::popFront() {
    if (!head) throw std::underflow_error("list is empty");
    Node* toDelete = head;
    int val = toDelete->value;
    head = head->next;
    if (!head) tail = nullptr;
    delete toDelete;
    size--;
    return val;
}

int List::popBack() {
    if (!head) throw std::underflow_error("list is empty");
    int val;
    if (head == tail) {
        val = head->value;
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* cur = head;
        while (cur->next != tail) cur = cur->next;
        val = tail->value;
        delete tail;
        tail = cur;
        tail->next = nullptr;
    }
    size--;
    return val;
}

bool List::isEmpty() const {
    return head == nullptr;
}

void Stack::push(int val) {
    list.pushFront(val);
}

int Stack::pop() {
    return list.popFront();
}

bool Stack::isEmpty() const {
    return list.isEmpty();
}

void Queue::enqueue(int val) {
    list.pushBack(val);
}

int Queue::dequeue() {
    return list.popFront();
}

bool Queue::isEmpty() const {
    return list.isEmpty();
}