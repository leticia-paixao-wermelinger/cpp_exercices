#include "Harl.hpp"

int main ()
{
	Harl harl;

	std::cout << "Harl is always complaining" << std::endl;
	std::cout << "And then they say vegans are the inflexible and irrational ones..." << std::endl;
	harl.complain("debug");
	harl.complain("INFO");
	harl.complain("warning");
	harl.complain("error");
	return (0);
}
