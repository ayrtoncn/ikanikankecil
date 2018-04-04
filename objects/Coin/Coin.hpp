/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE : #include "Coin.hpp"
*/

#ifndef COIN_HPP
#define COIN_HPP

#include <bits/stdc++.h>
#include "Point.hpp"
#include <iostream>

class Coin {
public:
    // CTOR CCTOR DTOR
    Coin();
    Coin(const Coin& coin);
    ~Coin();
    Coin& operator=(const Coin& coin);

    // GETTER SETTER
    int getValue() const;
    int getMovementSpeed() const;
    Point getPosition() const;

    void setValue(int _value);
    void setMovementSpeed(int _movement_speed);
    void setPosition(Point _position);

    // METHODS


private:
    int value;
    int movement_speed;
    Point position;
};

#endif