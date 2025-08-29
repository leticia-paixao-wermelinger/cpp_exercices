/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:52:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/08/28 19:52:04 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
//#include <cstdint>

struct Data
{
	int         intValue;
	float       floatValue;
	double      doubleValue;
	char        charValue;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer & src);
		Serializer & operator=(const Serializer & src);
	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};