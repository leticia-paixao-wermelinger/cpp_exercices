#include "File.hpp"

File::File(char **argv, int av_flag)
{
	if (!setFileName(argv, av_flag))
		return ;
	setNewFileName();
	setStrToBeReplaced(argv, av_flag);
	setStrToRepĺace(argv, av_flag);
/*	LOG("DEBUG:");
	LOG("filename: " + this->filename);
	LOG("newFilename: " + this->newFilename);
	LOG("s1: " + this->strReplaced);
	LOG("s2: " + this->newStr);*/
}

File::~File()
{
}

int	File::setFileName(char **av, int av_flag)
{
	std::string cmd;
	std::fstream fs;

	if (av_flag == 1)
	{
		fs.open(av[1], std::fstream::in);
		if (fs.fail())
		{
			std::cout << "Erro ao abrir o arquivo " << av[1] << std::endl;
			return false;
		}
		fs.close();
		this->filename = av[1];
	}
	else
	{
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
	}
	return true;
}

void	File::setNewFileName()
{
	size_t	i = this->filename.find_last_of(".");

	this->newFilename = this->filename.substr(0, i) + ".replace";
}

void	File::setStrToBeReplaced(char **av, int av_flag)
{
	std::string cmd;

	if (av_flag == 1)
		this->strReplaced = av[2];
	else
	{
		while (cmd.size() == 0)
		{
			std::cout << "Favor inserir o que será substituído no arquivo: ";
			std::getline(std::cin, cmd);
			std::cout << std::endl;
		}
		this->strReplaced = cmd;
	}
}

void	File::setStrToRepĺace(char **av, int av_flag)
{
	std::string cmd;

	if (av_flag == 1)
		this->newStr = av[3];
	else
	{
		while (cmd.size() == 0)
		{
			std::cout << "Favor inserir o que será incluído no arquivo: ";
			std::getline(std::cin, cmd);
			std::cout << std::endl;
		}
		this->newStr = cmd;
	}
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