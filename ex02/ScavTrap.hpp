#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string _name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &src);
        void guardGate();
        void attack(const std::string &target);
        void status(void);

    private:
        bool gatekeeper;
};

#endif