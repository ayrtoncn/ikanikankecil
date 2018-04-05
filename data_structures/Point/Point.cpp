/*
 * File:
 * Description:
 * Author :
 * Version :
 * USAGE : 
*/

// CTOR CCTOR DTOR
Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(const Point& point) {
    x = point.x;
    y = point.y;
}

Point::~Point() {

}

Point::Point& operator=(const Point& point) {
    this->x = point.x;
    this->y = point.y;
    return *this;
}

// OPERATOR OVERLOADING
Point Point::operator+(const Point& point) {
    Point P;
    P.x = x + point.x;
    P.y = y + point.y;
    return P;
}

Point Point::operator-(const Point& point) {
    Point P;
    P.x = x - point.x;
    P.y = y - point.y;
    return P;
}

// GETTER SETTER
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int _x) {
    x = _x;
}

void Point::setY(int _y) {
    y = _y;
}

// METHODS
float Point::getDistance(const Point& point) {
    float sum;
    sum = sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
    return sum;
}