// CardNode.cpp
#include "header/CardNode.h"

// Constructor
CardNode::CardNode(Card card) : data(card), next(nullptr) {}

// Getter for data
Card CardNode::getData() {
    return data;
}

// Setter for data
void CardNode::setData(Card card) {
    data = card;
}

// Getter for next
CardNode* CardNode::getNext() {
    return next;
}

// Setter for next
void CardNode::setNext(CardNode* nextNode) {
    next = nextNode;
}
