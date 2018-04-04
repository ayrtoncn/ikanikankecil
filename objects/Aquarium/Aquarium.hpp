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
    friend void AddFishFromFish(Aquarium &Aq, const Fish& _fish);
    friend void AddCoinFromCoins(Aquarium &Aq, const Coin &coin);
    friend void AddFoodfromFoods(Aquarium &Aq, const Food &food);

    friend void DeleteFishFromFish(Aquarium &Aq, const Fish &_fish);
    friend void DeleteCoinFromCoins(Aquarium &Aq, const Coin &coin);
    friend void DeleteFoodfromFoods(Aquarium &Aq, const Food &food);

    void MoveAll();

  private:
    int width;
    int height;
    pthread_mutex_t lock1;
    LinkedList<Fish*> fish;
    LinkedList<Coin> coins;
    LinkedList<Food> foods;
    Snail snail;
};

#endif