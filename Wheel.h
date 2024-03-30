// Wheel.h
#pragma once

#ifndef WHEEL_H
#define WHEEL_H

#include <cstdlib> // For rand()

#include "CircularLinkedList.h"

class Wheel {
private:
    CircularLinkedList wheel;
    int currentPosition;

public:
    Wheel();

    void spin();

    Card getCurrentCard();
};

#endif // WHEEL_H


