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
#include "../Fish/Fish.hpp"
#include "../../data_structures/Point/Point.hpp"
#include <iostream>

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

    static void setPiranhaCount();

    // METHODS
    void DropCoin();
    void Eat();

  private:
    static int piranha_count;
};

#endif;