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

RobotomyRequestForm::RobotomyRequestForm() : AForm(SIGNGRADE, EXECGRADE)
{
    setTarget("default");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(SIGNGRADE, EXECGRADE)
{
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(SIGNGRADE, EXECGRADE)
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
    // Makes some drilling noises, then informs that <target> has been robotomized
    // successfully 50% of the time. Otherwise, it informs that the robotomy failed.
}