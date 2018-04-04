#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "Food.hpp"

using namespace std;

class Aquarium {
public:
    // CTOR
    Aquarium();
    Aquarium(int _width, int _height);
    Aquarium(const Aquarium& aquarium);

    // GETTER SETTER
    

    // METHODS
    friend void AddFishFromFish(const Fish& _fish);
    friend void AddCoinFromCoins(const Coin &coin);
    friend void AddFoodfromFoods(const Food &food);

    friend void DeleteFishFromFish(const Fish &_fish);
    friend void DeleteCoinFromCoins(const Coin &coin);
    friend void DeleteFoodfromFoods(const Food &food);

    void MoveAll();

  private:
    int width;
    int height;
    LinkedList<Fish*> fish;
    LinkedList<Coin> coins;
    LinkedList<Food> foods;
    Snail snail;
};

#endif