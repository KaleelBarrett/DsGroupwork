// Player.cpp
#include "header/Player.h"

Player::Player(int playerNumber, const std::string& name)
    : playerNumber(playerNumber), name(name), grandTotal(0), roundTotal(0), solvedRound(false) {}

int Player::getPlayerNumber() const {
    return playerNumber;
}

const std::string& Player::getName() const {
    return name;
}

int Player::getGrandTotal() const {
    return grandTotal;
}

void Player::setGrandTotal(int total) {
    grandTotal = total;
}

int Player::getRoundTotal() const {
    return roundTotal;
}

void Player::setRoundTotal(int total) {
    roundTotal = total;
}

bool Player::hasSolvedRound() const {
    return solvedRound;
}

void Player::setSolvedRound(bool solved) {
    solvedRound = solved;
}
