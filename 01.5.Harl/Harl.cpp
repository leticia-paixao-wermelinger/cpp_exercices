#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

/*
The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!
*/
void	Harl::complain( std::string level )
{
	std::string levels[4] = {"debug", "info", "warning", "error"}; // Primeiro declaramos o objeto. No caso, um array de 4 abjetos

	void (Harl::*complains[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // Depois declaramos um array de 4 ponteiros para funções membro da classe Harl
	level = toLower(level);
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*complains[i])();
			return ;
		}
	}
}

std::string	Harl::toLower( std::string str )
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
	return str;
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}