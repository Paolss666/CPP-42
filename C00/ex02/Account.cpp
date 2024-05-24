/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:02:01 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/24 15:02:44 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(void){
    return ;
}

Account::Account(int initial_deposit): _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0),  _nbWithdrawals(0){
    
    _displayTimestamp();
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;

    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

Account::~Account(void)
{
    _displayTimestamp();
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;

    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
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
    _displayTimestamp();
    std::cout
        << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
        << std::endl;

    return ;
}


void    Account::displayStatus(void) const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";"
    << "withdrawals:" << _nbWithdrawals << std::endl;
}


int Account::checkAmount(void) const {
    if (this->_amount >= 0)
        return 1;
    return 0;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";";
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << "deposit:" << deposit << ";" << "amount:" << this->_amount << ";" << "nb_deposits:" << "1" << std::endl;
    return ;
}

bool    Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount << ";"
			  << "withdrawal:";
	this->_amount -= withdrawal;
	if (checkAmount() <= 0)
	{
		this->_amount += withdrawal;
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";";
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}


void    Account::_displayTimestamp(void)
{
    std::time_t   time_stamp = std::time(NULL);
    std::tm* currentTime =  std::localtime(&time_stamp);
    
    
    std::cout << "[" << (currentTime->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (currentTime->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << (currentTime->tm_mday) << "_"
	<< std::setw(2) << std::setfill('0') << (currentTime->tm_hour)
	<< std::setw(2) << std::setfill('0') << (currentTime->tm_min)
	<< std::setw(2) << std::setfill('0') << (currentTime->tm_sec) << "] ";
}


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;