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
    movement_speed = 20;
    position.setX(SCREEN_WIDTH/2);
    position.setY(SCREEN_HEIGHT-40);
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

Point Snail::getPosition(){
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

void Snail::setTujuan(Point _tujuan){
    tujuan.setX(_tujuan.getX());
    tujuan.setY(_tujuan.getY());
}

// METHODS
void Snail::Move(){
    double a;
    a = atan2(0,tujuan.getX()-position.getX());
    //cout<<a<<endl;
    if(a==0){
        orientation = 'r';
    }else{
        orientation = 'l';
    }
    position.setX(position.getX()+movement_speed * Snail_sec_since_last*cos(a));
}

void Snail::takeCoin(Coin& coin) {
    // if ((position.getX()+20 <= coin.getPosition().getX()) && (position.getX()-20 >= coin.getPosition().getX()) && (position.getY()-20 >= coin.getPosition().getY()) && ( position.getY() + 20 <= coin.getPosition().getY())) {
    //     while ((position.getX()+radius <= coin.getPosition().getX()-coin.getRadius()) or (position.getX()-radius >= coin.getPosition().getX()+coin.getRadius())) {
    //         if (position.getX()+radius <= coin.getPosition().getX()-coin.getRadius()) {
    //             MoveRight();
    //         } else if (position.getX()-radius >= coin.getPosition().getX()+coin.getRadius()) {
    //             MoveLeft();
    //         }
    //     }
    //     while (position.getY()-radius >= coin.getPosition().getY()+coin.getRadius()); // wait until coin falls down
    // }
    //coin.~Coin();
}

void Snail::executeSnail(){
    Snail_prevtime = time_since_start();
    Point temp;
    tujuan = temp;
    bool running =true;
    while(running){
        usleep(100);
        Snail_now = time_since_start();
        Snail_sec_since_last = Snail_now - Snail_prevtime;
        Snail_prevtime = Snail_now;
        //cout<<tujuan.getX()<<" "<< tujuan.getY()<< endl;
        if(tujuan.getX()!=temp.getX() && tujuan.getY()!=temp.getY()){
            if(!(tujuan.getX()-10<=position.getX() && tujuan.getX()+10>=position.getX())){
                Move();
            }
        }
    }
}