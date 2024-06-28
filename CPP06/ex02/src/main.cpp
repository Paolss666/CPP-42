/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:53 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 15:59:36 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"

int main(void)
{
	Base    *base2;

	base2 = generate();
	identify(base2);
	identify(*base2);

	delete base2;
}