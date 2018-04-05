/*
 * File: Pet.hpp
 * Description: Abstraction of class Snail
 * Author :
 * Version :
 * USAGE : #include "Pet.hpp"
*/

#ifndef PET_HPP
#define PET_HPP

#include <bits/stdc++.h>
#include "Point.hpp"
#include <iostream>
#include "CoinGatherer"

class Snail : public CoinGatherer{
public:
// CTOR CCTOR DTOR
    Snail();
    Snail(const Snail& snail);
    ~Snail();
    Snail& operator= (const Snail& snail);

// GETTER SETTER
    int getMovementSpeed() const;
    Point getPoint() const;

    void setMovementSpeed(int _movement_speed);
    void setPosition(int _position);

// METHODS
    void Move();
    void takeCoin();

private:
    int movement_speed;
    Point position;
};

#endif