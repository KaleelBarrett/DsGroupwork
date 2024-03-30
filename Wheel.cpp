// Wheel.cpp
#include "Wheel.h"

Wheel::Wheel() : currentPosition(0) {
    // Adding 25 cards to the wheel
    for (int i = 0; i < 25; ++i) {
        // Add cards according to your requirements
        CardType type = CardType::Money;
        int value = 500 + rand() % 2001; // Random value between 500 and 2500 for Money cards
        wheel.insert(Card(type, value));
    }
}

void Wheel::spin() {
    currentPosition = (currentPosition + 1) % 25;
}

Card Wheel::getCurrentCard() {
    if (wheel.isEmpty()) {
        std::cerr << "Error: Wheel is empty!" << std::endl;
        // Return a default card or handle the error according to your requirements
        return Card(CardType::Money, 0); // Example of returning a default card
    }

    CardNode* current = wheel.getHead();
    for (int i = 0; i < currentPosition; ++i) {
        current = current->next;
    }
    return current->data;
}
