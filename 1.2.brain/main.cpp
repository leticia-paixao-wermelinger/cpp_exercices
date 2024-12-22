#include <iostream>
#include <string>
#include <ostream>

int main ()
{
    std::string str = "HI THIS IS BRAIN";
    std::string &stringREF = str;
	std::string *stringPTR = &str;

	std::cout <<  std::endl;
	std::cout << "Endereço da variável original: " << &str << std::endl;
	std::cout << "Endereço do Ponteiro: " << &stringPTR << std::endl;
	std::cout << "Endereço da Referência: " << &stringREF << std::endl;
	std::cout <<  std::endl;
	std::cout << "Valor da variável original: " << str << std::endl;
	std::cout << "Valor apontado por Ponteiro: " << stringPTR << std::endl;
	std::cout << "Valor apontado pela Referência: " << stringREF << std::endl;
	std::cout <<  std::endl;
}