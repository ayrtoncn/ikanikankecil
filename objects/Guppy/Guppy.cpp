#include "Guppy.hpp"
#include "../Fish/Fish.hpp"
int Guppy::GUPPY_PRICE = 10;
int Guppy::GUPPY_FULL_PERIOD = 50;
double Guppy::GUPPY_HUNGER_PERIOD = 15;
int Guppy::GUPPY_COIN_PERIOD = 5;
int Guppy::GUPPY_MOVEMENT_SPEED = 80;
int Guppy::guppy_count =0;
// CTOR CCTOR DTOR
Guppy::Guppy():Fish("Guppy" + (guppy_count + 1), GUPPY_PRICE, GUPPY_FULL_PERIOD, GUPPY_HUNGER_PERIOD, GUPPY_COIN_PERIOD, GUPPY_MOVEMENT_SPEED){
    guppy_count++;
    growth_level = 0;
}

Guppy::Guppy(Point position, char orientation): Fish("Guppy" + (guppy_count + 1), GUPPY_PRICE, GUPPY_FULL_PERIOD, GUPPY_HUNGER_PERIOD, GUPPY_COIN_PERIOD, GUPPY_MOVEMENT_SPEED, position, orientation) {
    guppy_count++;
    growth_level = 0;
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
    hunger_period=15;
    Point P;
    tujuan = P;
    is_hungry = false;
    growth_level++;
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
        hunger_period-=sec_since_last;
        int ctemp = coin_period;
        coin_period-=sec_since_last;
        //cout<<GUPPY_HUNGER_PERIOD<<endl;
        prevtime = now;
        
        if(hunger_period<=10 && hunger_period>=0){
            is_hungry = true;
            //cout<<tujuan.getX()<<" "<<tujuan.getY()<<endl;
        }else if(hunger_period<0){
            name = "die";
        }
        if (coin_period <=0) {
            dropcoins = true;
            coin_period = ctemp;
        } else {
            dropcoins = false;
        }
        Move();
        // cout<<"Y"<<position.getX()<<endl;
        // cout<<"X"<<position.getY()<<endl;
    }
    position.setX(-100);
    position.setY(-100);
}
