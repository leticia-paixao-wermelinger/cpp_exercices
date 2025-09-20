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

class BitcoinExchange
{
    public:
        std::map<std::string, float> dataBase;
    private:
        BitcoinExchange();
        BitcoinExchange(const );
        ~BitcoinExchange();
};