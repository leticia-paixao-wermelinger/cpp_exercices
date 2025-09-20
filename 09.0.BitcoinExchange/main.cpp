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

bool lineIsValid(std::string line)
{
    
    return true;
}

std::map<std::string, float>    openCsv(std::string path)
{
    std::fstream fs;
    // difference between open and ifstream
    fs.open(path, std::fstream::in);
    std::string line;
    std::map<std::string, float>    dataBase;
    if (fs.is_open())
    {
        while (...)
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