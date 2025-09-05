/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:10:42 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:10:44 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain * _brain;
		void	cpyIdeas(const Cat & src);
	public:
		Cat( void );
		Cat( const Cat & src );
		~Cat( void );
		Cat & operator=( const Cat & src);
		void	makeSound() const;
		void	setIdea(std::string idea);
		int		getnIdeas() const;
		std::string	getIdea(int i) const;
		void	printIdea(int i);
		void	printAllIdeas();
		Brain *	getBrain() const;
		void	changeIdea(int i, std::string modifiedIdea);
};