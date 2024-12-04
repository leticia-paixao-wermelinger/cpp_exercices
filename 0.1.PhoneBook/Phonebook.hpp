#include "Contact.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>

class Phonebook
{
	public:
	Phonebook()
	{
		this->size = 0;
		this->index = 0;
		this->contacts = new Contact[8];
	}
	~Phonebook()
	{
		delete[] this->contacts;
	}
	void	addNewContact();
	void	searchContact();
	private:
	Contact	*contacts;
	int		size;
	int		index;
};