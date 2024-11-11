#include "ClapTrap.h"

ClapTrap::ClapTrap(std::string _name)
{
	this.name = _name;
	std::cout << "Constructor call" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor call" << std::endl;
}

void ClapTrap::status(void)
{
	std::cout << ""
	std::cout << "name : " << this.name << std::endl;
	std::cout << "hit points : " << this.hit_pts << std::endl;
	std::cout << "energy points : " << this.energy_pts << std::endl;
}

