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
#include "Form.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

int main()
{
    try {
        // Teste de criação com notas inválidas
        Form invalidFormHigh("Top Secret", 0, 50); // deve lançar exceção
    } catch (std::exception &e) {
        std::cout << RED << "Exception (grade too high): " << e.what() << COLOR_END << std::endl;
    }

    try {
        Form invalidFormLow("Bottom Secret", 151, 50); // deve lançar exceção
    } catch (std::exception &e) {
        std::cout << RED << "Exception (grade too low): " << e.what() << COLOR_END << std::endl;
    }

    // Criação de burocratas e formulários válidos
    Bureaucrat alice("Alice", 42);
    Bureaucrat bob("Bob", 150); // menor cargo
    Bureaucrat clara("Clara", 1); // maior cargo

    Form formA("FormA", 50, 20);
    Form formB("FormB", 140, 100);
    Form formC("FormC", 1, 1);

    std::cout << GREEN << "\n--- ESTADO INICIAL ---" << COLOR_END << std::endl;
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << clara << std::endl;

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;
    std::cout << formC << std::endl;

    // Teste de assinatura de formulário
    std::cout << GREEN << "\n--- TENTANDO ASSINAR OS FORMULÁRIOS ---" << COLOR_END << std::endl;
    alice.signForm(formA); // deve assinar com sucesso
    bob.signForm(formA);   // deve falhar
    clara.signForm(formC); // deve assinar com sucesso
    bob.signForm(formB);   // deve assinar com sucesso (grau 150 é suficiente para assinar grau 140?)

    // Tentar assinar um formulário já assinado
    alice.signForm(formA); // deve informar que já está assinado

    std::cout << GREEN << "\n--- ESTADO FINAL DOS FORMULÁRIOS ---" << COLOR_END << std::endl;
    std::cout << formA << std::endl;
    std::cout << formB << std::endl;
    std::cout << formC << std::endl;
    return 0;
}