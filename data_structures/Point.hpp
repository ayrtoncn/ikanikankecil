/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE : #include "Point.hpp"
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

class Point {
public:
    // CTOR CCTOR DTOR
    Point();
    Point(const Point& point);
    ~Point();
    Point& operator=(const Point& point);

    // OPERATOR OVERLOADING
    Point operator+(const Point& point);
    Point operator-(const Point& point);

    // GETTER SETTER
    int getX() const;
    int getY() const;

    void setX(int _x);
    void setY(int _y);

    // METHODS
    float getDistance(const Point& point);

private:
    int x, y;
};

#endif