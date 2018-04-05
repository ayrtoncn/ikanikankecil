#include "Fish.hpp"

Fish::fish_count = 0;

// CTOR CCTOR DTOR OPERATOR=
Fish::Fish(string _name, int _full_period, int _hunger_period, int _coin_period, int _movement_speed, Point _position, char orientation) {
    name = _name;
    full_period = _full_period;
    is_hungry = false;
    hunger_period = _hunger_period;
    coin_period = _coin_period;
    movement_speed = _movement_speed;
    position = _position;
    orientation = _orientation;
    fish_count += 1;
}

Fish::Fish(const Fish& fish) {
    full_period = fish.full_period;
    is_hungry = fish.is_hungry;
    hunger_period = fish.hunger_period;
    coin_period = fish.coin_period;
    movement_speed = fish.movement_speed;
    position = fish.position;
    orientation = fish.orientation;
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

// GETTER SETTER
static int Fish::getFishCount() {
    return fish_count;
}

string Fish::getName() const {
    return name;
}

int Fish::getFullPeriod() const {
    return full_period;
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

static void Fish::setFishCount(int _fish_count) {
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

void Fish::setMovementSpeed(int movement_speed) {
    movement_speed = _movement_speed;
}

void Fish::setPosition(Point _position) {
    position = _position;
}

void Fish::setOrientation(char _orientation) {
    orientation = _orientation;
}
