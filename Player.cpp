#include "header/Player.h"

Player::Player() : playerNumber(0), fName(" "), lName(" "), grandTotal(0) {}

Player::Player(int playerNumber, const std::string& fName, const std::string& lName) 
    : playerNumber(playerNumber), fName(fName), lName(lName), grandTotal(0) {}

void Player::setPlayerNumber(int playerNumber) {
    this->playerNumber = playerNumber;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

void Player::setFName(const std::string& fName) {
    this->fName = fName;
}

const std::string& Player::getFName() const {
    return fName;
}

void Player::setLName(const std::string& lName) {
    this->lName = lName;
}

const std::string& Player::getLName() const {
    return lName;
}

void Player::setGrandTotal(int grandTotal) {
    this->grandTotal = grandTotal;
}

int Player::getGrandTotal() const {
    return grandTotal;
}
