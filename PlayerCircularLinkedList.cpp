#include "header/PlayerCircularLinkedList.h"

PlayerCircularLinkedList::PlayerCircularLinkedList() : head(nullptr), count(0) {
    head = nullptr;
}

PlayerCircularLinkedList::~PlayerCircularLinkedList() {
    Node* current = head;
    Node* temp;
    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void PlayerCircularLinkedList::insertPlayer(std::string name, int number) {
    Node* newNode = new Node(name, number);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    count++;
}

void PlayerCircularLinkedList::displayPlayers() {
    if (head == nullptr) {
        std::cout << "No players in the list!" << std::endl;
        return;
    }

    Node* temp = head;
    do {
        std::cout << "Player Name: " << temp->playerName << ", Player Number: " << temp->playerNumber << ", Grand Total: $" << temp->grandTotal << std::endl;
        temp = temp->next;
    } while (temp != head);
}

int PlayerCircularLinkedList::getCount() {
    return count;
}

void PlayerCircularLinkedList::play(const std::string& categoryFile) {
    // Your code here
}