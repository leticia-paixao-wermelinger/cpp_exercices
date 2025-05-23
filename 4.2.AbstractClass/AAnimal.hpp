/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:09:06 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:09:49 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal // Abstract Class
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);
	virtual ~AAnimal();
	std::string getType() const;
	void setType(std::string type);
	virtual void makeSound() const = 0;
};