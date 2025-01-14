#include <string>
#include <iostream>
#include "colors.hpp"

class Zombie {
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void setName(std::string name);
        std::string getName(void);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);