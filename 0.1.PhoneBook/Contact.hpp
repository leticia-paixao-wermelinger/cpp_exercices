#include <iostream>
#include <ostream>
#include <iomanip>

class Contact
{
	public:
		Contact(/* args */);
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