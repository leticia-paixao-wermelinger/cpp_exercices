#include "File.hpp"

File::File()
{
	setFileName();
	setNewFileName();
	setStrToBeReplaced();
	setStrToRepĺace();
	LOG("DEBUG:");
	LOG("filename: " + this->filename);
	LOG("newFilename: " + this->newFilename);
	LOG("s1: " + this->strReplaced);
	LOG("s2: " + this->newStr);
}

File::~File()
{
}

void	File::setFileName() // Falta verificar existência do arquivo!
{
	std::string cmd;

//	LOG("Tamanho de cmd antes de getline: ");
//	LOG(cmd.size());
	while (cmd.size() == 0)
	{
		std::cout << "Favor inserir o nome de um arquivo existente nessa mesma pasta ou o caminho do arquivo desejado: ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
	}
//	LOG("Tamanho de cmd depois de getline: ");
//	LOG(cmd.size());
	
	this->filename = cmd;
//	LOG("Tamanho de filename: ");
//	LOG(this->filename.size());
}

void	File::setNewFileName() // Seria melhjor usar stem() ?
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

const char	*File::getNewFilename()
{
	const char	*name = this->newFilename.c_str();
	return (name);
}

void	File::saveAndReplaceToFile(std::ofstream	&myNewFile)
{
	//copy from original file
	myNewFile << "oi" << std::endl;
}