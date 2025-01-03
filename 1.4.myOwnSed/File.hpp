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
	int	setFileName();
	void	setNewFileName();
	void	setStrToBeReplaced();
	void	setStrToRepĺace();
	void	replaceInFind(std::string &line);
public:
	File();
	~File();
	int	isThereFile();
	const char	*getNewFilename();
	void	saveAndReplaceToFile(std::ofstream	&myNewFile);
//	std::string	getStrToBeReplaced();
//	std::string	getStrToRepĺace();
};
#endif