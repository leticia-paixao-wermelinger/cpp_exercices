/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:50 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:51 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

#include <iostream>

int main()
{
    Data *data = new Data();
    data->intValue = 42;
    data->floatValue = 3.14f;
    data->doubleValue = 42.42;
    data->charValue = 'a';

    std::cout << GREEN "Original Data:" COLOR_END << std::endl;
    std::cout << "Data address: " << data << std::endl;
    std::cout << "intValue: " << data->intValue << std::endl;
    std::cout << "floatValue: " << data->floatValue << std::endl;
    std::cout << "doubleValue: " << data->doubleValue << std::endl;
    std::cout << "charValue: " << data->charValue << std::endl;

    //uintptr_t raw = NULL;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << GREEN "Serialized Data:" COLOR_END << std::endl;
    std::cout << "raw: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << GREEN "Deserialized Data:" COLOR_END << std::endl;
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    std::cout << "intValue: " << deserializedData->intValue << std::endl;
    std::cout << "floatValue: " << deserializedData->floatValue << std::endl;
    std::cout << "doubleValue: " << deserializedData->doubleValue << std::endl;
    std::cout << "charValue: " << deserializedData->charValue << std::endl;

    //delete data;
    delete deserializedData;
    return 0;
}