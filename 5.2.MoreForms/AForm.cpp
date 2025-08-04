/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:57:01 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/29 15:57:02 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(STDGRADE) {}

AForm::~AForm() {}

AForm::AForm(const AForm & src) : _name(src._name), _signed(src._signed), _gradeToSign(validateGrade(src._gradeToSign)), _gradeToExec(validateGrade(src._gradeToExec)) {}

AForm & AForm::operator=(const AForm & src)
{
	if (this != &src)
		this->_signed = src.getSigned();
	return *this;
}

/*-------------------------- OTHER CONSTRUCTORS --------------------------*/

AForm::AForm(std::string name) : _name(name), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(STDGRADE) {}

AForm::AForm(std::string name, int gradeToSign)
	: _name(name), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(STDGRADE) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(validateGrade(gradeToExec)) {}

AForm::AForm(int gradeToSign, int gradeToExec) 
	: _name("Default"), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(validateGrade(gradeToExec)) {}

AForm::AForm(int gradeToSign)
	: _name("Default"), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(STDGRADE) {}

/*-------------------------- GETTERS --------------------------*/

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

/*-------------------------- OTHER METHODS --------------------------*/

bool AForm::beSigned(Bureaucrat const & B)
{
	if (this->getSigned() == true)
	{
		std::cout << "AForm " << this->getName() << " is already signed." << std::endl;
		return false;
	}
	if (B.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
	return true;
}

/*
* O ideal seria que tanto AForm como Bureaucrat utilizassem essa validação de
* um mesmo método isInRange, talvez de uma classe base ou utilitário.
* Da AForma que está, para atende ro exercício, não está muito limpo...
*/
int	AForm::validateGrade(int val)
{
	if (val <= 0)
		throw GradeTooHighException();
	else if (val > 150)
		throw GradeTooLowException();
	return val;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	std::cout << "execute de AForm" << std::endl;
	if (this->getSigned() == false)
	{
		unableToExec();
        throw(FormIsNotSigned());
	}
    else if (executor.getGrade() <= 0)
	{
		unableToExec();
        throw(GradeTooHighException());
	}
    else if (executor.getGrade() > this->getGradeToExec())
	{
		unableToExec();
        throw(GradeTooLowException());
	}
}

void	AForm::unableToExec() const
{
	std::cout << "Unable to execute form " << this->_name << " form because: ";
}

/*-------------------------- EXCEPTION CLASSES --------------------------*/

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade to AForm is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade to AForm is too low!";
}

const char* AForm::FormIsAlreadySigned::what() const throw()
{
    return "This form has already been signed!";
}

const char* AForm::FormIsNotSigned::what() const throw()
{
    return "This form hasn't been signed yet!";
}

/*-------------------------- OVERLOAD OPERATOR --------------------------*/

std::ostream& 	operator<<( std::ostream& out, AForm const & myAForm )
{
	out << "AForm Name: " << myAForm.getName() << ", Signed: " << (myAForm.getSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << myAForm.getGradeToSign()
		<< ", Grade to Execute: " << myAForm.getGradeToExec();
	return out;
}