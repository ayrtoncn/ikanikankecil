/*
 * File: Pet.hpp
 * Description: Abstraction of class Snail
 * Author :
 * Version :
 * USAGE : 
*/

#include "Pet.hpp"
#include "../Coin/Coin.hpp"

// CTOR CCTOR DTOR
Snail::Snail() {
    movement_speed = 0;
    position.setX(0);
    position.setY(1280);
}

Snail::Snail(const Snail& snail) {
    movement_speed = snail.movement_speed;
    position.setX(snail.position.getX());
    position.setY(snail.position.getY());
}

Snail::~Snail() {

}

Snail& Snail::operator= (const Snail& snail) {
    this->movement_speed = snail.movement_speed;
    this->position.setX(snail.position.getX());
    this->position.setY(snail.position.getY());
    return *this;
}

// GETTER SETTER
int Snail::getMovementSpeed(){
    return this->movement_speed;
}

Point Snail::getPoint(){
    return this->position;
}

int Snail::getOrientation(){
    return this->orientation;
}

void Snail::setMovementSpeed(int _movement_speed) {
    movement_speed = _movement_speed;
}

void Snail::setPosition(Point _position) {
    position.setX(_position.getX());
    position.setY(_position.getY());
}

void Snail::setOrientation(int _orientation) {
    orientation = _orientation;
}

// METHODS
void Snail::MoveRight() {
    position.setX(position.getX()+1);
    orientation = 2;
}

void Snail::MoveLeft() {
    position.setX(position.getX()-1);
    orientation = 1;
}

void Snail::takeCoin(Coin& coin) {
    if ((position.getX()+radius <= coin.getPosition().getX()-coin.getRadius()) or (position.getX()-radius >= coin.getPosition().getX()+coin.getRadius()) or (position.getY()-radius >= coin.getPosition().getY()+coin.getRadius())) {
        while ((position.getX()+radius <= coin.getPosition().getX()-coin.getRadius()) or (position.getX()-radius >= coin.getPosition().getX()+coin.getRadius())) {
            if (position.getX()+radius <= coin.getPosition().getX()-coin.getRadius()) {
                MoveRight();
            } else if (position.getX()-radius >= coin.getPosition().getX()+coin.getRadius()) {
                MoveLeft();
            }
        }
        while (position.getY()-radius >= coin.getPosition().getY()+coin.getRadius()); // wait until coin falls down
    }
    coin.~Coin();
}