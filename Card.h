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
    Card(CardType type, int value) : type(type), value(value) {}

    CardType getType() const {
        return type;
    }

    int getValue() const {
        return value;
    }

    std::string getTypeString() const {
        switch (type) {
            case CardType::Money: return "Money";
            case CardType::LoseATurn: return "Lose a Turn";
            case CardType::Bankruptcy: return "Bankruptcy";
        }
        return "Unknown";
    }
};
