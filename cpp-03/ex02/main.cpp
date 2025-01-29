#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap a("Friend1");
    a.attack("ENEMY!!!");
    a.takeDamage(10);
    a.beRepaired(2);
    a.highFivesGuys();

    return 0;
}