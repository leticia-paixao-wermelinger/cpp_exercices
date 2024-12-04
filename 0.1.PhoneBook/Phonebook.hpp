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

void Phonebook::addNewContact()
{
	if (this->size < 8)
	{
		this->contacts[this->index].createContact();
		this->size++;
		this->index++;
	}
	else // Pq q quando entra aqui ta dando double free no final?
	{
		if (this->index == 8)
			this->index = 0;
		std::cout << "WARNING: You have reached the maximum space in your phonebook. The oldest contact will be replaced by this new one." << std::endl;
		this->contacts[this->index].~Contact(); // Imagino q seja por essa linha, mas não pode não ter ela pq dá ruim...
		this->contacts[this->index].createContact();
		this->index++;
	}
}

void Phonebook::searchContact()
{
	int	i = 0;
	std::string	index;

	if (this->size == 0)
		std::cout << "There are no contacts in your phonebook" << std::endl;
	else
	{
		std::cout << "|" << std::setw(10) << "Index";
		std::cout << "|" << std::setw(10) << "FirstName";
		std::cout << "|" << std::setw(10) << "LastName";
		std::cout << "|" << std::setw(10) << "Nickname";
		std::cout << "|" << std::endl;
		while (i < size)
		{
			this->contacts[i].printTableContact(i);
			std::cout << std::endl;
			i++;
		}
		while (42)
		{
			std::cout << "Enter the index you want to see, or 'BACK' to finish the SEARCH mode" << std::endl;
			getline(std::cin, index);
			if (std::cin.eof())
			{
				std::cin.clear(); // Não está funcionando. O Ctrl+D está encerrando o programa, no lugar de encerrar apenas o método. Pq??
				break ;
			}
			else if (index == "BACK")
				return ;
			else
			{
				if (index == "0")
					this->contacts[0].printListContact();
				else if ((atoi(index.c_str()) >= 1 && atoi(index.c_str()) < 8) && atoi(index.c_str()) < this->size)
					this->contacts[atoi(index.c_str())].printListContact();
			}
		}
	}
}