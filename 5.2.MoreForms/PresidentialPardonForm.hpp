/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:53 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/06/02 12:01:54 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/*
*  Required grades: sign 25, exec 5
*  Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

#define SIGNGRADE 25
#define EXECGRADE 5PresidentialPardonFor

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		void		setTarget(const std::string str);
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		std::string	getTarget() const;
		void execute(const Bureaucrat &executor) const;
};