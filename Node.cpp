#include "Node.h"
#include "player.h"

Node::Node(Player data, Node* nextNode)
    : data(data), nextNode(nextNode) {}

void Node::display() {
    cout << "Player Name: " << data.GetName() << ", Score: " << data.GetScore() << endl;
    if (nextNode != nullptr) {
        nextNode->display();
    }
}