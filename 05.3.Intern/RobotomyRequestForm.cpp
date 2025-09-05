/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:38 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:39 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", RR_SIGNGRADE, RR_EXECGRADE)
{
    setTarget("default");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", RR_SIGNGRADE, RR_EXECGRADE)
{
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("Robotomy", RR_SIGNGRADE, RR_EXECGRADE)
{
    *this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (&src != this)
        setTarget(src.getTarget());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::setTarget(const std::string str)
{
    this->_target = str;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    int n = rand();
    std::cout << "Drilling noises..." << std::endl;
    if (n <= RAND_MAX / 2)
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << this->getTarget() << "'s  robotomy failed." << std::endl;
}


void    RobotomyRequestForm::setAbstract()
{
    std::cout << "RobotomyRequestForm não é uma classe abstrata" << std::endl;
}