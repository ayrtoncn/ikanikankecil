/*
 * File: Piranha.hpp
 * Description: Abstraction of class Piranha
 * Author :
 * Version :
 * USAGE : #include "Piranha.hpp"
*/

#include "Piranha.hpp"

int main() {
    Piranha g1;
    cout << "ctor g1 name " << g1.getName() << " price " << g1.getPrice() << " full " << g1.getFullPeriod() << " hunger " << g1.getHungerPeriod() << " coin " << g1.getCoinPeriod() << " speed " << g1.getMovementSpeed() << endl;
    Point x;
    x.setX(10);
    x.setY(30);
    Piranha g2(x, 'r');
    cout << "ctor g2 name " << g2.getName() << " price " << g2.getPrice() << " full " << g2.getFullPeriod() << " hunger " << g2.getHungerPeriod() << " coin " << g2.getCoinPeriod() << " speed " << g2.getMovementSpeed() << " pos " << g2.getPosition().getX() << " " << g2.getPosition().getY() << " orientation " << g2.getOrientation() << endl;
    Piranha g3;
    cout << "ctor g3 name " << g3.getName() << " price " << g3.getPrice() << " full " << g3.getFullPeriod() << " hunger " << g3.getHungerPeriod() << " coin " << g3.getCoinPeriod() << " speed " << g3.getMovementSpeed() << endl;
    g3=g2;
    cout << "op= g3=g2 name " << g3.getName() << " price " << g3.getPrice() << " full " << g3.getFullPeriod() << " hunger " << g3.getHungerPeriod() << " coin " << g3.getCoinPeriod() << " speed " << g3.getMovementSpeed() << endl;
    g2.setIsHungry(true);
    cout << "g2 ishungry? " << g2.getIsHungry() << endl;
    g2.Eat();
    cout << "g2 eats" << endl;
    cout << "check ishungry " << g2.getIsHungry() << endl;
    return 0;
    return 0;
}