/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:27 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:28 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    getName();
    getGrade();
    increaseGrade(); // example: from 3 to 2
    decreaseGrade(); // example: from 3 to 4
};