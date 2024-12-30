#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <fstream>

#define LOG(x) std::cout << x << std::endl;

class File
{
private:
	std::string	filename;
	std::string	newFilename;
	std::string	strReplaced;
	std::string	newStr;
	void	setFileName();
	void	setNewFileName();
	void	setStrToBeReplaced();
	void	setStrToRepĺace();
public:
	File();
	~File();
	const char	*getNewFilename();
	void	saveAndReplaceToFile(std::ofstream	&myNewFile);
//	std::string	getStrToBeReplaced();
//	std::string	getStrToRepĺace();
};
#endif