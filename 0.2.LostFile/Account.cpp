#include "Account.hpp"
#include <ostream>
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (0);
}

int	Account::getTotalAmount( void )
{
    return (0);
}

int	Account::getNbDeposits( void )
{
    return (0);
}

int	Account::getNbWithdrawals( void )
{
    return (0);
}

void	Account::displayAccountsInfos( void )
{
    // Imprimir: [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals;
    std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
    if (!this->_nbAccounts)
        this->_nbAccounts = 1;
    else
        this->_nbAccounts++;
    this->_totalAmount += initial_deposit;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;
    this->_accountIndex = this->_nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
}

Account::~Account( void )
{
    // [19920104_091532] index:0;amount:47;closed
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    // [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    // [19920104_091532] index:0;p_amount:47;withdrawal:refused
    // [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    (void)withdrawal;
     _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    if (this->_amount >= withdrawal)
    {
        std::cout << ";withdrawal:" << withdrawal;
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";amount:" << this->_amount;
        std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
    }
    else
        std::cout << ";withdrawal:refused";
    std::cout << std::endl;
    return (0);
}

int		Account::checkAmount( void ) const
{
    return (0);
}

void	Account::displayStatus( void ) const
{
    // Imprimir: [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
//    time_t  timestamp;
  //  time(&timestamp);
    //strftime(&timestamp);
    //std::cout << "[" << ctime(&timestamp) << "] ";
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer, 80,"[%Y%m%d_%H%M%S] ",timeinfo);
    std::cout << buffer;
}