// CardNode.h
#pragma once

#ifndef CARDNODE_H
#define CARDNODE_H

#include "Card.h"

class CardNode {
public:
    Card data;
    CardNode* next;

    CardNode(Card card);
};

#endif // CARDNODE_H
