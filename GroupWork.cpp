#include <iostream>
#include <string>
#include "Node.h"
#include "Player.h"



int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Constructor declaration
    Node(Player player) : data(player), next(nullptr) {}
};

// Define a structure to hold a node in the linked list of questions
struct QuestionNode {
    QuestionAnswer data;
    QuestionNode* next;

    // Constructor declaration
    QuestionNode(QuestionAnswer question) : data(question), next(nullptr) {}
};

class Game {
private:
    Node* head;
    Node* tail;
    QuestionNode* questionHead;
    QuestionNode* questionTail;

public:
    Game() : head(nullptr), tail(nullptr), questionHead(nullptr), questionTail(nullptr) {}

    // Function to add players
    void addPlayers() {
        for (int i = 0; i < 4; ++i) {
            string name;
            cout << "Enter name for Player " << i + 1 << ": ";
            cin.ignore(); // Clear input buffer
            getline(cin, name);
            Player newPlayer = { name, i + 1, 0 }; // Player number starts from 1
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

    // Function to load questions and puzzles from a file
    void loadQuestions(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            exit(1);
        }

        while (true) {
            QuestionAnswer question;
            string line;
            if (!getline(file, line)) {
                break;
            }
            if (line[0] == '#') {
                continue;
            }
            istringstream iss(line);
            string type;
            getline(iss, type, ';');
            getline(iss, question.prompt, ';');
            getline(iss, question.answer, ';');
            if (type == "Question") {
                QuestionNode* newNode = new QuestionNode(question);
                if (questionHead == nullptr) {
                    questionHead = newNode;
                    questionTail = newNode;
                }
                else {
                    questionTail->next = newNode;
                    questionTail = newNode;
                }
            }
        }

        file.close();
    }

    void playRound() {
    // Seed the random number generator
    srand(time(nullptr));

    // Select a random question
    int numQuestions = 0;
    QuestionNode* currentQuestion = questionHead;
    while (currentQuestion != nullptr) {
        numQuestions++;
        currentQuestion = currentQuestion->next;
    }
    int random_index = rand() % numQuestions;
    currentQuestion = questionHead;
    for (int i = 0; i < random_index; i++) {
        currentQuestion = currentQuestion->next;
    }

    // Ask the question to all players
    cout << "Question: " << currentQuestion->data.prompt << endl;
    Node* currentPlayer = head;
    for (int i = 0; i < 4; i++) {
        cout << currentPlayer->data.name << ": ";
        string answer;
        getline(cin, answer);
        if (answer == currentQuestion->data.answer) {
            cout << "Correct!" << endl;
            currentPlayer->data.total += 10;
        }
        else {
            cout << "Incorrect." << endl;
        }
        currentPlayer = currentPlayer->next;
    }

    // Move to the next question
    QuestionNode* temp = questionHead;
    questionHead = questionHead->next;
    if (questionHead == nullptr) {
        questionTail = nullptr;
    }
    delete temp; // Delete QuestionNode object
}

    // Function to display player information
    void displayInfo() {
        cout << "\nPlayers Information:" << endl;
        Node* current = head;
        while (current != nullptr) {
            Player* currentPlayer = &current->data;
            cout << "Player " << currentPlayer->number << ": ";
            cout << "Name: " << currentPlayer->name << ", ";
            cout << "Total: " << currentPlayer->total << endl;
            current = current->next;
        }
    }

    // Destructor to free memory allocated for players and questions
    ~Game() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp; // Delete Node object
        }
        QuestionNode* currentQuestion = questionHead;
        while (currentQuestion != nullptr) {
            QuestionNode* temp = currentQuestion;
            currentQuestion = currentQuestion->next;
            delete temp; // Delete QuestionNode object
        }
    }
};

int main() {
    ofstream("questions.txt"); // Create the "questions.txt" file if it doesn't exist
    Game game;
    game.addPlayers();
    game.loadQuestions("questions.txt");

    for (int round = 1; round <= 3; round++) {
        cout << "Round " << round << ":" << endl;
        game.playRound();
    }

    game.displayInfo();

    return 0;

}
