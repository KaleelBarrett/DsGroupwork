#include "Player.h"

Player::Player() {
    playerNumber = 0;
    fName = " ";
    lName = " ";
    grandTotal = 0;
}

Player::Player(int playerNumber, string fName, string lName)
    : playerNumber(playerNumber), fName(fName), lName(lName), grandTotal(0) {}

void Player::SetPlayerNumber(int playerNumber) {
    this->playerNumber = playerNumber;
}

int Player::GetPlayerNumber() {
    return playerNumber;
}

void Player::SetName(string fName) {
    this->fName = fName;
}

string Player::GetName() {
    return fName;
}

void Player::SetScore(int grandTotal) {
    this->grandTotal = grandTotal;
}

int Player::GetScore() {
    return grandTotal;
}