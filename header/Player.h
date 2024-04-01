// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    int playerNumber;
    std::string name;
    int grandTotal; // Total accumulated across all rounds
    int roundTotal; // Total accumulated for the current round
    bool solvedRound; // Flag to indicate if the player has solved the current round

public:
    Player(int playerNumber, const std::string& name);

    // Getters and setters for member variables
    int getPlayerNumber() const;
    const std::string& getName() const;
    int getGrandTotal() const;
    void setGrandTotal(int total);
    int getRoundTotal() const;
    void setRoundTotal(int total);
    bool hasSolvedRound() const;
    void setSolvedRound(bool solved);
};

#endif // PLAYER_H
