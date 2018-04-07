#include "Guppy.hpp"
#include "../Fish/Fish.hpp"
int Guppy::GUPPY_PRICE = 50;
int Guppy::GUPPY_FULL_PERIOD = 50;
time_t Guppy::GUPPY_HUNGER_PERIOD = time(&);
int Guppy::GUPPY_COIN_PERIOD = 50;
int Guppy::GUPPY_MOVEMENT_SPEED = 50;
int Guppy::guppy_count =0;
// CTOR CCTOR DTOR
Guppy::Guppy():Fish("Guppy" + (guppy_count + 1), GUPPY_PRICE, GUPPY_FULL_PERIOD, GUPPY_HUNGER_PERIOD, GUPPY_COIN_PERIOD, GUPPY_MOVEMENT_SPEED){
    guppy_count++;
}

Guppy::Guppy(Point position, char orientation): Fish("Guppy" + (guppy_count + 1), GUPPY_PRICE, GUPPY_FULL_PERIOD, GUPPY_HUNGER_PERIOD, GUPPY_COIN_PERIOD, GUPPY_MOVEMENT_SPEED, position, orientation) {
    guppy_count++;
}

Guppy::Guppy(const Guppy &guppy):Fish("Guppy" + (guppy_count + 1), GUPPY_PRICE, GUPPY_FULL_PERIOD, GUPPY_HUNGER_PERIOD, GUPPY_COIN_PERIOD, GUPPY_MOVEMENT_SPEED){
    // this=guppy;
    // guppy_count++;
    // name = "Guppy" + guppy_count;
}

Guppy::~Guppy() {
    guppy_count--;
}

Guppy& Guppy::operator=(const Guppy &guppy) {
    // this=guppy;
    // return *this;
    return *this;
}

// GETTER SETTER
int Guppy::getGuppyCount() {
    return guppy_count;
}

int Guppy::getGrowthLevel() const {
    return growth_level;
}

void Guppy::setGuppyCount(int _guppy_count) {
    guppy_count = _guppy_count;
}

void Guppy::setGrowthLevel(int _growth_level) {
    growth_level = _growth_level;
}

// METHODS
void Guppy::DropCoin() {
    Coin coin(10, 1,position);  
}

void Guppy::Eat() {

}
void Guppy::dewaGuppy(){
    prevtime = time_since_start();
    delay= rand()%4+1;
    arah = rand()%8+1;
    time(&start);
    bool running=true;
    while(running && name!="die"){
        srand(time(NULL));
        now = time_since_start();
        sec_since_last = now - prevtime;
        prevtime = now;
        Move();
        // cout<<"Y"<<position.getX()<<endl;
        // cout<<"X"<<position.getY()<<endl;
    }
}
