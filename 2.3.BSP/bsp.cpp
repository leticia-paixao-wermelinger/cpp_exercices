/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:57:57 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/07 13:57:58 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (isRight(a, b, c) != isRight(a, b, point))
		return false;
	// Verificar se c está À direta ou à esquerda de AB
	// Verificar se point está À direita ou à esquerda de AB
	// Verificar de a resposta das 2 verificações acima batem. Se não bater, retornar erro.

	if (isRight(a, c, b) != isRight(a, c, point))
		return false;
	// Verificar se b está à direta ou à esquerda de AC
	// Verificar se point está à direta ou à esquerda de AC
	// Verificar de a resposta das 2 verificações acima batem. Se não bater, retornar erro.

	if (isRight(b, c, a) != isRight(b, c, point))
		return false;
	// Verificar se a está à direta ou à esquerda de BC
	// Verificar se point está à direta ou à esquerda de BC
	// Verificar de a resposta das 2 verificações acima batem. Se não bater, retornar erro.

	return true;
}

/*
* isRight - Verifica se o ponto está à direita ou à esquerda do segmento de reta
* formado pelos dois vértices.
* @vertex1: Primeiro vértice do segmento de reta.
* @vertex2: Segundo vértice do segmento de reta.
* @point: Ponto a ser verificado.
*
* Retorna true se o ponto está à direita do segmento de reta, false caso contrário.
*
* A fórmula utilizada é a seguinte:
* (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) < 0
*
* A fórmula é baseada na regra do produto vetorial, que determina a orientação
* relativa de três pontos no plano cartesiano.
*
* Vetor A → B: (x2 - x1, y2 - y1)
* dx1 = x2 - x1 → Direção no eixo x
* dy1 = y2 - y1 → Direção no eixo y
*
* Vetor A → C: (x3 - x1, y3 - y1)
* dx2 = x3 - x1 → Direção no eixo x
* dy2 = y3 - y1 → Direção no eixo y
*
* A subtração desses vetores nos dá um número escalar (não um vetor) que representa:
* A área do paralelogramo formado entre os vetores A→B e A→C
* E o sinal desse número diz a direção do giro de A→B para A→C
* Se o resultado for menor que 0, o ponto está à direita do segmento de reta.
* Se o resultado for maior que 0, o ponto está à esquerda do segmento de reta.
* Se o resultado for igual a 0, o ponto está sobre o segmento de reta.
*/

bool	isRight(Point const vertex1, Point const vertex2, Point const point)
{
	Fixed dx1 = vertex2.getx() - vertex1.getx();
    Fixed dy1 = vertex2.gety() - vertex1.gety();
    Fixed dx2 = point.getx() - vertex1.getx();
    Fixed dy2 = point.gety() - vertex1.gety();

	if ((dx1 * dy2) - (dy1 * dx2) < 0)
		return true;
	else
		return false;
}