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

Coin::Coin(int _value, int _movement_speed, Point _position) {
    value = _value;
    movement_speed = _movement_speed;
    position = _position;
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

int Coin::getRadius() const {
    return radius;
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

void Coin::setRadius(int _radius) {
    radius = _radius;
}

void Coin::stop(){
    running = false;
}

void Coin::executeCoin() {
    Coin_prevtime = time_since_start();
    running = true;
    while (running)
    {
        usleep(100);
        Coin_now = time_since_start();
        Coin_sec_since_last = Coin_now - Coin_prevtime;
        Coin_prevtime = Coin_now;
        if (position.getY() <= SCREEN_HEIGHT-40) {
            position.setY(position.getY() + movement_speed * Coin_sec_since_last);
        } else {
            position.setY(SCREEN_HEIGHT-40);
        }
    }
}