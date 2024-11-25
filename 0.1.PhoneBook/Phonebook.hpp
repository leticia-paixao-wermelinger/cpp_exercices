#include "Contact.hpp"
#include <iostream>
#include <ostream>

class Phonebook
{
	public:
	Phonebook()
	{
		this->size = 1;
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
	if (this->size <= 8)
	{
//		std::cout << "Vai criar um novo contato no índice " << this->index << std::endl;
		this->contacts[this->index].createContact();
		this->size++;
		this->index++;
	}
	else
	{
		if (this->index == 8)
			this->index = 0;
		std::cout << "WARNING: You have reached the maximum space in your phonebook. The oldest contact will be replaced by this new one." << std::endl;
		this->contacts[this->index].createContact();
		// O ideal seria que fosse uma fila...... Como fazer isso em cpp?
		this->index++;
	}
//	std::cout << "Vai criar um novo contato" << std::endl;
}

void Phonebook::searchContact()
{
	int	i = 0;
	std::string	name;

	std::cout << "Please, insert the name of the contact you want to search:" << std::endl;
	getline(std::cin, name);
	while (i <= this->size)
	{
		if (this->contacts[i].checkName(name) == true)
		{
			this->contacts[i].printContact();
//			std::cout << "Nome encontrado na lista no índice " << i << std::endl; // Apenas para teste
			return ;
		}
		i++;
	}
	std::cout << "Contact not found" << std::endl;
}