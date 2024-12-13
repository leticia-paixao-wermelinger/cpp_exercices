#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie( std::string name );

int main()
{
    Zombie *myZombie;

    randomChump("Zooo");
    myZombie = newZombie("BLAAAA");
    delete(myZombie);
}