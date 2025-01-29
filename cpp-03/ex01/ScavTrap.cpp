#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_hp = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hp = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << "Modifed ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap& other) : ClapTrap(other) {
    this->_hp = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << " ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hp = other._hp;
        this->_energy = other._energy;
        this->_damage = other._damage;
    }
    std::cout << "Assignment ScavTrap operator called" << std::endl;
    return *this;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
