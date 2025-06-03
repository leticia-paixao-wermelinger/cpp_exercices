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

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

Bureaucrat::Bureaucrat() : _name("default")
{
    createGrade(DEFAULT);
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name)
{
    createGrade(src.getGrade());
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & src)
{
    if (this != &src)
        this->_grade = src.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

/*-------------------------- OTHER CONSTRUCTORS --------------------------*/

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    createGrade(grade);
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
    createGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
    createGrade(DEFAULT);
}  

/*-------------------------- GETTERS --------------------------*/

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

/*-------------------------- GRADE METHODS --------------------------*/

void    Bureaucrat::createGrade(int grade)
{
    int RangeFit = isInRange(grade);

    if (RangeFit == TOOHIGH)
        throw(Bureaucrat::GradeTooHighException());
    else if (RangeFit == TOOLOW)
        throw(Bureaucrat::GradeTooLowException());
    else
        this->_grade = grade;
}

void    Bureaucrat::increaseGrade()
{
    if (getGrade() == 1)
        throw(Bureaucrat::GradeTooHighException());
    else
        this->_grade--;
}

void    Bureaucrat::decreaseGrade()
{
    if (getGrade() == 150)
        throw(Bureaucrat::GradeTooLowException());
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

/*-------------------------- OTHER METHODS --------------------------*/

void   Bureaucrat::signAForm(AForm &src)
{
    try
    {
        bool check = src.beSigned(*this);
        if (check == true)
            std::cout << this->getName() << " signed " << src.getName() << std::endl;
        else
            std::cout << this->getName() << " couldn’t sign " << src.getName() << " because it is already signed." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << src.getName() << " because: " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << "executed" << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

/*-------------------------- EXCEPTIONS --------------------------*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

/*-------------------------- OVERLOAD OPERATOR --------------------------*/

std::ostream& 	operator<<( std::ostream& out, Bureaucrat const & myBureaucrat )
{
    out << myBureaucrat.getName() << ", bureaucrat grade " << myBureaucrat.getGrade();
    return out;
}