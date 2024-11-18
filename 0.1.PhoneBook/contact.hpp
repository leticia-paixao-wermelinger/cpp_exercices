#include <string>

class Contact
{
	public:
		Contact(/* args */);
		~Contact();
	private:
		std::string	FirstName;
		std::string	LastName;
		int	PhoneNumber;
		std::string	Nickname;
		std::string	DarkestSecret;
};

Contact::Contact()
{
}

Contact::~Contact()
{
}
