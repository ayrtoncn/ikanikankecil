#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "LinkedList.hpp"
#include "../Fish/Fish.hpp"
#include "../Guppy/Guppy.hpp"
#include "../Piranha/Piranha.hpp"
#include "../Coin/Coin.hpp"
#include "../Food/Food.hpp"

using namespace std;

class Aquarium {
public:
    // CTOR
    Aquarium();
    Aquarium(int _width, int _height);
    Aquarium(const Aquarium& aquarium);

    // DEWA AQUARIUM 
    void runAquarium();

    // METHODS
    friend void AddFishFromFish(Aquarium& Aq, const Fish& _fish);
    friend void AddCoinFromCoins(const Coin &coin);
    friend void AddFoodfromFoods(const Food &food);

    friend void DeleteFishFromFish(const Fish &_fish);
    friend void DeleteCoinFromCoins(const Coin &coin);
    friend void DeleteFoodfromFoods(const Food &food);

    void MoveAll();

  private:
    int width;
    int height;
    LinkedList<Guppy> guppy;
    LinkedList<Piranha> piranha;
    LinkedList<Coin> coins;
    LinkedList<Food> foods;
    Snail snail;
};

#endif