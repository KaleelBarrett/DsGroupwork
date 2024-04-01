#include "header/Player.h"
#include "header/Wheel.h"
#include <iostream>
#include <vector>

int main() {
    // Initialize players
    std::vector<Player> players;
    players.push_back(Player(1, "Player 1"));
    players.push_back(Player(2, "Player 2"));
    // Add more players if needed

    // Initialize wheel
    Wheel wheel;

    // Main game loop
    int currentRound = 1;
    const int totalRounds = 3;
    while (currentRound <= totalRounds) {
        std::cout << "Round " << currentRound << std::endl;

        // Iterate through each player's turn
        for (Player& player : players) {
            std::cout << "Current player: " << player.getName() << std::endl;

            // Spin the wheel
            wheel.spin();

            // Display the wheel result
            Card currentCard = wheel.getCurrentCard();
            std::cout << "Current wheel card: Type - " << static_cast<int>(currentCard.getType())
                      << ", Value - " << currentCard.getValue() << std::endl;

            // Your game logic for handling player's turn goes here
            // Allow the player to guess a letter, solve the puzzle, etc.

            // Update player's round total based on outcome
            // player.setRoundTotal(player.getRoundTotal() + ...);

            // Check if the player has solved the puzzle
            // if (player.hasSolvedPuzzle()) { ... }

            // Handle special wheel tiles (Bankrupt, Lose A Turn)
            // if (currentCard.getType() == CardType::Bankruptcy) { ... }
            // else if (currentCard.getType() == CardType::LoseATurn) { ... }

            // Move to the next player
        }

        // Display round results and update grand totals
        // Your code for displaying round results and updating grand totals goes here

        // Check if the game should continue
        // if (gameShouldContinue()) { ... }

        currentRound++;
    }

    // End of game
    // Your code for determining the winner and displaying final results goes here

    return 0;
}
