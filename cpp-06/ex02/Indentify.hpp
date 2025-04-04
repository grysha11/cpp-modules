#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP
#include "Classes.hpp"
#include <iostream>
#include <ctime>

class Indentify {
    private:
        Indentify();
    public:
        static Base* generate(void);
        static void indentify(Base* p);
        static void indentify(Base& p);
};

#endif