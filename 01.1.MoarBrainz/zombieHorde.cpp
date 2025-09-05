#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;
    Zombie  *myZombie = new Zombie[N];

    if (N == 0)
        return (myZombie);
    while (i < N)
    {
        myZombie[i].setName(name);
        i++;
    }
    return (myZombie);
}