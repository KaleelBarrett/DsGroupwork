#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <limits> // Include the <limits> header for numeric_limits
#include <algorithm> // For std::transform
#include "CircularLinkedList.h" // Assuming CircularLinkedList.h contains the declaration of CircularLinkedList

// Define a structure for each card in the puzzle game
struct Card {
    char letter;
    int moneyValue;
};

// Function to clear input buffer
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

// Function to play the puzzle game
int playPuzzleGame(const std::string& fileName, int& totalScore) {
    if (totalScore < 250) {
        std::cout << "Sorry, you need at least 250 points to play the puzzle game." << std::endl;
        return 0; // Return 0 indicating puzzle not played
    }

    // Initialize necessary variables
    std::queue<char> letterQueue;
    std::vector<Card> cards;
    std::string puzzle;
    int roundTotal = 0;

    // Open the file containing puzzle data
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return -1; // Return -1 indicating error
    }

    // Read data from file and populate letterQueue, puzzle, and cards
    char letter;
    int moneyValue;
    while (file >> letter >> moneyValue) {
        letterQueue.push(letter);
        puzzle.push_back(letter);
        cards.push_back({letter, moneyValue});
    }
    file.close();

    // Main loop for playing the puzzle game
    while (!letterQueue.empty()) {
        std::cout << "Enter a letter of the puzzle: ";
        std::cin >> letter;

        bool isLetterInPuzzle = false;
        int occurrences = 0;

        // Check if entered letter exists in the puzzle
        for (size_t i = 0; i < puzzle.length(); ++i) {
            if (puzzle[i] == letter) {
                isLetterInPuzzle = true;
                ++occurrences;
                puzzle[i] = '_';
                roundTotal += cards[i].moneyValue;
            }
        }

        // Display result of letter search
        if (isLetterInPuzzle) {
            std::cout << "Letter found! It appears " << occurrences << " times in the puzzle." << std::endl;
            std::cout << "Your round total is now: " << (totalScore += roundTotal) << std::endl;
        } else {
            std::cout << "Letter not found." << std::endl;
        }

        letterQueue.pop();
    }

    return roundTotal; // Return round total
}

// Function to play the main game
void playGame(CircularLinkedList& playersList ) {
    // Play 3 rounds
    for (int round = 1; round <= 3; ++round) {
        std::cout << "\nRound " << round << ":\n";

        // Iterate through players in the circular linked list
        Node* currentPlayer = playersList.head;
        do {
            std::cout << "\nCurrent Player: " << currentPlayer->playerName << std::endl;

            // Get player's total score
            int totalScore = currentPlayer->grandTotal;
            std::cout << "Player's Grand Total: " << totalScore << std::endl;

            // Initialize variables for file I/O and quiz questions
            std::string filename;
            std::ifstream file;
            std::string question;
            std::string correctAnswer;
            std::string userAnswer;

            // Display menu to select category
            int choice = 1;
            std::cout << "Select from the following categories:" << std::endl;
            std::cout << "1. Person"  << std::endl;
            std::cout << "2. Place"  << std::endl;
            std::cout << "3. Thing"  << std::endl;
            std::cout << "4. Phrase"  << std::endl;
            std::cout << "5. End game" << std::endl;
            std::cin >> choice;

            // Clear input buffer
            clearInputBuffer();

            switch (choice) {
                // Set filename based on user choice
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

                case 5:
                    return;

                default:
                    std::cout << "Invalid choice." << std::endl;
                    return;
            }

            // Prompt user to attempt puzzle or answer quiz question
            std::cout << "Would you like to attempt a puzzle? (yes/no): ";
            std::string attemptPuzzle;
            std::cin >> attemptPuzzle;
            clearInputBuffer();

            if (toLowercase(attemptPuzzle) == "yes") {
                // Play puzzle game
                std::string puzzleFileName = "puzzle.txt";
                int puzzleTotal = playPuzzleGame(puzzleFileName, totalScore);
                if (puzzleTotal != -1) {
                    totalScore += puzzleTotal;
                } else {
                    std::cout << "Puzzle game couldn't be played. Error occurred." << std::endl;
                }
            } else {
                // Load and display quiz question
                file.open(filename);
                if (!file.is_open()) {
                    std::cout << "Unable to open file: " << filename << std::endl;
                    return;
                }

                // Read questions and answers from file
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

                // Ask user for answer
                std::cout << question << std::endl;
                std::getline(std::cin, userAnswer);

                // Convert user's answer and correct answer to lowercase
                std::string userAnswerLower = toLowercase(userAnswer);
                std::string correctAnswerLower = toLowercase(correctAnswer);

                // Check if answer is correct
                if (userAnswerLower == correctAnswerLower) {
                    std::cout << "Correct answer!" << std::endl;
                } else {
                    std::cout << "Incorrect answer." << std::endl;
                }
            }

            // Display player's total score after the round
            std::cout << "Player's Grand Total after Round " << round << ": " << (currentPlayer->grandTotal = totalScore) << std::endl;

            // Move to the next player
            currentPlayer = currentPlayer->next;
        } while (currentPlayer != playersList.head);
    }
}

// Player class representing a player in the game
class Player {
public:
    std::string playerName;
    int playerNumber;
    int grandTotal;
};

// Main function
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

    // Display the list of players with their final scores
    std::cout << "\nList of Players:\n";
    playersList.displayPlayers();

    return 0;
}
