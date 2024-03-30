// CardNode.h
// CardNode.h
#ifndef CARDNODE_H
#define CARDNODE_H

#include "Card.h"

class CardNode {
public:
    Card data;
    CardNode* next;

    CardNode(Card card);

    // Getter for data
    Card getData() const;

    // Setter for data
    void setData(Card card);

    // Getter for next
    CardNode* getNext() const;

    // Setter for next
    void setNext(CardNode* nextNode);
};

#endif // CARDNODE_H
