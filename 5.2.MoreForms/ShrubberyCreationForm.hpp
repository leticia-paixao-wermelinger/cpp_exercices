/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:09 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:10 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/*
*  Required grades: sign 145, exec 137
*  Creates a file <target>_shrubbery in the working directory and writes ASCII trees
*  inside it.
*/

#define SIGNGRADE 145
#define EXECGRADE 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		void		setTarget(const std::string str);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		std::string	getTarget() const;
		void execute(const Bureaucrat &executor) const;
};