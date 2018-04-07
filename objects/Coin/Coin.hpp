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
#include "../../data_structures/Point/Point.hpp"
#include <iostream>
#include "../oop.hpp"
#include <unistd.h>

class Coin {
public:
    // CTOR CCTOR DTOR
    Coin();
    Coin(int, int, Point);
    Coin(const Coin& coin);
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
    void setRadius(int);

    // METHODS
    void executeCoin();

private:
    int value;
    int movement_speed;
    Point position;
    int radius;
    double Coin_now;
    double Coin_prevtime;
    double Coin_sec_since_last;
};

#endif
