#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

enum class CardType {
    Money,
    LoseATurn,
    Bankruptcy
};

class Card {
private:
    CardType type;
    int value;

public:
    Card(CardType type, int value);

    CardType getType() const;

    int getValue() const;
};

#endif // CARD_H
