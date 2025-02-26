#include "Fixed.hpp"
#include "Point.hpp"

void printRes(bool check) {
    if (check) {
        std::cout << "point is inside of a triangle" << std::endl;
    }
    std::cout << "point is outside of a triangle" << std::endl;
}

int main() {
    Point A(Fixed(0), Fixed(0));
    Point B(Fixed(5), Fixed(0));
    Point C(Fixed(0), Fixed(5));

    Point inside(Fixed(2), Fixed(2));
    printRes(bsp(A, B, C, inside));
    Point onEdge(Fixed(2.5f), Fixed(0));
    printRes(bsp(A, B, C, onEdge));
    Point atVertex(Fixed(0), Fixed(0));
    printRes(bsp(A, B, C, atVertex));
    Point outside(Fixed(6), Fixed(6));
    printRes(bsp(A, B, C, outside));

    return 0;
}
