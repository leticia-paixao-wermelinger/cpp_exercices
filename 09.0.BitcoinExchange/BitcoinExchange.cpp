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
            (this->_dataBase)[date] = atof(value.c_str());
        }
        setBorder();
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

void    BitcoinExchange::setBorder()
{
    std::map<std::string, float>::iterator F_it = getFirstDate();
    std::string firstDate = F_it->first;
    std::map<std::string, float>::iterator L_it = getLastDate();
    std::string lastDate = L_it->first;
    this->firstYear = getYear(firstDate);
    this->firstMonth = getMonth(firstDate);
    this->firstDay = getDay(firstDate);
    this->firstYear = getYear(lastDate);
    this->firstMonth = getMonth(lastDate);
    this->firstDay = getDay(lastDate);
}

float    BitcoinExchange::convertValue(std::string date, int value)
{
    std::string closestDate = findDate(date);
    std::cout << "value = " << value << std::endl;
    std::cout << "getBtcPrice(closestDate) = " << getBtcPrice(closestDate) << std::endl;
    float   btcValue = getBtcPrice(closestDate);
    return btcValue * value; // fixed?
}

std::string    BitcoinExchange::findDate(std::string date)
{
    std::string closestDate;
    if (this->_dataBase[date])
        return date;
    else
        // Incluir date no map, salvar a data anterior a essa posição em closestDate, excluir o date incluído.
        return getClosestDate(date);
    return closestDate;
}

std::map<std::string, float>::iterator BitcoinExchange::getFirstDate()
{
    return (this->_dataBase).begin();
}

std::map<std::string, float>::iterator BitcoinExchange::getLastDate()
{
    std::map<std::string, float>::iterator it = this->_dataBase.end();

    if (it == this->_dataBase.begin())
        return it;
    --it;
    return it;
}

int BitcoinExchange::getYear(std::string fullDate)
{
    return atoi(fullDate.substr(0, 4).c_str());
}

int BitcoinExchange::getMonth(std::string fullDate)
{
    return atoi(fullDate.substr(6, 8).c_str());
}

int BitcoinExchange::getDay(std::string fullDate)
{
    return atoi(fullDate.substr(10, 12).c_str());
}

float   BitcoinExchange::getBtcPrice(std::string closestDate)
{
    std::cout << std::endl << "(this->_dataBase)[closestDate] = " << (this->_dataBase)[closestDate] << std::endl;
    std::cout << "closestDate = " << closestDate << std::endl;
    float btcValue = (this->_dataBase)[closestDate];
    return btcValue;
}

std::string BitcoinExchange::getClosestDate(std::string date)
{
    if (beforeFirstDate(date) == true)
        return getFirstDate()->first;
    else if (afterLastDate(date) == true)
        return getLastDate()->first;
    (this->_dataBase)[date] = 0;
    std::map<std::string, float>::iterator it = (this->_dataBase).find(date);
    it--;
    std::string ret = it->first;
    (this->_dataBase).erase(date);
    return ret;
}

bool    BitcoinExchange::beforeFirstDate(std::string date)
{
    std::string firstDate = getFirstDate()->first;
    if (getYear(date) < this->firstYear)
        return true;
    else if (getYear(date) == this->firstYear)
    {
        if (getMonth(date) < this->firstMonth)
            return true;
        else if (getMonth(date) == this->firstMonth)
        {
            if (getDay(date) < this->firstDay)
                return true;
        }
    }
    return false;
}

bool    BitcoinExchange::afterLastDate(std::string date)
{
    std::string lastDate = getLastDate()->first;
    if (getYear(date) > this->lastYear)
        return true;
    else if (getYear(date) == this->lastYear)
    {
        if (getMonth(date) > this->lastMonth)
            return true;
        else if (getMonth(date) == this->lastMonth)
        {
            if (getDay(date) > this->lastDay)
                return true;
        }
    }
    return false;
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