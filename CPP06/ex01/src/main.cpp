/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 14:34:41 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"
#include "../incl/Data.hpp"

int main(void)
{
    Data *dt = new Data();
    Data *dt2;
    uintptr_t nb_raw;

    dt->nb = 10;
    
    {
        std::cout << "value dt: " << dt << std::endl;
        std::cout << "value dt->nb: " << dt->nb << std::endl;
        nb_raw = Serializer::serialize(dt);
        std::cout << "nb_raw: " << nb_raw << std::endl;
        dt2 = Serializer::deserialize(nb_raw);
        std::cout << "value dt2: " << dt2 << std::endl;
        std::cout << "dt2->nb: " << dt2->nb << std::endl;    
    }
    std::cout << std::endl << "*** TEST WITH SERIALIZE NULL ***" << std::endl;
    std::cout << "value dt: " << dt << std::endl;
    std::cout << "value dt->nb: " << dt->nb << std::endl;
    nb_raw = Serializer::serialize(NULL);
    std::cout << "nb_raw: " << nb_raw << std::endl;
    dt2 = Serializer::deserialize(nb_raw);
    std::cout << "value dt2: " << dt2 << std::endl;
    if (dt2)
    {
        std::cout << "value dt2->nb: " << dt2->nb << std::endl;
    }
    else
        std::cout << "dt2->nb is null " << std::endl;
    delete dt;
    return 0;
}