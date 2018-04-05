#include "Piranha.hpp"

int Piranha::piranha_count = 0;
int Piranha::PIRANHA_PRICE = 50;
int Piranha::PIRANHA_FULL_PERIOD = 50;
int Piranha::PIRANHA_HUNGER_PERIOD = 50;
int Piranha::PIRANHA_COIN_PERIOD = 50;
int Piranha::PIRANHA_MOVEMENT_SPEED = 50;
// CTOR CCTOR DTOR
Piranha::Piranha():Fish("Piranha" + (piranha_count + 1), PIRANHA_PRICE, PIRANHA_FULL_PERIOD, PIRANHA_HUNGER_PERIOD, PIRANHA_COIN_PERIOD, PIRANHA_MOVEMENT_SPEED){
    piranha_count++;
}

Piranha::Piranha(Point position, char orientation): Fish("Piranha" +  (piranha_count + 1), PIRANHA_PRICE, PIRANHA_FULL_PERIOD, PIRANHA_HUNGER_PERIOD, PIRANHA_COIN_PERIOD, PIRANHA_MOVEMENT_SPEED, position, orientation) {
    piranha_count++;
}

Piranha::Piranha(const Piranha &piranha):Fish("Piranha" + (piranha_count + 1), PIRANHA_PRICE, PIRANHA_FULL_PERIOD, PIRANHA_HUNGER_PERIOD, PIRANHA_COIN_PERIOD, PIRANHA_MOVEMENT_SPEED) {
    // Fish::Fish(piranha);
    // piranha_count++;
    // name = "Piranha" +piranha_count;
}

Piranha::~Piranha() {
    piranha_count--;
}

Piranha& Piranha::operator=(const Piranha &piranha) {
    // if (this != &piranha) {
    //     Fish::Fish(piranha);
    //     piranha_count++;
    //     name = "Piranha" + (string) piranha_count;
    // }
    return *this;
}

// GETTER SETTER
int Piranha::getPiranhaCount() {
    return piranha_count;
}

void Piranha::setPiranhaCount(int _piranha_count) {
    piranha_count = _piranha_count;
}

// METHODS
void Piranha::DropCoin() {
    int guppy_price=0;
    int guppy_growth_level=0;
    Coin coin(guppy_price * guppy_growth_level + 1, 1,position);
}

void Piranha::Eat() {

}

void Piranha::dewaPiranha(){
    prevtime = time_since_start();
    delay= rand()%4+1;
    arah = rand()%8+1;
    time(&start);
    bool running=true;
    while(running){
        //lock_guard<mutex> locker(lock1);
        now = time_since_start();
        sec_since_last = now - prevtime;
        prevtime = now;
        Move();
        // cout<<"Y"<<position.getX()<<endl;
        // cout<<"X"<<position.getY()<<endl;
    }
}