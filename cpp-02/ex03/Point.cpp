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
    Fixed full_area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / Fixed(2.0f);
    //full area of triangle using determinant formula

    Fixed area1 = (point.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY())) / Fixed(2.0f);
    Fixed area2 = (a.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY())) / Fixed(2.0f);
    Fixed area3 = (a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())) / Fixed(2.0f);
    //sub-areas formed by the point

    if ((area1 > 0 && area2 > 0 && area3 > 0) && (area1 + area2 + area3 == full_area)) {
        return true;
    }
    return false;
}
