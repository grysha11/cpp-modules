#include "Indentify.hpp"

Base* Indentify::generate(void) {
    std::srand(std::time(0));

    int random = std::rand() % 3;
    if (random == 0) {
        std::cout << "A class was created" << std::endl;
        return new A();
    }
    if (random == 1) {
        std::cout << "B class was created" << std::endl;
        return new B();
    }
    std::cout << "C class was created" << std::endl;
    return new C();
}

void Indentify::indentify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Indetified class is A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Indetified class is B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Indetified class is C" << std::endl;
    } else {
        std::cout << "Indetified class is something else" << std::endl;
    }
}

void Indentify::indentify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Indetified class is A" << std::endl;
        return;
    } catch (std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Indetified class is B" << std::endl;
        return;
    } catch (std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Indetified class is C" << std::endl;
        return;
    } catch (std::exception& e) {}
    std::cout << "Indetified class is something else" << std::endl;
}
