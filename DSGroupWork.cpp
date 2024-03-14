#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()

using namespace std;

// Define a structure to hold question-answer pairs
struct QuestionAnswer {
    string question;
    string answer;
};

class Player {
private:
    string Playername;
    int playernum;
    float grandtotal;

public:
    // Constructor declaration
    Player(string name, int num, float total) : Playername(name), playernum(num), grandtotal(total) {}

    // Getter function for Players name
    string getName() {
        return Playername;
    }
    // Getter function for player num
    int getNumber() {
        return playernum;
    }
    // getter function for grand total points for the player
    float getTotal() {
        return grandtotal;
    }

    // Function to update total
    void updateTotal(float points) {
        grandtotal += points;
    }
};

class Node {
public:
    Player* data;
    Node* next;

    // Constructor declaration
    Node(Player* player) : data(player), next(nullptr) {}
};

class Game {
private:
    Node* head;
    Node* tail;

public:
    Game() : head(nullptr), tail(nullptr) {}

    // Function toadd players
    void info() {
        for (int i = 0; i < 4; ++i) {
            string name;
            cout << "Enter name for Player " << i + 1 << ": ";
            cin.ignore(); // Clear input buffer
            getline(cin, name);
            Player* newPlayer = new Player(name, i + 1, 0); // Player number starts from 1
            Node* newNode = new Node(newPlayer);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    // Function to display player information
    void displayInfo() {
        cout << "\nPlayers Information:" << endl;
        Node* current = head;
        while (current != nullptr) {
            Player* currentPlayer = current->data;
            cout << "Player " << currentPlayer->getNumber() << ": ";
            cout << "Name: " << currentPlayer->getName() << ", ";
            cout << "Total: " << currentPlayer->getTotal() << endl;
            current = current->next;
        }
    }

    // Destructor to free memory allocated for players
    ~Game() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp->data; // Delete Player object
            delete temp; // Delete Node object
        }
    }
};

int main() {
    Game game;
    game.info();
    game.displayInfo();

    return 0;
}
