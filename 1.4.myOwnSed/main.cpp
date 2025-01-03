#include "File.hpp"
#include <filesystem>

int	fileExists(const char *filename);

int main ()
{
	File	objFile;
	const char	*filename = objFile.getNewFilename();
	if (fileExists(filename) == true)
	{
		std::cout << "Arquivo já existe" << std::endl;
		return 0;
	}
	std::ofstream	myNewFile(filename);

	if (myNewFile.is_open())
	{
		objFile.saveAndReplaceToFile(myNewFile);
		myNewFile.close();
	}
	else if (objFile.isThereFile() == false)
	{
		return 0;
	}
	else
		std::cout << "Erro ao criar o arquivo" << filename << std::endl;
	return (0);
}

int	fileExists(const char *filename)
{
	std::ifstream	fs(filename);

	if (fs.is_open())
	{
		fs.close();
		return true;
	}
	return false;
}