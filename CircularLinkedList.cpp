// CircularLinkedList.cpp
#include "header/CircularLinkedList.h" // Include the header file where CircularLinkedList class is declared
#include <iostream>

// Constructor for CircularLinkedList class
CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr) {}

// Function to check if the list is empty
bool CircularLinkedList::isEmpty(){
    return head == nullptr; // Returns true if head is nullptr, indicating an empty list
}

// Function to insert a new card node into the circular linked list
void CircularLinkedList::insert(Card card) {
    CardNode* newNode = new CardNode(card); // Create a new CardNode with the provided card data
    if (isEmpty()) {
        head = newNode; // If the list is empty, set both head and tail to the new node
        tail = newNode;
        tail->next = head; // Circular link: make the next of tail point back to head
    } else {
        tail->next = newNode; // If the list is not empty, add the new node after the tail
        tail = newNode; // Update tail to the new node
        tail->next = head; // Circular link: make the next of tail point back to head
    }
}

// Function to display the contents of the circular linked list
void CircularLinkedList::display() {
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl; // If the list is empty, print a message and return
        return;
    }

    CardNode* current = head; // Start from the head of the list
    do {
        std::cout << "Type: ";
        switch (current->getData().getType()) { // Print the type of card
            case CardType::Money:
                std::cout << "Money";
                break;
            case CardType::LoseATurn:
                std::cout << "Lose a Turn";
                break;
            case CardType::Bankruptcy:
                std::cout << "Bankruptcy";
                break;
        }
        std::cout << ", Value: " << current->getData().getValue() << std::endl; // Print the value of the card
        current = current->next; // Move to the next node
    } while (current != head); // Continue until we reach the head again
}

// Function to get the head of the circular linked list
CardNode* CircularLinkedList::getHead(){
    return head; // Return the head pointer
}
