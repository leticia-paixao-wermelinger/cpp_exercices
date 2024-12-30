#include "File.hpp"

int main ()
{
	File	objFile;
	const char	*filename = objFile.getNewFilename();
	std::ofstream	myNewFile(filename);

	if (myNewFile.is_open())
	{
		// Preencher o arquivo
		objFile.saveAndReplaceToFile(myNewFile);
		//myNewFile << "oi" << std::endl;
		myNewFile.close();
	}
	else
		std::cout << "Erro ao criar o arquivo" << std::endl;
	return (0);
}