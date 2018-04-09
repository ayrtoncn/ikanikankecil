#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "../../data_structures/LinkedList/LinkedList.hpp"
#include "../Fish/Fish.hpp"
#include "../Guppy/Guppy.hpp"
#include "../Piranha/Piranha.hpp"
#include "../Coin/Coin.hpp"
#include "../Food/Food.hpp"
#include "../Pet/Pet.hpp"
#include "../oop.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <mutex>
#include "../Fish/Fish.hpp"
#include "../Guppy/Guppy.hpp"
#include "../Piranha/Piranha.hpp"
#include "../Food/Food.hpp"

using namespace std;

class Aquarium {
public:
    // CTOR
    Aquarium();
    Aquarium(int _width, int _height);
    Aquarium(const Aquarium& aquarium);
    Aquarium& operator=(const Aquarium& Aq);
    ~Aquarium();

    //THREAD HANDLER
    void lockAquarium();

    void unlockAquarium();

    // DEWA AQUARIUM 
    void runAquarium();

    // SAVE LOAD
    void save();
    void load();

    // METHODS
    friend void InteractionChecker(Aquarium* Aq);
    friend void AddFishFromFish(Aquarium& Aq, const Fish& _fish);
    friend void AddCoinFromCoins(Aquarium& Aq, const Coin &coin);
    friend void AddFoodfromFoods(Aquarium& Aq, const Food &food);

    friend void DeleteFishFromFish(Aquarium& Aq, const Fish &_fish);
    friend void DeleteCoinFromCoins(Aquarium& Aq, const Coin &coin);
    friend void DeleteFoodfromFoods(Aquarium& Aq, const Food &food);

  private:
    int width;
    int height;
    int num_fish;
    int num_guppy;
    int num_piran;
    int num_food;
    int num_coin;
    int num_object;
    int coin;
    char input;
    LinkedList<Guppy*> guppy;
    LinkedList<Piranha*> piranha;
    LinkedList<Coin*> coins;
    LinkedList<Food*> foods;
    mutex lock1;
    thread ikan[1000];
    thread object[1000];
    Snail snail;
};

#endif