/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:30:25 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/20 17:30:26 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
	int			_nIdeas;
public:
	Brain();
	~Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	void	newIdea(std::string idea);
	int		getnIdeas() const;
	std::string	getIdea(int i);
	void	changeIdea(int i, std::string modifiedIdea);
};