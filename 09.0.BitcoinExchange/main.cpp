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

#include <iomanip>

bool validDate(std::string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << RED << "Error: not a date." << COLOR_END << std::endl;
        return false;
    }
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    for (int i = 0; i < 9; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
        {
            std::cerr << RED << "Error: not a date." << COLOR_END << std::endl;
            return false;
        }
    }
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

bool validValue(std::string value)
{
    int dotCount = 0;
    for (size_t i = 0; i < value.length(); i++)
    {
        if (i == 0 && (value[i] == '+' || value[i] == '-'))
            continue;
        if (value[i] == '.')
            dotCount++;
        else if (!isdigit(value[i]))
        {
            std::cerr << RED << "Error: not a number." << COLOR_END << std::endl;
            return false;
        }
    }
    if (dotCount > 1)
    {
        std::cerr << RED << "Error: not a number." << COLOR_END << std::endl;
        return false;
    }
    long int val = atol(value.c_str());
    std::cout << "Valor = " << val << std::endl;
    if (val < 0)
    {
        std::cerr << RED << "Error: not a positive number." << COLOR_END << std::endl;
        return false;
    }
    else if (val > 1000)
    {
        std::cerr << RED << "Error: too large a number." << COLOR_END << std::endl;
        return false;
    }
    else if (val == 0 && value != "0")
        return false;
    return true;
}

bool lineIsValid(std::string line)
{
    if (line.size() == 0)
        return false;
    else if (line.find(" | ") == std::string::npos) // std::string::find = member function of std::string
    {
        std::cerr << RED << "Error: bad input => " << line << COLOR_END << std::endl;
        return false;
    }
    //std::cout << "line: " << line << std::endl;
    if (validDate(line.substr(0, 10)) == false)
    return false;
    //std::cout << "Date is valid" << std::endl;
    if (line.length() <= 13)
    {
        std::cerr << RED << "Error: bad input => " << line << COLOR_END << std::endl;
        return false;
    }
    else if (validValue(line.substr(13, line.length() - 13)) == false)
    return false;
    return true;
}

void    execute(std::string path)
{
    std::fstream fs;
    // difference between open and ifstream
    fs.open(path.c_str(), std::fstream::in);
    if (fs.is_open())
    {
        BitcoinExchange btc;
        // std::cout << btc;
        std::string line;
        while (!fs.eof())
        {
            std::getline(fs, line);
            if (lineIsValid(line) == true)
            {
                std::string lineDate = line.substr(0, 10);
                float       lineValue = atof((line.substr(13, line.length() - 13)).c_str());
                std::cout << lineDate;
                std::cout << " => ";
                std::cout << lineValue;
                std::cout << " = ";
                // print value * exchange rate
                float convertedValue = btc.convertValue(lineDate, lineValue);
                // std::cout << convertedValue << std::fixed << std::setprecision(2) << std::endl;
                std::cout << convertedValue << std::endl;
            }
        }
        fs.close();
    }
    else
        std::cerr << RED << "Error: could not open file." << COLOR_END << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: could not open file." << COLOR_END << std::endl;
        std::cerr << "Usage: ./btc <file.txt>" << std::endl;
        return 0;
    }
    execute(argv[1]);
    return 0;
}