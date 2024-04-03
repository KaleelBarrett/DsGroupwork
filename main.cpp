#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "CircularLinkedList.h"
#include <limits> // Include the <limits> header for numeric_limits
#include <algorithm> // For std::transform
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()




void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to convert string to lowercase
std::string toLowercase(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
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
    
    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
            return ;
    }

    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        return ;
    }

    std::vector<std::string> questions;
    while (std::getline(file, question)) {
        std::getline(file, correctAnswer); // Read the corresponding answer (assuming questions and answers are stored alternately)
        questions.push_back(question);
    }
    file.close();

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Randomly select a question
    int randomIndex = std::rand() % questions.size();
    question = questions[randomIndex];

    std::cout << question << std::endl;
    std::getline(std::cin, userAnswer);

    // Convert user's answer and correct answer to lowercase
    std::string userAnswerLower = toLowercase(userAnswer);
    std::string correctAnswerLower = toLowercase(correctAnswer);

    if (userAnswerLower == correctAnswerLower) {
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