#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap trap("R2D2");

    trap.status();
    trap.attack("C3PO");
    trap.status();
    trap.takeDamage(10);
    trap.status();
    trap.beRepaired(10);
    trap.status();
    trap.beRepaired(10);
    trap.status();
    for (int i = 0; i < 100; i++)
        trap.attack("C3PO");
    trap.status();
    for (int i = 0; i < 11; i++)
        trap.takeDamage(10);
    trap.status();
	trap.highFivesGuys();
}