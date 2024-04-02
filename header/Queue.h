// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"

class Queue {
private:
    
    QueueNode* rear;

public:
    QueueNode* front;
    Queue();

    void enqueue(char data);
    char dequeue();
    bool isEmpty() const;
    void display() const;
};

#endif // QUEUE_H
