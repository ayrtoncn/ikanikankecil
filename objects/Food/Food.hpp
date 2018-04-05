/*
 * File: Food.hpp
 * Description: Abstraction of class Food
 * Author :
 * Version :
 * USAGE : #include "Food.hpp"
*/

#ifndef FOOD_HPP
#define FOOD_HPP

#include <bits/stdc++.h>
#include "Point.hpp"
#include <iostream>

class Food {
public:
    // CTOR CCTOR DTOR
    Food();
    Food(const Food& food);
    ~Food();
    Food& operator=(const Food& food);

    // GETTER SETTER
    string getName() const;
    int getMovementSpeed() const;
    Point getPosition() const;

    void setName(string _name);
    void setMovementSpeed(int _movement_speed);
    void setPosition(Point _position);

    // METHODS


private:
    string name;
    int movement_speed;
    Point position;
};

#endif