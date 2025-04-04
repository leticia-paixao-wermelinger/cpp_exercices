#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::createContact()
{
	std::cout << "Please, insert the contact's first name:" << std::endl;
	std::cin >> this->FirstName;
	std::cout << "Please, insert the contact's last name:" << std::endl;
	std::cin >> this->LastName;
	std::cout << "Please, insert the contact's phone number in the format (XX) X XXXX XXXX:" << std::endl;
	std::cin >> this->PhoneNumber;
	std::cout << "Please, insert the contact's nickname:" << std::endl;
	std::cin >> this->Nickname;
	std::cout << "Please, insert the contact's darkest secret:" << std::endl;
	std::cin >> this->DarkestSecret;
}

int	Contact::checkName(std::string name)
{
	if (name == this->FirstName)
		return (true);
	return (false);
}

void	Contact::printListContact()
{
	std::cout << "Here is your contact information:" << std::endl;
	std::cout << "          ";
	std::cout << "First Name: " << this->FirstName << std::endl;
	std::cout << "          ";
	std::cout << "Last Name: " << this->LastName << std::endl;
	std::cout << "          ";
	std::cout << "Phone number: " << this->PhoneNumber << std::endl;
	std::cout << "          ";
	std::cout << "Nickname: " << this->Nickname << std::endl;
	std::cout << "          ";
	std::cout << "Darkest Secret: " << this->DarkestSecret << std::endl;
}

void	Contact::printTableContact(int index)
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << printLimitedString(this->FirstName);
	std::cout << "|" << std::setw(10) << printLimitedString(this->LastName);
	std::cout << "|" << std::setw(10) << printLimitedString(this->Nickname);
	std::cout << "|";
}

std::string	Contact::printLimitedString(std::string	str)
{
	if (str.size() <= 10)
		return (str);
	else
		return (str.substr(0, 9) + '.');
}