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

Form::Form(const Form & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

Form & Form::operator=(const Form & src)
{
	if (this != &src)
		this->_signed = src.getSigned();
	return *this;
}

Form::Form(std::string name) : _name(name), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(STDGRADE) {}

Form::Form(std::string name, int gradeToExec) 
	: _name(name), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(gradeToExec) {}

Form::Form(std::string name, int gradeToSign)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(STDGRADE) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {}

Form::Form(int gradeToSign, int gradeToExec) 
	: _name("Default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {}

Form::Form(int gradeToExec)
	: _name("Default"), _signed(false), _gradeToSign(STDGRADE), _gradeToExec(gradeToExec) {}

Form::Form(int gradeToSign)
	: _name("Default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(STDGRADE) {}

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

void Form::beSigned(Bureaucrat const & B)
{
	if (B.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& 	operator<<( std::ostream& out, Form const & myForm )
{
	out << "Form Name: " << myForm.getName() << ", Signed: " << (myForm.getSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << myForm.getGradeToSign()
		<< ", Grade to Execute: " << myForm.getGradeToExec();
	return out;
}