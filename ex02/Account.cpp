#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}
Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = this->getNbAccounts();
	this->_totalAmount += this->_amount;
	std::cout <<"index:" << this->_accountIndex <<";"
	<<"amount:"<<this->checkAmount() <<";" 
	<< "created" << std::endl;
	this->_nbAccounts++;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout <<"index:" << this->_accountIndex <<";"
	<<"amount:"<<this->checkAmount() <<";" 
	<< "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);

}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);

}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:"<< Account::getNbAccounts() <<";" \
	<< "total:"<< Account::getTotalAmount() <<";" \
	<< "deposits:" <<Account::getNbDeposits() <<";"\
	<< "withdrawals:" <<Account::getNbWithdrawals() << std::endl;

}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_totalAmount +=deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits ++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
	<< "p_amount:" << this->checkAmount() - deposit << ";"\
	<< "deposit:" << deposit << ";"\
	<< "amount:" << this->checkAmount() << ";"\
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	if (withdrawal > this->checkAmount())
	{
		std::cout << "index:" << this->_accountIndex << ";"\
		<< "p_amount:" << this->checkAmount() << ";"\
		<< "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals ++;
	this->_totalNbWithdrawals ++;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex << ";"\
		<< "p_amount:" << this->checkAmount() + withdrawal << ";"\
		<< "withdrawal:" << withdrawal << ";"\
		<< "amount:" << this->checkAmount() << ";"\
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout <<"index:" << this->_accountIndex << ";"\
	<< "amount:" << this->checkAmount() << ";"\
	<< "deposits:" << this->_nbDeposits << ";"\
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}
