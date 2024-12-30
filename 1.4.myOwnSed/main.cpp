#include "File.hpp"

int main ()
{
	File	objFile;
	const char	*filename = "oi";
	std::ofstream	myNewFile(filename);

	myNewFile.open(filename);
	myNewFile.close();
	//Make Replacement
	//objFile.createNewFile();
	//objFile.fillNewFile();
	//objFile.getNewFile();
	return (0);
}