#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

enum LogLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
public:
	Harl();
	~Harl();
	void		complain(std::string level, std::string logLevel);
private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
	std::string	toLower(std::string level);
	int			getIntLevel(std::string level);
};
#endif