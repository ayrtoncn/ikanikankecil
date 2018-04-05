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

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

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
    int getOrientation() const;
    int getRadius() const;

    void setMovementSpeed(int _movement_speed);
    void setPosition(int _position);
    void setOrientation(int _orientation);
    void setRadius(int _radius);

// METHODS
    void MoveRight();
    void MoveLeft();
    void takeCoin(Coin& coin);

private:
    int movement_speed;
    Point position;
    // recently added
    int orientation;
    int radius;
};

#endif