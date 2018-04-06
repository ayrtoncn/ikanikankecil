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
#include "../../data_structures/Point/Point.hpp"
#include <iostream>
#include "../oop.hpp"
#include <unistd.h>

using namespace std;

class Food {
public:
    // CTOR CCTOR DTOR
    Food();
    Food(double x);
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
     //COntroller
     void executeFood();

private:
    string name;
    int movement_speed;
    Point position;
    double Food_now;
    double Food_prevtime;
    double Food_sec_since_last;
};

#endif