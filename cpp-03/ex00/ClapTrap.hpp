#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap {
    private:
        std::string _name;
        int _hp;
        int _energy;
        int _damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& other);
        ~ClapTrap();
        ClapTrap& operator = (const ClapTrap& other);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif