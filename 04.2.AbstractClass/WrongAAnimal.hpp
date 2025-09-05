/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:11:09 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:11:11 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAAnimal
{
	protected:
		std::string _type;
	public:
		WrongAAnimal();
		WrongAAnimal(std::string type);
		virtual ~WrongAAnimal();
		WrongAAnimal(const WrongAAnimal &src);
		WrongAAnimal &operator=(const WrongAAnimal &src);
		virtual void makeSound() const;
		std::string	getType() const;
		void setType(std::string type);
};