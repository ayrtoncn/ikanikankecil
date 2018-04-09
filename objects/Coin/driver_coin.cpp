/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE :
*/

#include "Coin.hpp"

int main(){

    Point x1;
    Coin c1(30,30,x1);
    cout << "ctor c1 value " << c1.getValue() << " move speed " << c1.getMovementSpeed() << " position " << c1.getPosition().getX() << " " << c1.getPosition().getY() << endl;
    Coin c2(c1);
    cout << "ctor c2 value " << c2.getValue() << " move speed " << c2.getMovementSpeed() << " position " << c2.getPosition().getX() << " " << c2.getPosition().getY() << endl;
    Coin c3;
    cout << "ctor c3 value " << c3.getValue() << " move speed " << c3.getMovementSpeed() << " position " << c3.getPosition().getX() << " " << c3.getPosition().getY() << endl;
    c3 = c1;
    cout << "cctor c3 value " << c3.getValue() << " move speed " << c3.getMovementSpeed() << " position " << c3.getPosition().getX() << " " << c3.getPosition().getY() << endl;
    return 0;
    
}