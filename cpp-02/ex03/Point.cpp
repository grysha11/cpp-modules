#include "Point.hpp"

Point::Point() : _x(0), _y(0) {

}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {

}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {

}

Point::~Point() {

}

Fixed Point::getX(void) const {
    return this->_x;
}

Fixed Point::getY(void) const {
    return this->_y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed as_x = point.getX() - a.getX();
    Fixed as_y = point.getY() - a.getY();

    bool s_ab = (b.getX() - a.getX()) * as_y - (b.getY() - a.getY()) * as_x > 0;

    if (((c.getX() - a.getX()) * as_y - (c.getY() - a.getY()) * as_x > 0) == s_ab) 
        return false;
    if (((c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY())*(point.getX() - b.getX()) > 0) != s_ab) 
        return false;
    return true;
}
