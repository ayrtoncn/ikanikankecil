/*
 * File: CoinGatherer.hpp
 * Description: Abstraction of class CoinGatherer
 * Author : Aditbro
 * Version : 0.0.1
 * USAGE : #include "CoinGatherer"
*/

#ifndef CoinGatherer_hpp
#define CoinGatherer_hpp
#include "../Coin/Coin.hpp"

class CoinGatherer{
    virtual void takeCoin(Coin&) = 0;
};

#endif