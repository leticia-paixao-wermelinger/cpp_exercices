#include "File.hpp"
#include <filesystem>

void	no_args();
int	fileExists(const char *filename);

int main (int argc, char *argv[])
{
	int	av_flag = 0;

	if (argc != 1 && argc != 4)
	{
		std::cout << "Entrada inválida. Por favor, passe 3 argumentos:" << std::endl;
		std::cout << "Primeiro argumento: arquivo a ser copiado;" << std::endl;
		std::cout << "Segundo argumento: texto a ser substituído;" << std::endl;
		std::cout << "Terceiro argumento: texto que irá substituir o anterior." << std::endl;
		return 0;
	}
	else if (argc == 4)
		av_flag = 1;

	File	objFile(argv, av_flag);

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