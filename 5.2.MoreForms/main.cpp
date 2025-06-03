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

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

int main()
{
    try {
        // Teste de criação com notas inválidas
        AForm invalidFormHigh("Top Secret", 0, 50); // deve lançar exceção
    } catch (std::exception &e) {
        std::cout << RED << "Exception (grade too high): " << e.what() << COLOR_END << std::endl;
    }

    try {
        AForm invalidFormLow("Bottom Secret", 151, 50); // deve lançar exceção
    } catch (std::exception &e) {
        std::cout << RED << "Exception (grade too low): " << e.what() << COLOR_END << std::endl;
    }

    // Criação de burocratas e Formulários válidos
    Bureaucrat alice("Alice", 42);
    Bureaucrat bob("Bob", 150); // menor cargo
    Bureaucrat clara("Clara", 1); // maior cargo

    AForm AFormA("AFormA", 50, 20);
    AForm AFormB("AFormB", 140, 100);
    AForm AFormC("AFormC", 1, 1);

    std::cout << GREEN << "\n--- ESTADO INICIAL ---" << COLOR_END << std::endl;
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << clara << std::endl;

    std::cout << AFormA << std::endl;
    std::cout << AFormB << std::endl;
    std::cout << AFormC << std::endl;

    // Teste de assinatura de Formulário
    std::cout << GREEN << "\n--- TENTANDO ASSINAR OS FormULÁRIOS ---" << COLOR_END << std::endl;
    alice.signAForm(AFormA); // deve assinar com sucesso
    bob.signAForm(AFormA);   // deve falhar
    clara.signAForm(AFormC); // deve assinar com sucesso
    bob.signAForm(AFormB);   // deve assinar com sucesso (grau 150 é suficiente para assinar grau 140?)

    // Tentar assinar um AFormulário já assinado
    alice.signAForm(AFormA); // deve inAFormar que já está assinado

    std::cout << GREEN << "\n--- ESTADO FINAL DOS AFormULÁRIOS ---" << COLOR_END << std::endl;
    std::cout << AFormA << std::endl;
    std::cout << AFormB << std::endl;
    std::cout << AFormC << std::endl;
    return 0;
}