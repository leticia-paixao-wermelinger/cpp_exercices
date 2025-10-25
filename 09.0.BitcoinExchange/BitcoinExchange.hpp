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
#include <cstring>
#include <cstdlib> // atoi

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

class BitcoinExchange
{
    private:
        std::map<std::string, float> _dataBase;
        int firstYear;
        int firstMonth;
        int firstDay;
        int lastYear;
        int lastMonth;
        int lastDay;
        std::string    findDate(std::string date);
        float   getBtcPrice(std::string closestDate);
        std::string getClosestDate(std::string date);
        void    setBorder();
        int getYear(std::string fullDate);
        int getMonth(std::string fullDate);
        int getDay(std::string fullDate);
        std::map<std::string, float>::iterator getFirstDate();
        std::map<std::string, float>::iterator getLastDate();
        bool    beforeFirstDate(std::string date);
        bool    afterLastDate(std::string date);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();
        const std::map<std::string, float>&    getDB();
        float    convertValue(std::string date, int value);
};

std::ostream &operator<<(std::ostream &out, BitcoinExchange &btcObj);