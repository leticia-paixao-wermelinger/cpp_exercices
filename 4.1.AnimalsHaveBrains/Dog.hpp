/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:10:36 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:10:37 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain * _brain;
		void	cpyIdeas(const Dog & src);
	public:
		Dog( void );
		Dog( const Dog & src );
		~Dog( void );
		Dog & operator=( const Dog & src);
		void	makeSound() const;
		void	setIdea(std::string idea);
		int		getnIdeas() const;
		std::string	getIdea(int i) const;
		void	printIdea(int i);
		void	printAllIdeas();
		Brain *	getBrain() const;
		void	changeIdea(int i, std::string modifiedIdea);
};