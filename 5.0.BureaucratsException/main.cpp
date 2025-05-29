/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:50 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:51 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

int main()
{
    Bureaucrat  me("Leticia", 5);

    std::cout << me << std::endl;
    for (int i = 0; i < 155; i++)
    {
        try
        {
            me.decreaseGrade();
            std::cout << GREEN << me << COLOR_END << std::endl;
        }
        catch (std::exception & e)
        {
            std::cout << RED << "Excption caught: " << e.what() << COLOR_END << std::endl;
        }
    }
    for (int j = 0; j < 160; j++)
    {
        try
        {
            me.increaseGrade();
            std::cout << GREEN << me << COLOR_END << std::endl;
        }
        catch (std::exception & e)
        {
            std::cout << RED << "Exception caught: " << e.what() << COLOR_END << std::endl;
        }
    }
    std::cout << GREEN << me << COLOR_END << std::endl;
    return 0;
}