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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

/*
* ShrubberyCreationForm - testar assinar com mais e com menos de 145.
* ShrubberyCreationForm - testar assinar fora da amplitude de 1 a 150.
* ShrubberyCreationForm - testar assinar já assinado.
* ShrubberyCreationForm - testar executar com mais e com menos de 137.
* ShrubberyCreationForm - testar executar fora da amplitude de 1 a 150.
* RobotomyRequestForm - testar assinar com mais e com menos de 72.
* RobotomyRequestForm - testar assinar fora da amplitude de 1 a 150.
* RobotomyRequestForm - testar assinar já assinado.
* RobotomyRequestForm - testar executar com mais e com menos de 45.
* RobotomyRequestForm - testar executar fora da amplitude de 1 a 150.
* PresidentialPardonForm - testar assinar com mais e com menos de 25.
* PresidentialPardonForm - testar assinar fora da amplitude de 1 a 150.
* PresidentialPardonForm - testar assinar já assinado.
* PresidentialPardonForm - testar executar com mais e com menos de 5.
* PresidentialPardonForm - testar executar fora da amplitude de 1 a 150.
*/

void testForm(AForm &form, Bureaucrat &signer, Bureaucrat &executor)
{
	std::cout << "\n===== Testando " << form.getName() << " =====\n";
	std::cout << "form signed = " << form.getSigned() << std::endl;
	try {
		signer.signForm(form);
	} catch (const std::exception &e) {
		std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
	}

	try {
		executor.executeForm(form);
	} catch (const std::exception &e) {
		std::cout << RED << "Erro ao executar: " << COLOR_END << e.what() << "\n";
	}
}

void separator(const std::string &msg)
{
	std::cout << "\n=== " << msg << " ===\n";
}

int main()
{
	/*
	// ShrubberyCreationForm tests
	separator("Shrubbery - Assinar com grade suficiente (<= 145)");
	{
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm form("Home");
		testForm(form, bob, bob);
	}

	separator("Shrubbery - Assinar com grade insuficiente (> 145)");
	{
		Bureaucrat joe("Joe", 146);
		ShrubberyCreationForm form("Yard");
		testForm(form, joe, joe);
	}

	separator("Shrubbery - Assinar com grade fora do intervalo (<1)");
	try {
		Bureaucrat invalid("Invalid", 0);
	} catch (const std::exception &e) {
		std::cout << "Erro ao criar Bureaucrat: " << e.what() << "\n";
	}

	separator("Shrubbery - Assinar com grade fora do intervalo (>150)");
	try {
		Bureaucrat invalid("Invalid", 151);
	} catch (const std::exception &e) {
		std::cout << "Erro ao criar Bureaucrat: " << e.what() << "\n";
	}
	*/
	separator("Shrubbery - Assinar já assinado");
	{
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm form("Garden");
		testForm(form, bob, bob); // Assina e executa uma vez
		testForm(form, bob, bob); // Tenta assinar e executar de novo
	}

	separator("Shrubbery - Executar com grade suficiente (<= 137)");
	{
		Bureaucrat exec("Exec", 130);
		ShrubberyCreationForm form("Park");
		try {
			form.beSigned(exec);
		} catch (const std::exception &e) {
			std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
		}
		testForm(form, exec, exec);
	}

	separator("Shrubbery - Executar com grade insuficiente (> 137)");
	{
		Bureaucrat lowExec("LowExec", 140);
		ShrubberyCreationForm form("Park");
		try {
			form.beSigned(lowExec);
		} catch (const std::exception &e) {
			std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
		}
		testForm(form, lowExec, lowExec);
	}

	// RobotomyRequestForm tests
	separator("Robotomy - Assinar com grade suficiente (<= 72)");
	{
		Bureaucrat roboSigner("Dr. Bot", 70);
		RobotomyRequestForm form("Target1");
		testForm(form, roboSigner, roboSigner);
	}

	separator("Robotomy - Assinar com grade insuficiente (> 72)");
	{
		Bureaucrat lowSigner("LowBot", 100);
		RobotomyRequestForm form("Target2");
		testForm(form, lowSigner, lowSigner);
	}

	separator("Robotomy - Assinar já assinado");
	{
		Bureaucrat bot("Bot", 50);
		RobotomyRequestForm form("Target3");
		testForm(form, bot, bot);
		testForm(form, bot, bot);
	}

	separator("Robotomy - Executar com grade suficiente (<= 45)");
	{
		Bureaucrat exec("ExecBot", 40);
		RobotomyRequestForm form("Target4");
		try {
			form.beSigned(exec);
		} catch (const std::exception &e) {
			std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
		}
		testForm(form, exec, exec);
	}

	separator("Robotomy - Executar com grade insuficiente (> 45)");
	{
		Bureaucrat exec("LowExecBot", 100);
		RobotomyRequestForm form("Target5");
		try {
			form.beSigned(exec);
		} catch (const std::exception &e) {
			std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
		}
		testForm(form, exec, exec);
	}

	// PresidentialPardonForm tests
	separator("Presidential - Assinar com grade suficiente (<= 25)");
	{
		Bureaucrat pres("Pres", 10);
		PresidentialPardonForm form("Alice");
		testForm(form, pres, pres);
	}

	separator("Presidential - Assinar com grade insuficiente (> 25)");
	{
		Bureaucrat lowPres("LowPres", 30);
		PresidentialPardonForm form("Bob");
		testForm(form, lowPres, lowPres);
	}

	separator("Presidential - Assinar já assinado");
	{
		Bureaucrat pres("Pres", 5);
		PresidentialPardonForm form("Charlie");
		testForm(form, pres, pres);
		testForm(form, pres, pres);
	}

	separator("Presidential - Executar com grade suficiente (<= 5)");
	{
		Bureaucrat exec("President", 1);
		PresidentialPardonForm form("Dana");
		try {
			form.beSigned(exec);
		} catch (const std::exception &e) {
			std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
		}
		testForm(form, exec, exec);
	}

	separator("Presidential - Executar com grade insuficiente (> 5)");
	{
		Bureaucrat exec("Vice", 10);
		PresidentialPardonForm form("Eve");
		try {
			form.beSigned(exec);
		} catch (const std::exception &e) {
			std::cout << RED << "Erro ao assinar: " << COLOR_END << e.what() << "\n";
		}
		testForm(form, exec, exec);
	}

    return 0;
}