#include "Aquarium.hpp"
#include "../../oop.h"

Aquarium::Aquarium(){
    piranha = new LinkedList<Piranha>();
    guppy = new LinkedList<Guppy>();
    coins = new LinkedList<Coin>();
    food = new LinkedList<Food>();
    snail = new Snail();
    height = 720;
    width = 1280;
}

Aquarium::Aquarium(int _width, int _height){
    piranha = new LinkedList<Piranha>();
    guppy = new LinkedList<Guppy>();
    coins = new LinkedList<Coin>();
    food = new LinkedList<Food>();
    snail = new Snail();
    height = 720;
    width = 1280;
}
