#include "File.hpp"

File::File()
{
	if (!setFileName())
		return ;
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

int	File::setFileName() // Falta verificar a existência do arquivo!
{
	std::string cmd;
	std::fstream fs;

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
	fs.open(cmd.c_str(), std::fstream::in);
	if (fs.fail())
	{
		std::cout << "Erro ao abrir o arquivo " << this->filename << std::endl;
		return false;
	}
	this->filename = cmd;
//	LOG("Tamanho de filename: ");
//	LOG(this->filename.size());
	return true;
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

void	File::saveAndReplaceToFile(std::ofstream &myNewFile)
{
/*	std::fstream fs;
	fs.open(this->filename.c_str(), std::fstream::in);
	if (fs.fail())
	{
		std::cout << "Erro ao abrir o arquivo " << this->filename << std::endl;
		return ;
	}*/
/*	if (!fs.is_open()) // dica do copilot
	{
		std::cout << "Erro ao abrir o arquivo " << this->filename << std::endl;
		exit(1);
	}*/
	//copy from original file
	myNewFile << "oi" << std::endl;
}