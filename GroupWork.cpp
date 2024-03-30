#include <iostream>
#include <string>
#include "Node.h"
#include "Player.h"



int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Create three player objects
    Player players[3];
    std::string playerName;

    // Get player names
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter name for Player "  << i + 1 << ": ";
        std::cin >> playerName;
        players[i] = Player(i + 1, playerName, "");
    }

 // Create nodes for each player and add them to the circular linked list
    for (int i = 0; i < 3; ++i) {
        Node* newNode = new Node(players[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->setNextNode(head); // Point back to the head to make it circular
        } else {
            tail->setNextNode(newNode);
            tail = newNode;
            tail->setNextNode(head); // Point back to the head to make it circular
        }
    }

    // Traverse the circular linked list and display player details
    Node* currentNode = head;
    do {
        currentNode->display();
        currentNode = currentNode->getNextNode();
    } while (currentNode != head);

    // Clean up memory
    currentNode = head;
    do {
        Node* temp = currentNode;
        currentNode = currentNode->getNextNode();
        delete temp;
    } while (currentNode != head);

    return 0;

}
