/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:31 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:32 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/*
*  Required grades: sign 72, exec 45
*  Makes some drilling noises, then informs that <target> has been robotomized
*  successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

#define SIGNGRADE 72
#define EXECGRADE 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		void		setTarget(const std::string str);
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		std::string	getTarget() const;
		void execute(const Bureaucrat &executor) const;
};