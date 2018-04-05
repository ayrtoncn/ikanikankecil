/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE : #include "Point.hpp"
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <bits/stdc++.h>
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
    double getX() const;
    double getY() const;

    void setX(double _x);
    void setY(double _y);

    // METHODS
    float getDistance(const Point& point);

private:
    double x;
    double y;
};

#endif