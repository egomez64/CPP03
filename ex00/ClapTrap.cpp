#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name()
{
	hit_pts = 10;
	energy_pts = 10;
	attack_dmg = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
	hit_pts = 10;
	energy_pts = 10;
	attack_dmg = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor call" << std::endl;
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
	this->name = src.name;
	return (*this);
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
		std::cout << "ClapTrap " << name << " takes " << amount << " damage." << std::endl;
		if (hit_pts - amount >= 0)
			hit_pts -= amount;
		else
		{
			hit_pts = 0;
			std::cout << "ClapTrap died" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap is already dead, don't be so violent" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_pts > 0 && hit_pts < 10)
	{
		if (hit_pts + amount <= 10)
			hit_pts += amount;
		else
			hit_pts = 10;
	}
	else if (hit_pts == 10)
		std::cout << "ClapTrap is already full health" << std::endl;
	else
		std::cout << "ClapTrap can't repair itself because he is already dead" << std::endl;
}
