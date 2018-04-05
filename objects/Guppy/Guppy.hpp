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
#include "Fish.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

class Guppy : public Fish, public CoinProducer {
  public:
    // CTOR CCTOR DTOR
    Guppy();
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

  private:
    static int guppy_count;
    int growth_level;
};

#endif