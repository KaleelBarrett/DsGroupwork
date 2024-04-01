// LetterTracker.h
#ifndef LETTERTRACKER_H
#define LETTERTRACKER_H

#include "header/Queue.h"

class LetterTracker {
private:
    Queue guessedLetters;

public:
    void addGuessedLetter(char letter);
    void displayGuessedLetters() const;
    bool isLetterGuessed(char letter) const;
};

#endif // LETTERTRACKER_H
