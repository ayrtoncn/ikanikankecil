/*
 * File: Pet.hpp
 * Description: Abstraction of class Snail
 * Author :
 * Version :
 * USAGE : 
*/

#include "Pet.hpp"
#include "Coin.hpp"

// CTOR CCTOR DTOR
Snail::Snail() {
    movement_speed = 0;
    position.setX(0);
    position.setY(SCREEN_HEIGHT);
}

Snail::Snail(const Snail& snail) {
    movement_speed = snail.movement_speed;
    position.setX(snail.getX());
    position.setY(snail.getY());
}

Snail::~Snail() {

}

Snail::Snail& operator= (const Snail& snail) {
    this->movement_speed = snail.movement_speed;
    this->position.setX(snail.getX());
    this->position.setY(snail.getY());
    return *this;
}

// GETTER SETTER
int getMovementSpeed() const {
    return movement_speed;
}

Point getPoint() const {
    return position;
}

int getOrientation() const {
    return orientation;
}

void setMovementSpeed(int _movement_speed) {
    movement_speed = _movement_speed;
}

void setPosition(int _position) {
    position = _position;
}

void setOrientation(int _orientation) {
    orientation = _orientation;
}

// METHODS
void MoveRight() {
    position.setX(position.getX()++);
    orientation = 2;
}

void MoveLeft() {
    position.setX(position.getX()--);
    orientation = 1;
}

void takeCoin(Coin& coin) {
    while (position.getX() != coin.position.getX()) {
        if (Snail.position.getX() < coin.position.getX()) {
            MoveRight();
        } else {
            MoveLeft();
        }
    }
    while (position.getY() != coin.position.getY());

    coin.~Coin();
}