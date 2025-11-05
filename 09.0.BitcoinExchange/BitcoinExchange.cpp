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
    // std::cout << "---------------- construtor --------------" << std::endl;
	std::fstream fs;
    fs.open("data.csv", std::fstream::in);
    std::string line;
    initAttributes();
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            std::getline(fs, line);
            if (line == "date,exchange_rate")
            continue;
            if (line.length() == 0)
            break ;
			// std::cout << "Line: " << line << std::endl;
            //std::cout << "line lengtn - 1 = " << line.length() - 1 << " que corresponde a " << line[line.length() - 1] << std::endl;
			std::string date = line.substr(0, 10);
			std::string value = line.substr(11, line.length() - 9);
			// std::cout << "Date = " << date << " and value = " << value << std::endl;
            (this->_dataBase)[date] = atof(value.c_str());
            // std::cout << (this->_dataBase)[date] << std::endl;
        }
        setBorder();
        fs.close();
        // std::cout << "Objeto criado:" << std::endl;
        // printAttributes();
    }
    else
        std::cerr << RED << "Error: could not open _dataBase." << COLOR_END << std::endl;
}

void    BitcoinExchange::initAttributes()
{
    this->_dataBase = std::map<std::string, float>();
    this->_firstYear = 0;
    this->_firstMonth = 0;
    this->_firstDay = 0;
    this->_lastYear = 0;
    this->_lastMonth = 0;
    this->_lastDay = 0;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        _dataBase = src.getDataBase();
        _firstYear = src.getFirstYear();
        _firstMonth = src.getFirstMonth();
        _firstDay = src.getFirstDay();
        _lastYear = src.getLastYear();
        _lastMonth = src.getLastMonth();
        _lastDay = src.getLastDay();
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	this->_dataBase.clear();
}

void    BitcoinExchange::setBorder()
{
    // std::cout << "Em setBorder()" << std::endl;
    std::map<std::string, float>::iterator F_it = getFirstDate();
    std::string firstDate = F_it->first;
    // std::cout << "firstDate = " << firstDate << std::endl;
    std::map<std::string, float>::iterator L_it = getLastDate();
    std::string lastDate = L_it->first;
    // std::cout << "firstDate = " << lastDate << std::endl;
    this->_firstYear = getYear(firstDate);
    // std::cout << "Salvou _firstYear = " << this->_firstYear << std::endl;
    this->_firstMonth = getMonth(firstDate);
    this->_firstDay = getDay(firstDate);
    this->_lastYear = getYear(lastDate);
    this->_lastMonth = getMonth(lastDate);
    this->_lastDay = getDay(lastDate);
}

float    BitcoinExchange::convertValue(std::string date, float value)
{
    std::string closestDate = findDate(date);
    // std::cout << "value = " << value << std::endl;
    // std::cout << "closest date = " << closestDate << std::endl;
    // std::cout << "getBtcPrice(closestDate) = " << getBtcPrice(closestDate) << std::endl;
    float   btcValue = getBtcPrice(closestDate);
    return btcValue * value; // fixed?
}

std::string    BitcoinExchange::findDate(std::string date)
{
    // std::cout << std::endl << "----------------- INICIO ---------------------" << std::endl;
    // std::cout << "Em findDate com date = " << date << std::endl;
    std::string closestDate;
    if (this->_dataBase.find(date) != this->_dataBase.end())
    {
        // std::cout << "Encontrou uma correspondência exata" << std::endl;
        // std::cout << std::endl << "----------------- FIM ---------------------" << std::endl;
        return date;
    }
    // std::cout << "Vai para get closest date" << std::endl;
    closestDate = getClosestDate(date);
    // std::cout << "Encontrou a data mais próxima sendo " << closestDate << std::endl;
    // std::cout << std::endl << "----------------- FIM ---------------------" << std::endl;
    return closestDate;
}

std::map<std::string, float>::iterator BitcoinExchange::getFirstDate()
{
    return (this->_dataBase).begin();
}

std::map<std::string, float>::iterator BitcoinExchange::getLastDate()
{
    // printAttributes();
    std::map<std::string, float>::iterator it = this->_dataBase.end();

    if (it == this->_dataBase.begin())
    return it;
    it--;
    // std::cout << "última posição = " << it->first << std::endl;
    return it;
}

int BitcoinExchange::getYear(std::string fullDate)
{
    // std::cout << "Em getYear, com " << fullDate << ", year = " << fullDate.substr(0, 4) << std::endl;
    return atoi(fullDate.substr(0, 4).c_str());
}

int BitcoinExchange::getMonth(std::string fullDate)
{
    // std::cout << "Em getMonth, com " << fullDate << ", month = " << fullDate.substr(5, 2) << std::endl;
    return atoi(fullDate.substr(5, 2).c_str());
}

