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
#include "../../data_structures/Point/Point.hpp"
#include <iostream>

using namespace std;

class Fish {
public:
    // CTOR CCTOR DTOR OPERATOR=
    Fish();
    Fish(const Fish& fish);
    ~Fish();
    Fish& operator=(const Fish& fish);

    // GETTER SETTER
    static int getFishCount();
    string getName() const;
    int getFullPeriod() const;
    bool getIsHungry() const;
    int getHungerPeriod() const;
    int getCoinPeriod() const;
    int getMovementSpeed() const;
    Point getPosition() const;
    char getOrientation() const;

    static void setFishCount();
    void setName(string _name);
    void setFullPeriod(int _full_period);
    void setIsHungry(bool _is_hungry);
    void setHungerPeriod(int _hunger_period);
    void setCoinPeriod(int _coin_period);
    void setMovementSpeed(int movement_speed);
    void setPosition(Point _position);
    void setOrientation(char _orientation);

    // METHODS
    void Move();
    virtual void DropCoin() = 0;
    virtual void Eat() = 0;

private:
    static int fish_count;

protected:
    string name;
    int full_period; // periode kenyang
    bool is_hungry;
    int hunger_period; // periode butuh makan
    int coin_period;
    int movement_speed;
    Point position;
    char orientation; // 'l' for left and 'r' for right
};

#endif