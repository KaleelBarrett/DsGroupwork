// LetterTracker.cpp
#include "header/LetterTracker.h"

void LetterTracker::addGuessedLetter(char letter) {
    guessedLetters.enqueue(letter);
}

void LetterTracker::displayGuessedLetters() const {
    guessedLetters.display();
}

bool LetterTracker::isLetterGuessed(char letter) const {
    // Check if the letter is in the guessed letters queue
    QueueNode* current = guessedLetters.front;
    while (current != nullptr) {
        if (current->data == letter) {
            return true;
        }
        current = current->next;
    }
    return false;
}
