#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap a("Friend1");
    a.attack("ENEMY!!!");
    a.takeDamage(10);
    a.beRepaired(2);
    a.guardGate();

    return 0;
}