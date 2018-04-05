/*
 * File: Piranha.hpp
 * Description: Abstraction of class Piranha
 * Author :
 * Version :
 * USAGE : #include "Piranha.hpp"
*/

#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <math.h>
#include <sstream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <time.h>

#include <bits/stdc++.h>
#include "../Fish/Fish.hpp"
#include "../../data_structures/Point/Point.hpp"
#include <iostream>
#include "../CoinProducer/CoinProducer.hpp"
#include "../Coin/Coin.hpp"

using namespace std;

class Piranha : public Fish, public CoinProducer {
  public:
    // CTOR CCTOR DTOR
    Piranha();
    Piranha(Point,char);
    Piranha(const Piranha &piranha);
    ~Piranha();
    Piranha &operator=(const Piranha &piranha);

    // GETTER SETTER
    static int getPiranhaCount();

    static void setPiranhaCount(int _piranha_count);

    // METHODS
    void DropCoin();
    void Eat();
    //control
    void dewaPiranha();

    //static
    static int piranha_count;
    static int PIRANHA_COIN_PERIOD;
    static int PIRANHA_FULL_PERIOD;
    static int PIRANHA_HUNGER_PERIOD;
    static int PIRANHA_MOVEMENT_SPEED;
    static int PIRANHA_PRICE;
};

#endif