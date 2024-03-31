// CircularLinkedList.cpp
#include "CircularLinkedList.h"
#include <iostream>

CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    // Implement destructor to free memory if needed
}

bool CircularLinkedList::isEmpty(){
    return head == nullptr;
}

void CircularLinkedList::insert(Card card) {
    CardNode* newNode = new CardNode(card);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        tail->next = head; // Circular link
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // Circular link
    }
}

void CircularLinkedList::display() {
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    CardNode* current = head;
    do {
        std::cout << "Type: " << current->getData().getTypeString() << ", Value: " << current->getData().getValue() << std::endl;
        current = current->next;
    } while (current != head);
}

CardNode* CircularLinkedList::getHead(){
    return head;
}
