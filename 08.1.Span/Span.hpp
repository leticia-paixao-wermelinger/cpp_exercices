/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:31:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/07 20:31:37 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Span
{
private:
	/* data */
public:
	Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
};