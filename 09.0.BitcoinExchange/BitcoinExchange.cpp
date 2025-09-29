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
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
	std::fstream fs;
    fs.open("data.csv", std::fstream::in);
    std::string line;
    this->_dataBase = std::map<std::string, float>();
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            std::getline(fs, line);
            if (line.length() == 0)
                break ;
			// std::cout << "Line: " << line << std::endl;
// 			std::cout << "line lengtn - 1 = " << line.length() - 1 << " que corresponde a " << line[line.length() - 1] << std::endl;
			std::string date = line.substr(0, 10);
			std::string value = line.substr(11, line.length() - 9);
			// std::cout << "Date = " << date << " and value = " << value << std::endl;
            _dataBase[date] = atof(value.c_str());
        }
        fs.close();
    }
    else
        std::cerr << RED << "Error: could not open _dataBase." << COLOR_END << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        _dataBase = src._dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	this->_dataBase.clear();
}

const std::map<std::string, float>&    BitcoinExchange::getDB()
{
    return this->_dataBase;
}

std::ostream & operator<<(std::ostream &out, BitcoinExchange &btcObj)
{
    std::map<std::string, float> db = btcObj.getDB();
    std::map<std::string, float>::iterator it;
    for (it = db.begin(); it != db.end(); ++it)
    {
        out << "Data: " << it->first << " e valor: " << it->second << std::fixed << std::setprecision(2) << std::endl;
    }
    return out;
}