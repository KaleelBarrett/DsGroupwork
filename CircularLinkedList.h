// CircularLinkedList.h
#pragma once

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include "CardNode.h"

class CircularLinkedList {
private:
    CardNode* head;
    CardNode* tail;

public:
    CircularLinkedList();

    bool isEmpty() const;

    void insert(Card card);

    void display();
};

#endif // CIRCULAR_LINKED_LIST_H

