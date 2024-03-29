#pragma once

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Player.h"
using namespace std;

class Node{

private:
	Player data;
	Node* nextNode;
	//Node* prevNode;

public:

	Node() {
		data;
		nextNode = NULL;
		//prevNode = NULL;
	}

	Node* getNextNode() {

		return nextNode;
	}

	void setNextNode(Node* nextNode) {
		this->nextNode = nextNode;
	}

	/*Node* getPrevNode() {
		return prevNode;
	}

	void setPrevNode(Node* prevNode) {
		this->prevNode = prevNode;
	}*/

	Player getData() {
		return data;
	}

	void setData(Player pbj) {
		this->data = data;
	}

};

#endif