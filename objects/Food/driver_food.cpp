/*
 * File: Food.hpp
 * Description: Abstraction of class Food
 * Author :
 * Version :
 * USAGE : #include "Food.hpp"
*/

#include "Food.hpp"

int main(){
    Food f1;
    cout << "ctor f1 movement speed " << f1.getMovementSpeed() << " position " << f1.getPosition().getX() << " " << f1.getPosition().getY() << endl;
    Food f2(50);
    cout << "ctor f2 movement speed " << f2.getMovementSpeed() << " position " << f2.getPosition().getX() << " " << f2.getPosition().getY() << endl;
    Food f3(f1);
    cout << "cctor f3 movement speed " << f3.getMovementSpeed() << " position " << f3.getPosition().getX() << " " << f3.getPosition().getY() << endl;
    Food f4;
    cout << "ctor f4 movement speed " << f4.getMovementSpeed() << " position " << f4.getPosition().getX() << " " << f4.getPosition().getY() << endl;
    f4 = f3;
    cout << "op= f4=f3 movement speed " << f4.getMovementSpeed() << " position " << f4.getPosition().getX() << " " << f4.getPosition().getY() << endl;
    return 0;
}