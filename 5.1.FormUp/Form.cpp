/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:57:01 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/29 15:57:02 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(STDGRADE) {}

Form::~Form() {}

Form::Form(const Form & src) : _name(src._name), _signed(src._signed), _gradeToSign(validateGrade(src._gradeToSign)), _gradeToExec(validateGrade(src._gradeToExec)) {}

Form & Form::operator=(const Form & src)
{
	if (this != &src)
		this->_signed = src.getSigned();
	return *this;
}

Form::Form(std::string name) : _name(name), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(STDGRADE) {}

Form::Form(std::string name, int gradeToSign)
	: _name(name), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(STDGRADE) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(validateGrade(gradeToExec)) {}

Form::Form(int gradeToSign, int gradeToExec) 
	: _name("Default"), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(validateGrade(gradeToExec)) {}

Form::Form(int gradeToSign)
	: _name("Default"), _signed(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(STDGRADE) {}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

bool Form::beSigned(Bureaucrat const & B)
{
	if (this->getSigned() == true)
	{
		std::cout << "Form " << this->getName() << " is already signed." << std::endl;
		return false;
	}
	if (B.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
	return true;
}

std::ostream& 	operator<<( std::ostream& out, Form const & myForm )
{
	out << "Form Name: " << myForm.getName() << ", Signed: " << (myForm.getSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << myForm.getGradeToSign()
		<< ", Grade to Execute: " << myForm.getGradeToExec();
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade to Form is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade to Form is too low!";
}


/*
* O ideal seria que tanto Form como Bureaucrat utilizassem essa validação de 
* um mesmo método isInRange, talvez de uma classe base ou utilitário.
* Da forma que está, para atende ro exercício, não está muito limpo...
*/
int	Form::validateGrade(int val)
{
	if (val <= 0)
		throw GradeTooHighException();
	else if (val > 150)
		throw GradeTooLowException();
	return val;
}