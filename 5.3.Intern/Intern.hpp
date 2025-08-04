/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:54:06 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/08/03 19:54:08 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *formType(std::string target);
    public:
        Intern();
        Intern(const Intern & src);
        Intern & operator=(const Intern & src);
        ~Intern();
		AForm	*makeForm(std::string formName, std::string target);
		AForm* createShrubbery(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createPresidential(std::string target);
};