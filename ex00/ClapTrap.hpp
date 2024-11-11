#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);

	private:
		std::string name;
		unsigned int hit_pts;
		unsigned int energy_pts;
		unsigned int attack_dmg;

	public:
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status(void);
};

#endif