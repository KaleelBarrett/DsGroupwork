#include "header/Card.h"

// Constructor definition
Card::Card(CardType type, int value) : type(type), value(value) {}

// Getter method for type
CardType Card::getType() const {
    return type;
}

// Getter method for value
int Card::getValue() const {
    return value;
}
