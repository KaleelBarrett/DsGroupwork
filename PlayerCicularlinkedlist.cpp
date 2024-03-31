#pragma once

#include <iostream>
#include "Player.h"

class PlayerList {

private:
    int numPlayers;
    Player* players;
    int capacity;

public:

    PlayerList(int capacity)
        : numPlayers(0), players(new Player[capacity]), capacity(capacity) {}

    PlayerList(const PlayerList& other)
        : numPlayers(other.numPlayers), players(new Player[other.capacity]), capacity(other.capacity) {
        for (int i = 0; i < numPlayers; i++) {
            players[i] = other.players[i];
        }
    }

    ~PlayerList() {
        delete[] players;
    }

    void addPlayer(Player player) {
        if (numPlayers >= capacity) {
            throw std::runtime_error("PlayerList is full");
        }

        players[numPlayers++] = player;
    }

    Player& getPlayer(int index) {
        if (index < 0 || index >= numPlayers) {
            throw std::out_of_range("Index out of range");
        }

        return players[index];
    }

    int numPlayers() {
        return numPlayers;
    }

    void display() {
        for (int i = 0; i < numPlayers; i++) {
            Player player = getPlayer(i);
            std::cout << "Player " << player.GetPlayerNumber()
                << ": " << player.GetName()
                << " - Grand Total: " << player.GetScore()
                << std::endl;
        }
    }
};