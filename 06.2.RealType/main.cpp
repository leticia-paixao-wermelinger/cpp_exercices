/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:50 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:51 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void) // randomly instantiates A, B, or C and returns the instance as a Base pointer
{
    std::srand(std::time(NULL));
    int ranNbr = std::rand() % 3 + 1;
    std::cout << "Random number: " << ranNbr << std::endl;
    switch (ranNbr)
    {
        case 1:
            std::cout << "A generated" << std::endl;
            return new A();
        case 2:
            std::cout << "B generated" << std::endl;
            return new B();
        case 3:
            std::cout << "C generated" << std::endl;
            return new C();
        default:
            std::cout << "Error generating type" << std::endl;
            return NULL;
    }
}

void identify(Base* p) // prints the actual type of the object pointed to by p: "A", "B", or "C"
{
    std::cout << "Identify pointer: ";
    if (dynamic_cast<A*>(p))
        std::cout << "Hello, there! I'm A! Glad to be here!" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Hello, there! I'm B! Glad to be here!" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Hello, there! I'm C! Glad to be here!" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) // prints the actual type of the object referenced by p: "A", "B", or "C"
{
    std::cout << "Identify reference: ";
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "Hi! I'm A! :)" << std::endl;
        return ;
    }
    catch (...) {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "Hi! I'm B! :)" << std::endl;
            return ;
        }
        catch (...) {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "Hi! I'm C! :)" << std::endl;
                return ;
            }
            catch (std::exception &e) {
                std::cout << "Unknown Type" << std::endl;
                return;
            }
        }
    }
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}