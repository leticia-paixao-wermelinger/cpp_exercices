/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:52:03 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/20 14:52:05 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib> // atoi

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

class BitcoinExchange
{
    private:
        std::map<std::string, float> dataBase;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

};