/*
 * File: Guppy.hpp
 * Description: Abstraction of class Guppy
 * Author :
 * Version :
 * USAGE : #include "Guppy.hpp"
*/

#include "Guppy.hpp"

int main() {
    Guppy g1;
    cout << "ctor g1 name " << g1.getName() << " price " << g1.getPrice() << " full " << g1.getFullPeriod() << " hunger " << g1.getHungerPeriod() << " coin " << g1.getCoinPeriod() << " speed " << g1.getMovementSpeed() << endl;
    Point x;
    x.setX(10);
    x.setY(30);
    Guppy g2(x,'r');
    cout << "ctor g2 name " << g2.getName() << " price " << g2.getPrice() << " full " << g2.getFullPeriod() << " hunger " << g2.getHungerPeriod() << " coin " << g2.getCoinPeriod() << " speed " << g2.getMovementSpeed() << " pos " << g2.getPosition().getX() << " " << g2.getPosition().getY() << " orientation " << g2.getOrientation() << endl;
    g2.setGrowthLevel(2);
    cout << "g2 growth " << g2.getGrowthLevel() << endl;
    g2.setIsHungry(true);
    cout << "g2 is hungry" << endl;
    g2.Eat();
    cout << "g2 eats" << endl;
    cout << "check ishungry " << g2.getIsHungry() << endl;
    return 0;
}