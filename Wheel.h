// Wheel.h
#pragma once

#ifndef WHEEL_H
#define WHEEL_H

#include <cstdlib> // For rand()
#include <random>

#include "CircularLinkedList.h"

class Wheel {
private:
    CircularLinkedList wheel;
    int currentPosition;
    std::mt19937 rng; // Mersenne Twister random number generator

public:
    Wheel();

    void spin();

    Card getCurrentCard();

};

#endif // WHEEL_H


