#include <string>
#include <iostream>
#include <ostream>

class Contact
{
	public:
		Contact(/* args */);
		~Contact();
		void	createContact();
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	PhoneNumber;
		std::string	Nickname;
		std::string	DarkestSecret;
};

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::createContact()
{
	std::cout << "Please, insert the contact's first name:" << std::endl;
	getline(std::cin, this->FirstName);
	std::cout << "Please, insert the contact's last name:" << std::endl;
	getline(std::cin, this->LastName);
	std::cout << "Please, insert the contact's phone number in the format (XX) X XXXX XXXX:" << std::endl;
	getline(std::cin, this->PhoneNumber);
	std::cout << "Please, insert the contact's nickname:" << std::endl;
	getline(std::cin, this->Nickname);
	std::cout << "Please, insert the contact's darkest secret:" << std::endl;
	getline(std::cin, this->DarkestSecret);
}