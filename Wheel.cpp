// Wheel.cpp
#include "header/Wheel.h"

Wheel::Wheel() : currentPosition(0) {
    // Adding 25 cards to the wheel
    for (int i = 0; i < 25; ++i) {
        CardType type;
        int value;
        
        // Assign card type and value based on requirements
        if (i % 5 == 0) {
            type = CardType::LoseATurn;
            value = 0; // Value of Lose a Turn card
        } else if (i % 7 == 0 || i % 11 == 0) {
            type = CardType::Bankruptcy;
            value = 0; // Value of Bankruptcy card
        } else {
            type = CardType::Money;
            value = 500 + rand() % 2001; // Random value between 500 and 2500 for Money cards
        }

        // Insert the card into the wheel
        wheel.insert(Card(type, value));
    }
}


void Wheel::spin() {
    std::uniform_int_distribution<int> dist(50, 100); // Uniform distribution between 50 and 100
    int randomNumber = dist(rng); // Generate random number
    currentPosition = (currentPosition + randomNumber) % 25; // Move current position

    // Get the current card after spinning
    Card currentCard = getCurrentCard();
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
