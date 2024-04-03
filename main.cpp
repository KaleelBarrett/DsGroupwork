#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "CircularLinkedList.h"
#include <limits> // Include the <limits> header for numeric_limits

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to play the game
void playGame(CircularLinkedList& playersList) {

    // Play 3 rounds
    for (int round = 1; round <= 3; ++round) {
        std::cout << "\nRound " << round << ":\n";

        Node* currentPlayer = playersList.head;
        do {
            std::cout << "\nCurrent Player: " << currentPlayer->playerName << std::endl;

    std::string filename;
    std::ifstream file;
    std::string question;
    std::string correctAnswer;
    std::string userAnswer;

    int choice = 1;

    std::cout << "Select from the following categories:" << std::endl;
    std::cout << "1. Person"  << std::endl;
    std::cout << "2. Place"  << std::endl;
    std::cout << "3. Thing"  << std::endl;
    std::cout << "4. Phrase"  << std::endl;

    std::cin >> choice;

    switch (choice) {
        case 1:
            filename = "person.txt";
            break;

        case 2:
            filename = "place.txt";
            break;

        case 3:
            filename = "thing.txt";
            break;

        case 4:
            filename = "phrase.txt";
            break;

        default:
            std::cout << "Invalid choice." << std::endl;
            return;
    }

    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::getline(file, question);
    std::getline(file, correctAnswer);
    file.close();

    std::cin.ignore(); // Ignore the newline character in the input buffer

    std::cout << question << std::endl;
    std::getline(std::cin, userAnswer);

    if (userAnswer == correctAnswer) {
        std::cout << "Correct answer!" << std::endl;
    } else {
        std::cout << "Incorrect answer." << std::endl;
    }
            currentPlayer = currentPlayer->next;
        } while (currentPlayer != playersList.head);
    }
}

class Player {
public:
    std::string playerName;
    int playerNumber;
    int grandTotal;
};

int main() {
    CircularLinkedList playersList;
    std::string name;
    int playerNumber = 1;

    // Allow up to three players to enter their names and assign player numbers
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter player " << (i + 1) << "'s name: ";
        std::getline(std::cin, name);
        playersList.insertPlayer(name, playerNumber++);
    }

    // Display the list of players
    std::cout << "\nList of Players:\n";
    playersList.displayPlayers();

    // Play the game
    playGame(playersList);

    return 0;
}