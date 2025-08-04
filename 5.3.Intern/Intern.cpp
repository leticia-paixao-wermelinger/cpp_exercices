/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:54:13 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/08/03 19:54:17 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern & src)
{
	*this = src;
}

Intern & Intern::operator=(const Intern & src)
{
	(void)src;
	return (*this);
}

Intern::~Intern()
{}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string formOpts[3] = {"presidential request", "shrubbery request", "robotomy request"};
	AForm* (Intern::*formType[3])(std::string) = {&Intern::createPresidential, &Intern::createShrubbery, &Intern::createRobotomy};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formOpts[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formType[i])(target);
		}
	}
	std::cerr << "Intern couldn't find form: " << formName << std::endl;
	return NULL; 
}

AForm* Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}