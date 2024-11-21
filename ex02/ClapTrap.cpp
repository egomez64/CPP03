#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name()
{
	hit_pts = 10;
	energy_pts = 10;
	attack_dmg = 0;
	max = hit_pts;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
	hit_pts = 10;
	energy_pts = 10;
	attack_dmg = 0;
	max = hit_pts;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this == &src)
		return (*this);
	this->attack_dmg = src.attack_dmg;
	this->energy_pts = src.energy_pts;
	this->hit_pts = src.hit_pts;
	this->max = src.max;
	this->name = src.name;
	return (*this);
}

void ClapTrap::status(void)
{
	std::cout << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << "ClapTrap name : " << name << std::endl;
	std::cout << "hit points : " << hit_pts << std::endl;
	std::cout << "energy points : " << energy_pts << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_pts > 0 && hit_pts > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
		energy_pts--;
	}
	else
		std::cout << "ClapTrap can't attcack because he is dead or out of energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
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

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_pts > 0 && hit_pts < max)
	{
		if (hit_pts + amount <= max)
			hit_pts += amount;
		else
			hit_pts = max;
	}
	else if (hit_pts == max)
		std::cout << name << " is already full health" << std::endl;
	else
		std::cout << name << " can't repair itself because he is already dead" << std::endl;
}
