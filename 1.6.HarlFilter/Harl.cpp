#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::complain(std::string level, std::string logLevel)
{

	std::string levels[4] = {"debug", "info", "warning", "error"}; // Primeiro declaramos o objeto. No caso, um array de 4 abjetos

	void (Harl::*complains[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // Depois declaramos um array de 4 ponteiros para funções membro da classe Harl
	level = toLower(level);

	logLevel = toLower(logLevel);
	switch (getIntLevel(logLevel))
	{
		case (DEBUG):
			(this->*complains[0])();
			(this->*complains[1])();
			(this->*complains[2])();
			(this->*complains[3])();
			break;
		case (INFO):
			(this->*complains[1])();
			(this->*complains[2])();
			(this->*complains[3])();
			break;
		case (WARNING):
			(this->*complains[2])();
			(this->*complains[3])();
			break;
		case (ERROR):
			(this->*complains[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

int	Harl::getIntLevel(std::string level)
{
	if (level == "debug")
		return DEBUG;
	else if (level == "info")
		return INFO;
	else if (level == "warning")
		return WARNING;
	else if (level == "error")
		return ERROR;
	return -1;
}

std::string	Harl::toLower( std::string str )
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
	return str;
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}