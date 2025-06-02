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

class RobotomRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomRequestForm();
		RobotomRequestForm(const std::string &target);
		RobotomRequestForm(const RobotomRequestForm &src);
		RobotomRequestForm &operator=(const RobotomRequestForm &src);
		~RobotomRequestForm();

		void execute(const Bureaucrat &executor) const override;
};