#include "Fish.hpp"

int Fish::fish_count = 0;
mutex Fish::lock1;
// CTOR CCTOR DTOR OPERATOR=
Fish::Fish(string _name, int _price, int _full_period, int _hunger_period, int _coin_period, int _movement_speed) {
    name = _name;
    price = _price;
    full_period = _full_period;
    is_hungry = false;
    hunger_period = _hunger_period;
    coin_period = _coin_period;
    movement_speed = _movement_speed;
    Point temp;
    position = temp;
    tujuan = temp;
    orientation = 'l';
    fish_count += 1;
    dropcoins = false;
    time(&start);
    delay= rand()%4+1;
}

Fish::Fish(string _name, int _price, int _full_period, int _hunger_period, int _coin_period, int _movement_speed, Point _position, char _orientation) {
    name = _name;
    price = _price;
    full_period = _full_period;
    is_hungry = false;
    hunger_period = _hunger_period;
    coin_period = _coin_period;
    movement_speed = _movement_speed;
    position = _position;
    Point temp;
    tujuan = temp;
    orientation = _orientation;
    fish_count += 1;
    dropcoins = false;
    time(&start);
    delay= rand()%4+1;
}

Fish::Fish(const Fish& fish) {
    full_period = fish.full_period;
    is_hungry = fish.is_hungry;
    hunger_period = fish.hunger_period;
    coin_period = fish.coin_period;
    movement_speed = fish.movement_speed;
    position = fish.position;
    orientation = fish.orientation;
    dropcoins = fish.dropcoins;
    fish_count += 1;
}

Fish::~Fish() {
    // No pointer to be freed
}

Fish& Fish::operator=(const Fish& fish) {
    if (this != &fish) {
        name = fish.name;
        full_period = fish.full_period;
        is_hungry = fish.is_hungry;
        hunger_period = fish.hunger_period;
        coin_period = fish.coin_period;
        movement_speed = fish.movement_speed;
        position = fish.position;
        orientation = fish.orientation;
        fish_count += 1;
    }
    return *this;
}

// GETTER SETTE
int Fish::getFishCount() {
    return fish_count;
}

string Fish::getName() const {
    return name;
}

int Fish::getFullPeriod() const {
    return full_period;
}

int Fish::getPrice() const {
    return price;
}

bool Fish::getIsHungry() const {
    return is_hungry;
}

int Fish::getHungerPeriod() const {
    return hunger_period;
}

int Fish::getCoinPeriod() const {
    return coin_period;
}

int Fish::getMovementSpeed() const {
    return movement_speed;
}

Point Fish::getPosition() const {
    return position;
}

char Fish::getOrientation() const {
    return orientation;
}

bool Fish::getDropCoin() const {
    return dropcoins;
}

void Fish::setFishCount(int _fish_count) {
    fish_count = _fish_count;
}

void Fish::setName(string _name) {
    name = _name;
}

void Fish::setFullPeriod(int _full_period) {
    full_period = _full_period;
}

void Fish::setIsHungry(bool _is_hungry) {
    is_hungry = _is_hungry;
}

void Fish::setHungerPeriod(int _hunger_period) {
    hunger_period = _hunger_period;
}

void Fish::setCoinPeriod(int _coin_period) {
    coin_period = _coin_period;
}

void Fish::setMovementSpeed(int _movement_speed) {
    movement_speed = _movement_speed;
}

void Fish::setPosition(Point _position) {
    position = _position;
}

void Fish::setDropCoin(bool _dropcoins) {
    dropcoins = _dropcoins;
}

void Fish::setTujuan(Point _tujuan){
    tujuan = _tujuan;
}

void Fish::setOrientation(char _orientation) {
    orientation = _orientation;
}
void Fish::Move(){
    Fish::lock1.lock();
    srand(time(NULL));
    Point temp;
    if(tujuan.getX()==temp.getX()&& tujuan.getY()==temp.getY()){

        if(position.getX()<=10){
            arah = 4;
            time(&start);
        }else if(position.getX()>=SCREEN_WIDTH-10){
            arah = 3;
            time(&start);
        }else if(position.getY()<=10){
            arah = 2;
            time(&start);
        }else if(position.getY()>=SCREEN_HEIGHT-10){
            arah = 1;
            time(&start);
        }
        // cout<<movement_speed<<endl;
        if(difftime(time(0),start)<=delay){
            switch(arah){
                case 1:
                    position.setY(position.getY()-movement_speed * sec_since_last);
                    break;
                case 2:
                    position.setY(position.getY()+movement_speed * sec_since_last);
                    break;
                case 3:
                    position.setX(position.getX()-movement_speed * sec_since_last);
                    orientation = 'l';
                    break;
                case 4:
                    position.setX(position.getX()+movement_speed * sec_since_last);
                    orientation = 'r';
                    break;
                case 5:
                    position.setX(position.getX()+movement_speed * sec_since_last);
                    position.setY(position.getY()+movement_speed * sec_since_last);
                    orientation = 'r';
                    break;
                case 6:
                    position.setX(position.getX()+movement_speed * sec_since_last);
                    position.setY(position.getY()-movement_speed * sec_since_last);
                    orientation = 'r';
                    break;
                case 7:
                    position.setX(position.getX()-movement_speed * sec_since_last);
                    position.setY(position.getY()+movement_speed * sec_since_last);
                    orientation = 'l';
                    break;
                case 8:
                    position.setX(position.getX()-movement_speed * sec_since_last);
                    position.setY(position.getY()-movement_speed * sec_since_last);
                    orientation = 'l';
                    break;
            }
        }else{
            time(&start);
            delay= rand()%4+1;
            arah = rand()%8+1;
        }
    }else{
        double a;
        a = atan2(tujuan.getY()-position.getY(),tujuan.getX()-position.getX());
        if((a<=3.14 && a>=(3.14/2) )|| (a>=-3.14 && a<=-(3.14/2))){
            orientation = 'l';
        }else{
            orientation = 'r';
        }
        position.setX(position.getX()+movement_speed * sec_since_last*cos(a));
        position.setY(position.getY()+movement_speed * sec_since_last*sin(a));
    }
    Fish::lock1.unlock();
    // cout<<"Y"<<position.getX()<<endl;
    // cout<<"X"<<position.getY()<<endl;

}
void Fish::dewaIkan(){
    prevtime = time_since_start();
    delay= rand()%4+1;
    arah = rand()%8+1;
    time(&start);
    bool running=true;
    while(running){
        //lock_guard<mutex> locker(lock1);
        srand(time(NULL));
        now = time_since_start();
        sec_since_last = now - prevtime;
        prevtime = now;
        Move();
        // cout<<"Y"<<position.getX()<<endl;
        // cout<<"X"<<position.getY()<<endl;
    }
}
