#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point p1(Fixed(1), Fixed(1));
    Point p2(Fixed(2), Fixed(3));
    Point p3(Fixed(3), Fixed(1));
    Point p4(Fixed(2), Fixed(2));

    bool result = bsp(p1, p2, p3, p4);
    if (result) {
        std::cout << "p4 is inside of triangle p1, p2, p3" << std::endl;
    }

    Point p5(Fixed(0), Fixed(0));
    result = bsp(p1, p2, p3, p5);
    if (!result) {
        std::cout << "p5 is not inside of triangle p1, p2, p3" << std::endl;
    }

    return 0;
}
