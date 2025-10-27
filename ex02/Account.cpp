/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:58:25 by fpedroso          #+#    #+#             */
/*   Updated: 2025/10/22 16:58:25 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int  Account::getNbAccounts( void ) { return _nbAccounts }
int  Account::getNbDeposits( void ) { return _totalNbDeposits }
int  Account::getNbWithdrawals( void ) { return _totalNbWithdrawals }

void    Account::displayAccountsInfos( void ) {

    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << ";";

    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
}

Account::Account( int initial_deposit ) : _amount(initial_deposit) { 
    
    }

Account::~Account( void );

Account::void	makeDeposit( int deposit );
Account::bool	makeWithdrawal( int withdrawal );
Account::int		checkAmount( void ) const;
Account::void	displayStatus( void ) const;