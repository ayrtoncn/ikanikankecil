#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "../../data_structures/LinkedList/LinkedList.hpp"
#include "../Fish/Fish.hpp"
#include "../Coin/Coin.hpp"
#include "../Food/Food.hpp"
#include "../Guppy/Guppy.hpp"
#include "../Piranha/Piranha.hpp"
#include "../Pet/Pet.hpp"

using namespace std;

class Aquarium {
public:
    // CTOR
    Aquarium();
    Aquarium(const Aquarium& aquarium);
    Aquarium& operator=(Aquarium*);

    // GETTER SETTER
    LinkedList<Fish*>* getFishList();
    void addFish(Guppy);
    void addFish(Piranha);
    void dellFIsh(int i);

    Fish* getFish(int i);

    int getFishAmmount();

    // METHODS
    friend void AddFishFromFish(const Fish& _fish);
    friend void AddCoinFromCoins(const Coin &coin);
    friend void AddFoodfromFoods(const Food &food);

    friend void DeleteFishFromFish(const Fish &_fish);
    friend void DeleteCoinFromCoins(const Coin &coin);
    friend void DeleteFoodfromFoods(const Food &food);

    void MoveAll();

  private:
    LinkedList<Fish*> fish;
    LinkedList<Coin> coins;
    LinkedList<Food> foods;
    Snail snail;
};

#endif