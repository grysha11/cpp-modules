#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
}

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _amount = initial_deposit;
    _nbAccounts += 1;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ) {
    std::cout << "[19920104_091532]";
}


void	Account::displayAccountsInfos( void ) {

}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;
        std::cout << 
        return true;
    }
    return false;
}

int		Account::checkAmount( void ) const {
    return _amount;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
}
