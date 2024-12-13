#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name );

int main()
{
    Zombie *myZombie = NULL;
    int n = 5;

    myZombie = zombieHorde(n, "BLAAAA");
    std::cout << "Vai liberar a memória" << std::endl;
    delete[] myZombie;
}