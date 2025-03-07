#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
    private:
        const Fixed _x;
        const Fixed _y;
        Point& operator = (const Point& other);
    public:
        Point();
        Point(const Fixed x, const Fixed y);
        Point(const Point& other);
        ~Point();
        Fixed getX(void) const;
        Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif