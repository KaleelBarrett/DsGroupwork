#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include <string>

struct Node {
    std::string playerName;
    int playerNumber;
    int grandTotal;
    Node* next;

    Node(std::string name, int number) : playerName(name), playerNumber(number), grandTotal(0), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;
    int count;

    CircularLinkedList();
    ~CircularLinkedList();

    void insertPlayer(std::string name, int number);
    void displayPlayers();
    int getCount();
    void play(const std::string& categoryFile);
};

#endif // CIRCULARLINKEDLIST_H