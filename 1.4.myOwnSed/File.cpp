#include "File.hpp"

File::File()
{
	if (!setFileName())
		return ;
	setNewFileName();
	setStrToBeReplaced();
	setStrToRepĺace();
/*	LOG("DEBUG:");
	LOG("filename: " + this->filename);
	LOG("newFilename: " + this->newFilename);
	LOG("s1: " + this->strReplaced);
	LOG("s2: " + this->newStr);*/
}

File::~File()
{
}

int	File::setFileName()
{
	std::string cmd;
	std::fstream fs;

	while (cmd.size() == 0)
	{
		std::cout << "Favor inserir o nome de um arquivo existente nessa mesma pasta ou o caminho do arquivo desejado: ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
	}
	fs.open(cmd.c_str(), std::fstream::in);
	if (fs.fail())
	{
		std::cout << "Erro ao abrir o arquivo " << cmd << std::endl;
		return false;
	}
	fs.close();
	this->filename = cmd;
	return true;
}

void	File::setNewFileName() // Seria melhor usar stem() ?
{
	size_t	i = this->filename.find_last_of(".");

	this->newFilename = this->filename.substr(0, i) + ".replace";
}

void	File::setStrToBeReplaced()
{
	std::string cmd;

	while (cmd.size() == 0)
	{
		std::cout << "Favor inserir o que será substituído no arquivo: ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
	}
	this->strReplaced = cmd;
}

void	File::setStrToRepĺace()
{
	std::string cmd;

	while (cmd.size() == 0)
	{
		std::cout << "Favor inserir o que será incluído no arquivo: ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
	}
	this->newStr = cmd;
}


int	File::isThereFile()
{
	if (this->filename.size() == 0)
		return false;
	return true;
}

const char	*File::getNewFilename()
{
	const char	*name = this->newFilename.c_str();
	return (name);
}

void	File::saveAndReplaceToFile(std::ofstream &myNewFile)
{
	std::ifstream	originalFile((this->filename).c_str());
	std::string	line;

//	originalFile.open(filename.c_str(), std::fstream::in); // Entender pq não pode dar open 2x
/*	if (!originalFile.is_open())
	{
		return ;
	}*/
	while (getline(originalFile, line))
	{
		while (line.find(this->strReplaced) != std::string::npos)
			replaceInFind(line);
		myNewFile << line << std::endl;
	}
	originalFile.close();
}

void	File::replaceInFind(std::string &line)
{
	int start = line.find(this->strReplaced);
	int end = start + this->strReplaced.size();
	
	line = line.substr(0, start) + this->newStr + line.substr(end);
}