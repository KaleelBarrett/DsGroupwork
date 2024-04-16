#ifndef PLAYERCIRCULARLINKEDLIST_H
#define PLAYERCIRCULARLINKEDLIST_H

#include <iostream>
#include <string>

struct Node {
    std::string playerName;
    int playerNumber;
    int grandTotal;
    Node* next;
    Node* previous;

    Node(std::string name, int number) : playerName(name), playerNumber(number), grandTotal(0), next(nullptr) {}
};

class PlayerCircularLinkedList {
public:
    Node* head;
    int count;

    PlayerCircularLinkedList();
    ~PlayerCircularLinkedList();

    void insertPlayer(std::string name, int number);
    void displayPlayers();
    int getCount();
    void play(const std::string& categoryFile);
};

#endif // PLAYERCIRCULARLINKEDLIST_H
