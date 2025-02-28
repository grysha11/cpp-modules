#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_hp = 100;
    this->_max_hp = 100;
    this->_energy = 100;
    this->_damage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hp = 100;
    this->_max_hp = 100;
    this->_energy = 100;
    this->_damage = 30;
    std::cout << "Modifed FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    this->_hp = 100;
    this->_max_hp = 100;
    this->_energy = 100;
    this->_damage = 30;
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hp = other._hp;
        this->_max_hp = 100;
        this->_energy = other._energy;
        this->_damage = other._damage;
    }
    std::cout << "Assignment FragTrap operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "High five guys c'mon !!" << std::endl;
}
