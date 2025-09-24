/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:50:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/20 14:51:22 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

#include <cstdlib> // atoi

bool validDate(std::string date)
{
    //std::cout << "date: " << date << std::endl;
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    for (int i = 0; i < 9; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

bool validValue(std::string value)
{
    std::cout << "value: " << value << std::endl;
    int dotCount = 0;
    for (size_t i = 0; i < value.length(); i++)
    {
        if (value[i] == '.')
            dotCount++;
        else if (!isdigit(value[i]))
        {
            std::cout << "Invalid character in value[" << i << "] = " << value[i] << std::endl;
            return false;
        }
    }
    if (dotCount > 1)
    {
        std::cout << "Invalid value format: too many dots = " << dotCount << std::endl;
        return false;
    }
    int val = atoi(value.c_str());
    if (val < 0 || val > 1000)
    {
        std::cout << "Invalid value range: " << val << std::endl;
        return false;
    }
    return true;
}

bool lineIsValid(std::string line)
{
    if (line.find(" | ") == std::string::npos) // std::string::find = member function of std::string
        return false;
    //std::cout << "line: " << line << std::endl;
    if (validDate(line.substr(0, 10)) == false)
        return false;
    //std::cout << "Date is valid" << std::endl;
    if (line.length() <= 13)
    {
        std::cout << "Invalid line length: " << line.length() << std::endl;
        return false;
    }
    else if (validValue(line.substr(13, line.length() - 13)) == false)
    {
        std::cout << "Value is not valid" << std::endl;
        return false;
    }
    return true;
}

std::map<std::string, float>    openCsv(std::string path)
{
    std::fstream fs;
    // difference between open and ifstream
    fs.open(path.c_str(), std::fstream::in);
    std::string line;
    std::map<std::string, float>    dataBase;
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            std::getline(fs, line);
            if (lineIsValid(line) == false)
            {
                std::cerr << "Invalid File lines" << std::endl;
                std::cerr << "all lines must be as follows: date | value" << std::endl;
                std::cerr << "In which date is in the following format: Year-Month-Day" << std::endl;
                fs.close();
                return dataBase;
            }
            std::cout << GREEN << "Valid line: " << COLOR_END << line << std::endl;
        }
        fs.close();
    }
    return dataBase;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: invalid number of arguments." << COLOR_END << std::endl;
        std::cerr << "Usage: ./btc <file.csv>" << std::endl;
        return 0;
    }
    std::map<std::string, float> dataBase = openCsv(argv[1]);
    if (dataBase.empty())
        return 0;
    return 0;
}