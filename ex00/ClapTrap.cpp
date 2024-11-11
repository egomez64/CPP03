#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
	hit_pts = 10;
	energy_pts = 10;
	attack_dmg = 0;
	std::cout << "Constructor call" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor call" << std::endl;
}

void ClapTrap::status(void)
{
	std::cout << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << "name : " << name << std::endl;
	std::cout << "hit points : " << hit_pts << std::endl;
	std::cout << "energy points : " << energy_pts << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_pts > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
		energy_pts--;
	}
	else
		std::cout << "ClapTrap has " << energy_pts << " energy points so he can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << " damage." << std::endl;
	if (hit_pts > 0)
	{
		if (hit_pts - amount >= 0)
			hit_pts -= amount;
		else
			hit_pts = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " is repaired of " << amount << " hit points." << std::endl;
	if (hit_pts < 10)
	{
		if (hit_pts + amount <= 10)
			hit_pts += amount;
		else
			hit_pts = 10;
	}
}
