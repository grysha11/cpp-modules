#include <string>
#include <iostream>
#include "colors.hpp"

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string init_name);
        ~Zombie();
        void setName(std::string name);
        std::string getName(void);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);