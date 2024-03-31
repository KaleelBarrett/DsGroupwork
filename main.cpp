#include <iostream>
#include "header/Wheel.h"

void displayMenu() {
    std::cout << "Welcome to Spin the Wheel Game!" << std::endl;
    std::cout << "1. Spin the wheel" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Wheel wheel;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Spinning the wheel..." << std::endl;
                wheel.spin();
                Card currentCard = wheel.getCurrentCard();
                std::cout << "You landed on ";
                switch (currentCard.getType()) {
                    case CardType::Money:
                        std::cout << "Money: $" << currentCard.getValue() << std::endl;
                        break;
                    case CardType::LoseATurn:
                        std::cout << "Lose a Turn" << std::endl;
                        break;
                    case CardType::Bankruptcy:
                        std::cout << "Bankruptcy" << std::endl;
                        break;
                }
                break;
            }
            case 2:
                std::cout << "Quitting the game. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 2);

    return 0;
}
