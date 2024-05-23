/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:02:01 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/23 20:18:24 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>

Account::Account(void){
    return ;
}

Account::Account(int initial_deposit): _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0),  _nbWithdrawals(0){
    
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;

    std::cout << "index: " << this->_accountIndex << "; amount:" << this->_amount << "; created" << std::endl;
    return ;
}

Account::~Account(void)
{
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;

    std::cout << "index: " << this->_accountIndex << "; amount:" << this->_amount << "; closed" << std::endl;
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
    return Account::_totalAmount;
}


int Account::getNbDeposits(void){
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return Account::_totalNbWithdrawals;
}


int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

void    Account::displayAccountsInfos(void)
{
    std::cout << "Account Infos " << std::endl;
    std::cout << "nb account: " << getNbAccounts() << "; ";
    std::cout << "nb deposits: " <<  getNbDeposits() << "; ";
    std::cout << "total amaunt: " << getTotalAmount() << "; "; 
    std::cout << "nb with draw w: " << getNbWithdrawals() << std::endl;
    return ;
}


void    Account::displayStatus(void) const
{
    std::cout << "Display status " << std::endl;
    std::cout << "index: " << _accountIndex << "; ";
    std::cout << "amout: " <<  _amount << "; ";
    std::cout << "deposits: " << _nbDeposits << "; "; 
    std::cout << "with drawals: " << _nbWithdrawals << std::endl;
}


int Account::checkAmount(void) const {
    if (this->_amount >= 0)
        return 1;
    return 0;
}

void Account::makeDeposit(int deposit)
{
    std::cout << "index: " << this->_accountIndex << "; ";
    std::cout << "personal amout: " << this->_amount << "; ";
    std::cout << "deposit: " << deposit << "; ";
    std::cout << "upgrade amout: " <<  this->_amount + deposit << "; ";
    std::cout << "deposit: " << this->_nbDeposits + 1 << std::endl;

    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    return ;
}


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;