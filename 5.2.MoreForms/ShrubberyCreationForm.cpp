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

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SIGNGRADE, EXECGRADE)
{
    setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(SIGNGRADE, EXECGRADE)
{
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(SIGNGRADE, EXECGRADE)
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
    // Create a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
}