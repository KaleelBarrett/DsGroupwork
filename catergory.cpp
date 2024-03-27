#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::ifstream file;
    std::string question;
    std::string correctAnswer;
    std::string userAnswer;
    std::string answer;

    int choice = 1;

    std::cout << " Select from the following categories" << std::endl;
    std::cout << "1. Person"  << std::endl;
    std::cout << "2. Place"  << std::endl;
    std::cout << "3. Thing"  << std::endl;
    std::cout << "4. Phrase"  << std::endl;

    std::cin >> choice;

    switch (choice) {
        case 1:
            filename = "person.txt";
            file.open(filename);
            if (file.is_open()) {
                std::getline(file, question);
                std::getline(file, answer);
                correctAnswer = answer;
                file.close();
            } else {
                std::cout << "Unable to open file: " << filename << std::endl;
                return 1;
            }
            break;

        case 2:
            filename = "place.txt";
            file.open(filename);
            if (file.is_open()) {
                std::getline(file, question);
                std::getline(file, answer);
                correctAnswer = answer;
                file.close();
            } else {
                std::cout << "Unable to open file: " << filename << std::endl;
                return 1;
            }
            break;

        case 3:
            filename = "thing.txt";
            file.open(filename);
            if (file.is_open()) {
                std::getline(file, question);
                std::getline(file, answer);
                correctAnswer = answer;
                file.close();
            } else {
                std::cout << "Unable to open file: " << filename << std::endl;
                return 1;
            }
            break;

        case 4:
            filename = "phrase.txt";
            file.open(filename);
            if (file.is_open()) {
                std::getline(file, question);
                std::getline(file, answer);
                correctAnswer = answer;
                file.close();
            } else {
                std::cout << "Unable to open file: " << filename << std::endl;
                return 1;
            }
            break;

        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
    }

    std::getline(std::cin, std::string()); // Clear input buffer

    std::cout << question << std::endl;
    std::getline(std::cin, userAnswer);

    if (userAnswer == answer) {
        std::cout << "Correct answer!" << std::endl;
        
    } else {
        std::cout << "Incorrect answer." << std::endl;
        std::cout << "Player turn ends. Moving on to the next player." << std::endl;
    }

    return 0;
}