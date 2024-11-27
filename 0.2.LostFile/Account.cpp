#include "Account.hpp"

int	Account::getNbAccounts( void )
{}

static int	Account::getTotalAmount( void )
{}

static int	Account::getNbDeposits( void )
{}

static int	Account::getNbWithdrawals( void )
{}

static void	Account::displayAccountsInfos( void )
{}

Account::Account(int initial_deposit)
{
    if (!this->_nbAccounts)
        this->_nbAccounts = 1;
    else
        this->_nbAccounts++;
    this->_totalAmount = initial_deposit;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;
    if (!this->_accountIndex)
        this->_accountIndex = 0;
    else
        this->_accountIndex++;
}

Account::~Account( void );

void	Account::makeDeposit( int deposit )
{}

bool	Account::makeWithdrawal( int withdrawal )
{}

int		Account::checkAmount( void ) const
{}

void	Account::displayStatus( void ) const
{}