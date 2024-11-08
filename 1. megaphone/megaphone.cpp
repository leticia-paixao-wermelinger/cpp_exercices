#include <iostream>

void	scream(char *str)
{
	int	i = 0;

	while (str[i])
	{
		std::cout << (char)toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv[i])
	{
		scream(argv[i]);
//		std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}
