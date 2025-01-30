#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noname_clap_name"), ScavTrap(), FragTrap(), _name("noname") {
    ScavTrap::resetEnergy();
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    ScavTrap::resetEnergy();
    std::cout << "Modified DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "Assignment DiamondTrap operator called" << std::endl;
    return *this;
}

void DiamondTrap::WhoAmI(void) const {
    std::cout << "This DiamondTrap has names: " << _name << ", " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
