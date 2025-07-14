/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:27 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:28 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <exception>

class AForm; // Forward declaration to avoid circular dependency

enum    grade
{
    DEFAULT = 1,
    TOOLOW,
    FIT,
    TOOHIGH
};

class Bureaucrat //  exception classes do not have to be designed in Orthodox Canonical AForm
{
    private:
        const std::string   _name;
        int                 _grade; // From 150 to 1
        int                 isInRange(int val);
        void                createGrade(int grade);
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
        Bureaucrat();
        Bureaucrat(const Bureaucrat & src);
        Bureaucrat & operator=(const Bureaucrat & src);
        ~Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(int grade);
        std::string getName() const;
        int         getGrade() const;
        void        increaseGrade(); // example: from 3 to 2
        void        decreaseGrade(); // example: from 3 to 4
        void        signForm(AForm &src);
        void        executeForm(AForm const & form) const;
};

std::ostream& 	operator<<( std::ostream& out, Bureaucrat const & myBureaucrat ); // operator<< overload
