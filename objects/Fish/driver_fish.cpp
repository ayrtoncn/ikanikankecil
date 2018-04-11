/*
 * File: Fish.hpp
 * Description: Abstraction of class Fish
 * Author :
 * Version :
 * USAGE : #include "Fish.hpp"
*/

#include "Fish.hpp"

int main() {
    Fish f1("f1",30,20,20,20,20);
    cout << "ctor " << f1.getName() << " " << f1.getPrice() << " " << f1.getFullPeriod() << " " << f1.getHungerPeriod() << " " << f1.getCoinPeriod() << " " << f1.getMovementSpeed() << " " << endl;
    f1.setHungerPeriod(50);
    cout << "f1 set hunger to 50" << endl;
    f1.setFullPeriod(10);
    cout << "f1 set full period to 10" << endl;
    Fish f3(f1);
    cout << "cctor f3(f1) f3" << " " << f3.getPrice() << " " << f3.getFullPeriod() << " " << f3.getHungerPeriod() << " " << f3.getCoinPeriod() << " " << f3.getMovementSpeed() << " " << endl;
    return 0;
}