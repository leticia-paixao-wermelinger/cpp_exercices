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

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SC_SIGNGRADE, SC_EXECGRADE)
{
    setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(SC_SIGNGRADE, SC_EXECGRADE)
{
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(SC_SIGNGRADE, SC_EXECGRADE)
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

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::string fileName = this->getTarget() + "_shrubbery";
    const char *fileNamePtr = fileName.std::string::c_str();
    std::fstream fs;
    fs.open(fileNamePtr, std::fstream::in);
    if (fs.fail())
    {
        std::cout << "Unable to open the file" << fileName << std::endl;
    }
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

void    ShrubberyCreationForm::setAbstract()
{
    std::cout << "ShrubberyCreationForm não é uma classe abstrata" << std::endl;
}