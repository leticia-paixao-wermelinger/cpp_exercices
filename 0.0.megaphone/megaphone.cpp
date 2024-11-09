#include <iostream>

/**
 * @brief Converts a given string to uppercase and prints it to the standard output.
 *
 * This function iterates over each character in the input string and converts it
 * to uppercase using the `toupper` function. It then outputs each character to 
 * the standard output without any separation. The result of `toupper` is cast 
 * to `char` because `toupper` returns an `int` (as per its prototype `int toupper(int c);`).
 * The cast ensures the printed character is correctly interpreted as a single 
 * character in the output.
 *
 * Note: No need to include `<ctype.h>` since `toupper` is a part of the C standard 
 * library, and we are assuming a C++ standard library import context that includes it 
 * implicitly when using `std::cout`.
 *
 * @param str A null-terminated string to be converted to uppercase and printed.
 */

void	scream(char *str)
{
	int	i = 0;

	while (str[i])
	{
		std::cout << (char)toupper(str[i]);
		i++;
	}
}


/**
 * @brief Entry point of the program that processes command-line arguments to 
 *        print them in uppercase.
 *
 * The main function checks if any command-line arguments are provided. If no arguments
 * are given, it outputs a predefined message indicating a loud noise. Otherwise, it
 * iterates over each argument starting from the first (ignoring the program name) 
 * and calls the scream function to print each argument in uppercase.
 *
 * @param argc The count of command-line arguments, including the program name.
 * @param argv An array of pointers to the command-line arguments, with argv[0] being 
 *             the program name.
 * @return int Returns 0 upon successful execution.
 */

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
