#include "Harl.hpp"

int main (int argc, char **argv)
{
	Harl harl;
	std::string level;

	if (argc != 2)
	{
		std::cout << "Usage: ./HarlFilter <level>" << std::endl;
		return (1);
	}
	level = argv[1];
	harl.complain(level, level);
	return (0);
}