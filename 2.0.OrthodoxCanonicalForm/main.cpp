#include "Fixed.hpp"
#include <iostream>

// subject main
/*
int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
*/

// my test main

int main (void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	c.setRawBits( 42 );
	b.setRawBits( 24 );
	std::cout << "Initial a: " << a.getRawBits() << std::endl;
	std::cout << "Initial b: " << b.getRawBits() << std::endl;
	std::cout << "Initial c: " << c.getRawBits() << std::endl;
	a = b;
	b = c;
	c.setRawBits( 69 );
	std::cout << "Final a: " << a.getRawBits() << std::endl;
	std::cout << "Final b: " << b.getRawBits() << std::endl;
	std::cout << "Final c: " << c.getRawBits() << std::endl;
	return 0;
}