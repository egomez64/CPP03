#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trap("R2D2");

    trap.status();
    trap.attack("C3PO");
    trap.status();
    trap.takeDamage(1);
    trap.status();
    trap.beRepaired(1);
    trap.status();
    trap.beRepaired(1);
    trap.status();
    for (int i = 0; i < 10; i++)
        trap.attack("C3PO");
    trap.status();
    for (int i = 0; i < 11; i++)
        trap.takeDamage(1);
    trap.status();
}