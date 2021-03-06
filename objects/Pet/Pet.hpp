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
#include "../../data_structures/Point/Point.hpp"
#include <iostream>
#include "../CoinGatherer/CoinGatherer.hpp"
#include "../Coin/Coin.hpp"
#include "../oop.hpp"
#include <unistd.h>

class Snail : public CoinGatherer{
public:
// CTOR CCTOR DTOR
    Snail();
    Snail(const Snail& snail);
    ~Snail();
    Snail& operator= (const Snail& snail);

// GETTER SETTER
    int getMovementSpeed();
    Point getPosition();
    int getOrientation();

    void setTujuan(Point);
    void setOrientation(int);
    void MoveRight();
    void MoveLeft();
    void setMovementSpeed(int _movement_speed);
    void setPosition(Point _position);

// METHODS
    void Move();
    void takeCoin(Coin&);

//CONTROLER
    void executeSnail();
private:
    //int radius;
    int orientation;
    int movement_speed;
    Point position;
    Point tujuan;
    double Snail_now;
    double Snail_prevtime;
    double Snail_sec_since_last;
};

#endif