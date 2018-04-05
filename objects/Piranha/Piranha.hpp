/*
 * File: Piranha.hpp
 * Description: Abstraction of class Piranha
 * Author :
 * Version :
 * USAGE : #include "Piranha.hpp"
*/

#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <bits/stdc++.h>
#include "Fish.hpp"
#include "Point.hpp"
#include <iostream>

// constants still arbitrary
#define PIRANHA_PRICE 30;
#define PIRANHA_FULL_PERIOD 10;
#define PIRANHA_HUNGER_PERIOD 10;
#define PIRANHA_COIN_PERIOD 0;
#define PIRANHA_MOVEMENT_SPEED 10;

using namespace std;

class Piranha : public Fish, public CoinProducer {
  public:
    // CTOR CCTOR DTOR
    Piranha();
    Piranha(const Piranha &piranha);
    ~Piranha();
    Piranha &operator=(const Piranha &piranha);

    // GETTER SETTER
    static int getPiranhaCount();

    static void setPiranhaCount(int _piranha_count);

    // METHODS
    void DropCoin();
    void Eat();

  private:
    static int piranha_count;
};

#endif;