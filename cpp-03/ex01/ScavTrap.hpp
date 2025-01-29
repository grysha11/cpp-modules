#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ClapTrap& other);
        ~ScavTrap();
        ScavTrap& operator = (const ScavTrap& other);
        void guardGate(void);
};

#endif