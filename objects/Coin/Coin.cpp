/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE :
*/

#include "Coin.hpp"
// CTOR CCTOR DTOR
Coin::Coin() {
    value = 0;
    movement_speed = 0;
    position.setX(0);
    position.setY(0);
}

Coin::Coin(const Coin& coin) {
    value = coin.value;
    movement_speed = coin.movement_speed;
    position.setX(coin.position.getX());
    position.setY(coin.position.getY());
}

Coin::~Coin() {
    value =0;
    movement_speed = 0;
    position.setX(-1);
    position.setY(-1);
}

Coin& Coin::operator=(const Coin& coin) {
    this->value = coin.value;
    this->movement_speed = coin.movement_speed;
    this->position.setX(coin.position.getX());
    this->position.setY(coin.position.getY());
    return *this;
}

// GETTER SETTER
int Coin::getValue() const {
    return value;
}

int Coin::getMovementSpeed() const {
    return movement_speed;
}

Point Coin::getPosition() const {
    return position;
}

void Coin::setValue(int _value) {
    value = _value;
}

void Coin::setMovementSpeed(int _movement_speed) {
    movement_speed = _movement_speed;
}

void Coin::setPosition(Point _position) {
    position = _position;
}