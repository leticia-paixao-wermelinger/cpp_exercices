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
//	std::string	newFilename;
//	std::fstream	myNewFile(std::string "oi");
	std::string	strReplaced;
	std::string	newStr;
	void	setFileName();
	void	setNewFileName();
	void	setStrToBeReplaced();
	void	setStrToRepĺace();
public:
	File();
	~File();
//	std::string	getFileName();
//	std::string	getStrToBeReplaced();
//	std::string	getStrToRepĺace();
	void	createNewFile();
	//void	fillNewFile();
//	std::string	getNewFile();
};
#endif