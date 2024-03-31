#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
#include "Node.h"
#include "PlayerCircularLinkedList.h"
#include "CircularLinkedList.h"
#include "Wheel.h"

void enterPlayerNames(PlayerList& playerList) {
    int playerNumber = 1;
    for (int i = 1; i <= 3; i++) {
        std::string firstName, lastName;
        std::cout << "Enter player " << i << " information:\n";
        std::cout << "First name: ";
        std::cin >> firstName;
        std::cout << "Last name: ";
        std::cin >> lastName;
        Player newPlayer(playerNumber, firstName, lastName);
        playerList.insert(newPlayer);
        playerNumber++;
    }
}

class Category {
public:
    void getCategory() {
        std::cout << " Select from the following categories\n";
        std::cout << "1. Person  \n";
        std::cout << "2. Place  \n";
        std::cout << "3. Thing  \n";
        std::cout << "4. Phrase  \n";

        std::cin >> choice;

        while (choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Please choose a number between 1 and 4." << std::endl;
            std::cin >> choice;
        }
    }

    std::string getCategoryString() {
        std::string category;
        switch (choice) {
            case 1:
                category = "person";
                break;
            case 2:
                category = "place";
                break;
            case 3:
                category = "thing";
                break;
            case 4:
                category = "phrase";
                break;
        }

        return category;
    }

private:
    int choice;
};

void playGame(PlayerList& playerList) {
    Category categoryObj;
    categoryObj.getCategory();
    std::string categoryString = categoryObj.getCategoryString();

    Wheel wheelObj;

    Player currentPlayer;
    for (int i = 0; i < 3; i++) {
        std::ifstream file(categoryString + ".txt");
        if (!file.is_open()) {
            std::cout << "Unable to open file for category: " << categoryString << std::endl;
            return;
        }

        std::string question;
        std::string correctAnswer;
        std::getline(file, question);
        std::getline(file, correctAnswer);
        file.close();

        std::cout << question << std::endl;
        std::string userAnswer;
        std::getline(std::cin, userAnswer);

        if (userAnswer == correctAnswer) {
            std::cout << "Correct answer!" << std::endl;

            // Spin the wheel and add the value of the card to the player's grand total
            wheelObj.spin();
            Card currentCard = wheelObj.getCurrentCard();
            int cardValue = currentCard.getValue();
            currentPlayer.SetGrandTotal(cardValue);
            std::cout << "Player " << i+1 << " wins " << cardValue << " dollars!" << std::endl;
        } else {
            std::cout << "Incorrect answer." << std::endl;
            std::cout << "Player turn ends. Moving on to the next player." << std::endl;
        }
    }

    // Add the current player to the player list
    playerList.insert(currentPlayer);

    std::cout << "Game over!" << std::endl;
    std::cout << "Player grand totals: " << std::endl;
    
}

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
    std::uniform_int_distribution<int> dist(50, 100); // Uniform distribution between 50 and 100
    int randomNumber = dist(rng); // Generate random number
    currentPosition = (currentPosition + randomNumber) % 25; // Move current position
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

int main(){
    PlayerList playerList;
    enterPlayerNames(playerList);

    Category categoryObj;
    categoryObj.getCategory();
    std::string c = categoryObj.getCategoryString();

    playGame(playerList);

    return 0;
}