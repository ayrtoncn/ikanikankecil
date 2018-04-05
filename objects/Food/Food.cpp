/*
 * File: Food.hpp
 * Description: Abstraction of class Food
 * Author :
 * Version :
 * USAGE : #include "Food.hpp"
*/
#include "Food.hpp"

// CTOR CCTOR DTOR
Food::Food() {
    name = "";
    movement_speed = 0;
    position.setX(0);
    position.setY(0);
}

Food::Food(const Food& food) {
    strcpy(name, food.name);
    movement_speed = food.movement_speed;
    position.setX(food.position.getX());
    position.setY(food.position.getY());
}

Food::~Food() {
    name = "";
    movement_speed = 0;
    position.setX(0);
    position.setY(0);
}

Food::Food& operator=(const Food& food) {
    strcpy(this->name, food.name);
    this->movement_speed = food.movement_speed;
    this->position.setX(food.position.getX());
    this->position.setY(food.position.getY());
    return *this;
}

// GETTER SETTER
string Food::getName() const {
    return name;
}

int Food::getMovementSpeed() const {
    return movement_speed;
}

Point Food::getPosition() const {
    return position;
}

int Food::getRadius() const {
    return radius;
}

void Food::setName(string _name) {
    name = _name;
}

void Food::setMovementSpeed(int _movement_speed) {
    movement_speed = _movement_speed;
}

void Food::setPosition(Point _position) {
    position = _position;
}

void Food::setRadius(int _radius) {
    radius = _radius;
}