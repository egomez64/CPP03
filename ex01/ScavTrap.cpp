#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap constructor called" << std::endl;
    name = "";
    hit_pts = 100;
    energy_pts = 50;
    attack_dmg = 20;
    max = hit_pts;
    gatekeeper = false;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    name = _name;
    hit_pts = 100;
    energy_pts = 50;
    attack_dmg = 20;
    max = hit_pts;
    gatekeeper = false;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap copy operator assignment called" << std::endl;
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (energy_pts > 0 && hit_pts > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
		energy_pts--;
	}
	else
		std::cout << "ScavTrap can't attcack because he is dead or out of energy" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->gatekeeper)
	{
		std::cout << "ScavTrap " << name << " is in gatekeeper mode so he can't take damage" << std::endl;
		return ;
	}
	if (hit_pts > 0)
	{
		std::cout << name << " takes " << amount << " damage." << std::endl;
		if (hit_pts - amount >= 0)
			hit_pts -= amount;
		else
		{
			hit_pts = 0;
			std::cout << name << " died" << std::endl;
		}
	}
	else
		std::cout << name << " is already dead, don't be so violent" << std::endl;
}

void ScavTrap::status(void)
{
    std::cout << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << "ScavTrap name : " << name << std::endl;
	std::cout << "hit points : " << hit_pts << std::endl;
	std::cout << "energy points : " << energy_pts << std::endl;
    std::cout << "gate keeper mode : " << gatekeeper << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << std::endl;
}

void ScavTrap::guardGate()
{
    if (!gatekeeper)
	{
        std::cout << name << " gate keeper mode : on" << std::endl;
		this->gatekeeper = true;
	}
    else
	{
        std::cout << name << " gate keeper mode : off" << std::endl;
		this->gatekeeper = false;
	}
}
