/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:46 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/04/23 16:13:47 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);
void printError(Point const & p);
void printValidation(std::string name);

int main(void)
{
	Point const a(1, 2);
	Point const b(7, 2);
	Point const c(4, 7);

	std::cout << "Testes positivos:" << std::endl;
	Point const t1("t1", 3, 4);
	Point const t2("t2", 4, 6);
	Point const t3("t3", 5, 5);
	Point const t4("t4", 5, 3);
	Point const t5("t5", 3, 3);

//	std::cout << "True = " << true << std::endl;
//	std::cout << "False = " << false << std::endl;
	std::cout << "t1 = (" << t1.getx() << ", " << t1.gety() << ")" << std::endl;
	std::cout << "t2 = (" << t2.getx() << ", " << t2.gety() << ")" << std::endl;
	std::cout << "t3 = (" << t3.getx() << ", " << t3.gety() << ")" << std::endl;
	std::cout << "t4 = (" << t4.getx() << ", " << t4.gety() << ")" << std::endl;
	std::cout << "t5 = (" << t5.getx() << ", " << t5.gety() << ")" << std::endl;

	if (bsp(a, b, c, t1) != true)
		printError(t1);
	else
		printValidation(t1.getName());

	if (bsp(a, b, c, t2) != true)
		printError(t2);
	else
		printValidation(t2.getName());

	if (bsp(a, b, c, t3) != true)
		printError(t3);
	else
		printValidation(t3.getName());
	
	if (bsp(a, b, c, t4) != true)
		printError(t4);
	else
		printValidation(t4.getName());
	
	if (bsp(a, b, c, t5) != true)
		printError(t5);
	else
		printValidation(t5.getName());
	

	std::cout << "Testes negativos:" << std::endl;
	Point const t6("t6", 1, 3);
	Point const t7("t7", 3, 2);
	Point const t8("t8", 5, 7);
	Point const t9("t9", 5, 7);
	Point const t10("t10", 7, 2);

//	bool	ret = bsp(a, b, c, t6);
//	std::cout << "bsp(a, b, c, t6) = " << ret << std::endl;
	std::cout << "t6 = (" << t6.getx() << ", " << t6.gety() << ")" << std::endl;
	std::cout << "t7 = (" << t7.getx() << ", " << t7.gety() << ")" << std::endl;
	std::cout << "t8 = (" << t8.getx() << ", " << t8.gety() << ")" << std::endl;
	std::cout << "t9 = (" << t9.getx() << ", " << t9.gety() << ")" << std::endl;
	std::cout << "t10 = (" << t10.getx() << ", " << t10.gety() << ")" << std::endl;

	if (bsp(a, b, c, t6) == true)
		printError(t6);
	else
		printValidation(t6.getName());

	if (bsp(a, b, c, t7) == true)
		printError(t7);
	else
		printValidation(t7.getName());
	
	if (bsp(a, b, c, t8) == true)
		printError(t8);
	else
		printValidation(t8.getName());
	
	if (bsp(a, b, c, t9) == true)
		printError(t9);
	else
		printValidation(t9.getName());
	
	if (bsp(a, b, c, t10) == true)
		printError(t10);
	else
		printValidation(t10.getName());

	return 0;
}

void printError(Point const & p)
{
	std::cout << "Erro em " << p.getName() << "(" << p.getx() << ", " << p.gety() << ")." << std::endl;
}

void printValidation(std::string name)
{
	std::cout << name << " está correto!" << std::endl;
}