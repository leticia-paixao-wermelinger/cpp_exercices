/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:21 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:23 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
    createGrade(DEFAULT);
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
    createGrade(DEFAULT);
}  

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    createGrade(grade);
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
    createGrade(grade);
}

void    Bureaucrat::createGrade(int grade)
{
    int RangeFit = isInRange(grade);
//    std::cout << "Em createGrande, RangeFit = " << RangeFit << std::endl;

    if (RangeFit == TOOHIGH)
        std::cout << "Vai chamar GradeTooHighException" << std::endl;
        // GradeTooHighException
    else if (RangeFit == TOOLOW)
        std::cout << "Vai chamar GradeTooLowException" << std::endl;
        // GradeTooLowException
    else
        this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::increaseGrade()
{
    if (getGrade() == 1)
        std::cout << "Vai chamar GradeTooHighException" << std::endl;
        // GradeTooHighException
    else
        this->_grade--;
}

void    Bureaucrat::decreaseGrade()
{
    if (getGrade() == 150)
        std::cout << "Vai chamar GradeTooLowException" << std::endl;
        // GradeTooLowException
    else
        this->_grade++;
}

int    Bureaucrat::isInRange(int val)
{
    if (val <= 0)
        return TOOHIGH;
    else if (val > 150)
        return TOOLOW;
    else
        return FIT;
}

std::ostream& 	operator<<( std::ostream& out, Bureaucrat const & myBureaucrat )
{
    out << myBureaucrat.getName() << ", bureaucrat grade " << myBureaucrat.getGrade();
    return out;
}