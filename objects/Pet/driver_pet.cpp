/*
 * File: Pet.hpp
 * Description: Abstraction of class Snail
 * Author :
 * Version :
 * USAGE : 
*/

#include "Pet.hpp"

int main(){
    Snail s1;
    cout << "ctor s1 move speed " << s1.getMovementSpeed() << " position " << s1.getPosition().getX() << " " << s1.getPosition().getY() << endl;
    Snail s2(s1);
    cout << "cctor s2 move speed " << s2.getMovementSpeed() << " position " << s2.getPosition().getX() << " " << s2.getPosition().getY() << endl;
    Snail s3;
    cout << "ctor s3 move speed " << s3.getMovementSpeed() << " position " << s3.getPosition().getX() << " " << s3.getPosition().getY() << endl;
    s3=s1;
    cout << "op= s3=s1 move speed " << s3.getMovementSpeed() << " position " << s3.getPosition().getX() << " " << s3.getPosition().getY() << endl;
    return 0;
}