#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>

class Phonebook
{
	public:
	Phonebook();
	~Phonebook();
	void	addNewContact();
	void	searchContact();
	private:
	Contact	*contacts;
	int		size;
	int		index;
};
#endif