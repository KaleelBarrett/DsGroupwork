#include <iostream>
#include <fstream>
#include <string>

int main() {
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
            return 1;
    }

    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        return 1;
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
        std::cout << "Player turn ends. Moving on to the next player." << std::endl;
    }

    return 0;
}
