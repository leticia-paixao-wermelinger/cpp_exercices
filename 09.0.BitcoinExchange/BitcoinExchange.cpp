/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:51:54 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/20 14:51:57 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::fstream fs;
    fs.open("data.csv", std::fstream::in);
    std::string line;
    this->dataBase = std::map<std::string, float>();
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            std::getline(fs, line);
//			std::cout << "Line: " << line << std::endl;
//			std::cout << "line lengtn - 1 = " << line.length() - 1 << " que corresponde a " << line[line.length() - 1] << std::endl;
			std::string date = line.substr(0, 10);
			std::string value = line.substr(11, line.length() - 10);
			std::cout << "Date = " << date << " and value = " << value << std::endl;
            dataBase[date] = atoi(value.c_str());
        }
        fs.close();
    }
    else
        std::cerr << RED << "Error: could not open database." << COLOR_END << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        dataBase = src.dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	this->dataBase.clear();
}