int BitcoinExchange::getDay(std::string fullDate)
{
    // std::cout << "Em getDay, com " << fullDate << ", day = " << fullDate.substr(8, 2) << std::endl;
    return atoi(fullDate.substr(8, 2).c_str());
}

float   BitcoinExchange::getBtcPrice(std::string closestDate)
{
    //std::cout << std::endl << "(this->_dataBase)[closestDate] = " << (this->_dataBase)[closestDate] << std::endl;
    //std::cout << "closestDate = " << closestDate << std::endl;
    float btcValue = (this->_dataBase)[closestDate];
    return btcValue;
}

std::string BitcoinExchange::getClosestDate(std::string date)
{
    // std::cout << "Está em, getClosestDate() com date = " << date << std::endl;
    if (beforeFirstDate(date) == true)
    {
        // std::cout << "Entrou na validação de beforeFirstDate e vai retornar " << getFirstDate()->first << std::endl;
        return getFirstDate()->first;
    }
    else if (afterLastDate(date) == true)
    {
        // std::cout << "Entrou na validação de afterLastDate e vai retornar " << getLastDate()->first << std::endl;
        return getLastDate()->first;
    }
    (this->_dataBase)[date] = 0;
    std::map<std::string, float>::iterator it = (this->_dataBase).find(date);
    // std::cout << "Incluiu a data no map com valor 0 -> " << it->first << "," << it->second << std::endl;
    it--;
    // std::cout << "Fez it-- para encontrar a data mais próxima -> " << it->first << "," << it->second << std::endl;
    std::string ret = it->first;
    (this->_dataBase).erase(date);
    return ret;
}

bool    BitcoinExchange::beforeFirstDate(std::string date)
{
    std::string firstDate = getFirstDate()->first;
    // std::cout << "Em beforeFirstDate com date = " << date << " e _firstYear = " << this->_firstYear << std::endl;
    if (getYear(date) < this->_firstYear)
    {
        // std::cout << "Entrou na validação de getYear(date) sendo " << getYear(date) << " < " << this->_firstYear << "(_firstYear)" << std::endl;
        return true;
    }
    else if (getYear(date) == this->_firstYear)
    {
        // std::cout << "Entrou na validação de getYear(date) sendo " << getYear(date) << " == " << this->_firstYear << "(_firstYear)" << std::endl;
        if (getMonth(date) < this->_firstMonth)
        {
            // std::cout << "Entrou na validação de getMonth(date) sendo " << getMonth(date) << " < " << this->_firstMonth << "(_firstMonth)" << std::endl;
            return true;
        }
        else if (getMonth(date) == this->_firstMonth)
        {
            // std::cout << "Entrou na validação de getMonth(date) sendo " << getMonth(date) << " == " << this->_firstMonth << "(_firstMonth)" << std::endl;
            if (getDay(date) < this->_firstDay)
            {
                // std::cout << "Entrou na validação de getDay(date) sendo " << getDay(date) << " < " << this->_firstDay << "(_firstDay)" << std::endl;
                return true;
            }
        }
    }
    // std::cout << "Vai retornar falso" << std::endl;
    return false;
}

bool    BitcoinExchange::afterLastDate(std::string date)
{
    std::string lastDate = getLastDate()->first;
    if (getYear(date) > this->_lastYear)
        return true;
    else if (getYear(date) == this->_lastYear)
    {
        if (getMonth(date) > this->_lastMonth)
            return true;
        else if (getMonth(date) == this->_lastMonth)
        {
            if (getDay(date) > this->_lastDay)
                return true;
        }
    }
    return false;
}

const std::map<std::string, float>&    BitcoinExchange::getDB()
{
    return this->_dataBase;
}

void    BitcoinExchange::printAttributes()
{
    std::map<std::string, float>::iterator it = (this->_dataBase).begin();
    while (it != (this->_dataBase).end())
    {
        std::cout << it->first << " -> " << it->second << std::endl;
        it++;
    }
    std::cout << "Primeira data = " << this->_firstYear << "/" << this->_firstMonth << "/" << this->_firstDay << std::endl;
    std::cout << "Última data = " << this->_lastYear << "/" << this->_lastMonth << "/" << this->_lastDay << std::endl;
}

std::map<std::string, float>    BitcoinExchange::getDataBase() const
{
    return this->_dataBase;
}

int BitcoinExchange::getFirstYear() const
{
    return this->_firstYear;
}

int BitcoinExchange::getFirstMonth() const
{
    return this->_firstMonth;
}

int BitcoinExchange::getFirstDay() const
{
    return this->_firstDay;
}

int BitcoinExchange::getLastYear() const
{
    return this->_lastYear;
}

int BitcoinExchange::getLastMonth() const
{
    return this->_lastMonth;
}

int BitcoinExchange::getLastDay() const
{
    return this->_lastDay;
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