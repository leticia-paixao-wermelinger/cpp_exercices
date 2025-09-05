/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:56:57 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/29 15:56:58 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration to avoid circular dependency

#define STDGRADE 1

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExec; // Para que sevre?
        int                 validateGrade(int val);
        class   GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    public:
        Form();
        ~Form();
        Form(const Form & src);
        Form & operator=(const Form & src);
        Form(std::string name);
        Form(std::string name, int gradeToSign);
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(int gradeToSign, int gradeToExec);
        Form(int gradeToSign);
        std::string         getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;
        bool                beSigned( Bureaucrat const & B );
};

std::ostream& 	operator<<( std::ostream& out, Form const & myForm ); // operator<< overload