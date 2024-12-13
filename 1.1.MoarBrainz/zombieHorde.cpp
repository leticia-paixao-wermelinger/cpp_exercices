#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;
    Zombie  *myZombie = new Zombie[N];

    if (N == 0)
        return (myZombie);
    while (i < N)
    {
        std::cout << "Loop em i = " << i << std::endl;
        myZombie[i].setName(name);
        myZombie[i].announce();
        i++;
    }
    std::cout << "Vai retornar" << std::endl;
    return (myZombie);
}