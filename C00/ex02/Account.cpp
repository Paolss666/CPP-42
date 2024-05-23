/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:02:01 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/23 17:31:17 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>

Account::Account(int initial_deposit ){
    
    initial_deposit = 0;
    std::cout << "CALLED" << std::endl;
    return ;
}

Account::~Account(void)
{
    std::cout << "Destruct CALLED" << std::endl;
    return ;
}


// Nella definizione di funzioni statiche 
// all'interno di una classe,
// non è necessario utilizzare this-> perché
// this si riferisce all'oggetto corrente,
// mentre le funzioni statiche non sono associate
//ad un'istanza specifica della classe.
//Le funzioni statiche operano solo sulle variabili
//statiche della classe e non possono
//accedere alle variabili non statiche
//o ai metodi di istanza.

int Account::getTotalAmount(void){
    return _totalAmount;
}


int Account::getNbDeposits(void){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return _nbAccounts;
}


int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

void    Account::displayAccountsInfos(void)
{
    std::cout << "Account Infos " << std::endl;
    std::cout << _nbAccounts << std::endl;
    std::cout << _totalAmount << std::endl;
    std::cout << _totalNbDeposits << std::endl; 
    std::cout << _totalNbDeposits << std::endl;
    return ;
}