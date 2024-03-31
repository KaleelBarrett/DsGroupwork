// main.cpp
#include <iostream>
#include "Wheel.h"


int main() {
    // Create a Wheel object
    Wheel wheel;

    // Spin the wheel a few times and display the current card
    for (int i = 0; i < 5; ++i) {
        wheel.spin();
        Card currentCard = wheel.getCurrentCard();
        std::cout << "Current Card Type: " << currentCard.getTypeString() << ", Value: " << currentCard.getValue() << std::endl;
    }

    return 0;
}
