#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name );

int main()
{
    Zombie *myZombie = NULL;
    int n = 5;
    int i = 0;

    myZombie = zombieHorde(n, "BLAAAA");
    while (i < 5)
    {
        myZombie[i].announce();
        i++;
    }
    delete[] myZombie;
}