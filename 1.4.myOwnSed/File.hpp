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
	int	setFileName(char **av, int av_flag);
	void	setNewFileName();
	void	setStrToBeReplaced(char **av, int av_flag);
	void	setStrToRepĺace(char **av, int av_flag);
	void	replaceInFind(std::string &line);
public:
	File(char **av, int av_flag);
	~File();
	int	isThereFile();
	const char	*getNewFilename();
	void	saveAndReplaceToFile(std::ofstream	&myNewFile);
//	std::string	getStrToBeReplaced();
//	std::string	getStrToRepĺace();
};
#endif