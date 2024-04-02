// Queue.cpp
#include "header/Queue.h"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr) {}

void Queue::enqueue(char data) {
    QueueNode* newNode = new QueueNode(data);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

char Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty!" << std::endl;
        return '\0'; // Return null character or handle error according to your requirements
    }
    char data = front->data;
    QueueNode* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr; // Reset rear pointer if queue becomes empty
    }
    return data;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::display() const {
    QueueNode* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
