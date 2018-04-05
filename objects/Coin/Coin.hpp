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
    Coin(int _value, int _movement_speed, Point _position);
    ~Coin();
    Coin& operator=(const Coin& coin);

    // GETTER SETTER
    int getValue() const;
    int getMovementSpeed() const;
    Point getPosition() const;
    int getRadius() const;

    void setValue(int _value);
    void setMovementSpeed(int _movement_speed);
    void setPosition(Point _position);
    void setRadius(int _radius);

    // METHODS


private:
    int value;
    int movement_speed;
    Point position;
    int radius;
};

#endif