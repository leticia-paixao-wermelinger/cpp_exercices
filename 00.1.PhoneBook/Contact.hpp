#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <ostream>
#include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();
		void		createContact();
		int			checkName(std::string name);
		void		printListContact();
		void		printTableContact(int index);
		std::string	printLimitedString(std::string	str);
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	PhoneNumber;
		std::string	Nickname;
		std::string	DarkestSecret;
};
#endif