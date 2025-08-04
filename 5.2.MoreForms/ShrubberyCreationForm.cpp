/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:13 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:15 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", SC_SIGNGRADE, SC_EXECGRADE)
{
    setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", SC_SIGNGRADE, SC_EXECGRADE)
{
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("Shrubbery", SC_SIGNGRADE, SC_EXECGRADE)
{
    *this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (&src != this)
        setTarget(src.getTarget());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::setTarget(const std::string str)
{
    this->_target = str;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    try
    {
        AForm::execute(executor);
    }
    catch (const std::exception &e)
    {
        return ;
    }
    std::string fileName = this->getTarget() + "_shrubbery.txt";
    const char *fileNamePtr = fileName.c_str();
    //std::ofstream outputFile(fileNamePtr);
    std::fstream fs;
    fs.open(fileNamePtr, std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (fs.is_open())
    {
        fs << "          *          " << std::endl;
        fs << "         ***         " << std::endl;
        fs << "        *****        " << std::endl;
        fs << "      *********      " << std::endl;
        fs << "    *************    " << std::endl;
        fs << "  *****************  " << std::endl;
        fs << "*********************" << std::endl;
        fs << "         ***         " << std::endl;
        fs << "         ***         " << std::endl;
        fs << "         ***         " << std::endl;
        fs << "         ***         " << std::endl;
        fs << "         ***         " << std::endl;
    }
    else
    {
        std::cout << "Unable to open the file" << fileName << std::endl;
        return ;
    }
}

void    ShrubberyCreationForm::setAbstract()
{
    std::cout << "ShrubberyCreationForm não é uma classe abstrata" << std::endl;
}