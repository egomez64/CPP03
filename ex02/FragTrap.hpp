#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string _name);
        ~FragTrap();
        FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &src);
        void attack(const std::string &target);
        void status(void);
        void highFivesGuys(void);
};

#endif