#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap trap("R2D2");

    trap.status();
    trap.attack("C3PO");
    trap.status();
    trap.takeDamage(10);
    trap.status();
    trap.beRepaired(10);
    trap.status();
    trap.beRepaired(10);
    trap.status();
	trap.guardGate();
	trap.takeDamage(10);
	trap.status();
	trap.guardGate();
    for (int i = 0; i < 99; i++)
        trap.attack("C3PO");
    trap.status();
    for (int i = 0; i < 11; i++)
        trap.takeDamage(10);
    trap.status();
}