#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);

	protected:
		std::string name;
		unsigned int hit_pts;
		unsigned int energy_pts;
		unsigned int attack_dmg;
		unsigned int max;

	public:
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		virtual void status(void);
};

#endif