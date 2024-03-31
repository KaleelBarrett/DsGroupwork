#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
#include "Node.h"
#include "PlayerCircularLinkedList.h"
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

void playGame(const std::string& category) {
    Category categoryObj;
    categoryObj.getCategory();
    std::string categoryString = categoryObj.getCategoryString();

    int numPlayers = 3;

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
        } else {
            std::cout << "Incorrect answer." << std::endl;
            std::cout << "Player turn ends. Moving on to the next player." << std::endl;
        }
    }

    std::cout << "Game over!" << std::endl;
}

int main(){
    PlayerList playerList;
    enterPlayerNames(playerList);

    Category categoryObj;
    categoryObj.getCategory();
    std::string c = categoryObj.getCategoryString();

    playGame(c);

    return 0;
}