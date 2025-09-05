#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *myZombie;

    myZombie = new Zombie;
    myZombie->setName(name);
    myZombie->announce();
    return (myZombie);
}