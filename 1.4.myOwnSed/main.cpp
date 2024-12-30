#include "File.hpp"

int main ()
{
	File	objFile;
	const char	*filename = "oi";
	std::fstream	myNewFile(filename);

	myNewFile.open(filename);
	//Make Replacement
	//objFile.createNewFile();
	//objFile.fillNewFile();
	//objFile.getNewFile();
	return (0);
}