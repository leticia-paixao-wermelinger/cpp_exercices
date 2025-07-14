/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:57 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:58 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(PP_SIGNGRADE, PP_EXECGRADE)
{
    setTarget("default");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(PP_SIGNGRADE, PP_EXECGRADE)
{
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(PP_SIGNGRADE, PP_EXECGRADE)
{
    *this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (&src != this)
        setTarget(src.getTarget());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::setTarget(const std::string str)
{
    this->_target = str;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}


void    PresidentialPardonForm::setAbstract()
{
    std::cout << "PresidentialPardonForm não é uma classe abstrata" << std::endl;
}