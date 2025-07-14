/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExec;
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
        class   FormIsAlreadySigned : public std::exception
        {
            public:
                const char* what() const throw();
        };
        virtual void    setAbstract() = 0;
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm & src);
        AForm & operator=(const AForm & src);
        AForm(std::string name);
        AForm(std::string name, int gradeToSign);
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(int gradeToSign, int gradeToExec);
        AForm(int gradeToSign);
        std::string         getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;
        bool                beSigned( Bureaucrat const & B );
        void        execute(const Bureaucrat &executor) const;
};

std::ostream& 	operator<<( std::ostream& out, AForm const & myAForm ); // operator<< overload