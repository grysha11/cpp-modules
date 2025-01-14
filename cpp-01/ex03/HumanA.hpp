#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"
#include <string>

class HumanA {
    private:
        std::string _name;
        Weapon& _weapon;
    public:
        HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
            std::cout << "HumanA constructor called" << std::endl;
        }
        ~HumanA();
        void attack();
};

#endif