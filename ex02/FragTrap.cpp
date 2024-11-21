#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap constructor called" << std::endl;
    name = "";
    hit_pts = 100;
    energy_pts = 100;
    attack_dmg = 30;
    max = hit_pts;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    name = _name;
    hit_pts = 100;
    energy_pts = 100;
    attack_dmg = 30;
    max = hit_pts;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap copy operator assignment called" << std::endl;
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if (energy_pts > 0 && hit_pts > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
		energy_pts--;
	}
	else
		std::cout << "FragTrap can't attcack because he is dead or out of energy" << std::endl;
}

void FragTrap::status(void)
{
    std::cout << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << "FragTrap name : " << name << std::endl;
	std::cout << "hit points : " << hit_pts << std::endl;
	std::cout << "energy points : " << energy_pts << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::string answer;
    std::cout << name << " ask you for a high five" << std::endl;
    std::getline(std::cin, answer);
    if (answer == "yes")
        std::cout << ":)" << std::endl;
    else if (answer == "no")
        std::cout << ":(" << std::endl;
    else
        std::cout << "??" << std::endl;
}
