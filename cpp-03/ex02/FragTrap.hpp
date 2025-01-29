#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(ClapTrap& other);
        ~FragTrap();
        FragTrap& operator = (const FragTrap& other);
        void highFivesGuys(void);
};

#endif