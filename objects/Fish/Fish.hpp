/*
 * File: Fish.hpp
 * Description: Abstraction of class Fish
 * Author :
 * Version :
 * USAGE : #include "Fish.hpp"
*/

#ifndef FISH_HPP
#define FISH_HPP

#include <bits/stdc++.h>

#include <math.h>
#include <sstream>
#include <cstdlib>
#include <thread>
#include <mutex>

#include "../../data_structures/Point/Point.hpp"
#include "../oop.hpp"
#include <iostream>
#include <time.h>

using namespace std;

class Fish {
public:
    static int fish_count;
    // CTOR CCTOR DTOR OPERATOR=
    Fish(string _name, int _price, int _full_period, int _hunger_period, int _coin_period, int _movement_speed);
    Fish(string _name, int _price, int _full_period, int _hunger_period, int _coin_period, int _movement_speed, Point _position, char orientation);
    Fish(const Fish& fish);
    ~Fish();
    Fish& operator=(const Fish& fish);

    // GETTER SETTER
    static int getFishCount();
    string getName() const;
    int getPrice() const;
    int getFullPeriod() const;
    bool getIsHungry() const;
    int getHungerPeriod() const;
    int getCoinPeriod() const;
    int getMovementSpeed() const;
    Point getPosition() const;
    char getOrientation() const;
    bool getDropCoin() const;

    static void setFishCount(int _fish_count);
    void setName(string _name);
    void setFullPeriod(int _full_period);
    void setIsHungry(bool _is_hungry);
    void setHungerPeriod(int _hunger_period);
    void setCoinPeriod(int _coin_period);
    void setMovementSpeed(int _movement_speed);
    void setPosition(Point _position);
    void setDropCoin(bool _dropcoins);
    void setOrientation(char _orientation);
    void setTujuan(Point _tujuan);

    // METHODS
    void Move();
    // virtual void DropCoin() = 0;
    // virtual void Eat() = 0;
    //controller
    void dewaIkan();

    static mutex lock1;

protected:
    string name;
    int price;
    int full_period; // periode kenyang
    bool is_hungry;
    double hunger_period; // periode butuh makan
    int coin_period;
    int movement_speed;
    Point position;
    Point tujuan;
    char orientation; // 'l' for left and 'r' for right
    double delay;
    time_t start;
    int arah;
    double now;
    double prevtime;
    double sec_since_last;
    bool dropcoins;
};

#endif
