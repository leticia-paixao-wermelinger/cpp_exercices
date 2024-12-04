#include "Phonebook.hpp"
//#include <iostream>

int	main()
{
	std::string cmd;
	Phonebook	myPhonebook;

	std::cout << "\033[31;1;5mWellcome to your Phonebook.\033[0m" << std::endl;
	std::cout << "\033[35mPlease, write:" << std::endl;
	std::cout << "'ADD' to insert a new contact," << std::endl;
	std::cout << "'SEARCH' to find an existing contact, or" << std::endl;
	std::cout << "'EXIT' to close the program.\033[0m" << std::endl;
	std::cout << "\033[0;36mPS: Your Phobebook can store a maximum of 8 contacts.\033[0m" << std::endl << std::endl;
	while (42)
	{
		std::cout << "\033[1;32m$ ";
		getline(std::cin, cmd);
		std::cout << "\033[0m";
		if (std::cin.eof())
			return (0);
		if (cmd == "ADD")
			myPhonebook.addNewContact();
//			std::cout << "Let's add a new contact" << std::endl;
		else if (cmd == "SEARCH")
			myPhonebook.searchContact();
//			std::cout << "Let's search for an existing contact" << std::endl;
		else if (cmd == "EXIT")
			break ;
		//std::cout << cmd << std::endl;
	}
}