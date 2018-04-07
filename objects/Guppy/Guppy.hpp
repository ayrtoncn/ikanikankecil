/*
 * File: Guppy.hpp
 * Description: Abstraction of class Guppy
 * Author :
 * Version :
 * USAGE : #include "Guppy.hpp"
*/

#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <bits/stdc++.h>

#include <math.h>
#include <sstream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <time.h>

#include "../Fish/Fish.hpp"
#include "../../data_structures/Point/Point.hpp"
#include <iostream>
#include "../CoinProducer/CoinProducer.hpp"
#include "../Coin/Coin.hpp"

using namespace std;

class Guppy : public Fish, public CoinProducer {
  public:
    // CTOR CCTOR DTOR
    Guppy();
    Guppy(Point,char);
    Guppy(const Guppy &guppy);
    ~Guppy();
    Guppy &operator=(const Guppy &guppy);

    // GETTER SETTER
    static int getGuppyCount();
    int getGrowthLevel() const;

    static void setGuppyCount(int _guppy_count);
    void setGrowthLevel(int _growth_level);

    // METHODS
    void DropCoin();
    void Eat();
    //control
    void dewaGuppy();

    //static
    static int guppy_count;
    static int GUPPY_COIN_PERIOD;
    static int GUPPY_FULL_PERIOD;
    static double GUPPY_HUNGER_PERIOD;
    static int GUPPY_MOVEMENT_SPEED;
    static int GUPPY_PRICE;
  private:
    
    int growth_level;
};

#endif
