#include <iostream>
#include <string>
#include "Account.h"

/*Add amount to current balance*/
double Account::credit(double amount)
{	if(amount < 0){
		return balance;
	}
	balance = balance + amount;
	return balance;	
}
/*withdraws money from Account*/
double Account::debit(double amount)
{
	if(amount > balance)
	{
		cout << "Debit amount exceeded account balance" << endl;
		return balance;
	}
	else {
		balance = balance - amount;
		return balance;
	}	
}
/*returns the currenct balance */
double Account::getBalance()
{
	return balance;
}

/*Use to add both accounts in total*/
double Account::addAccountBalance(Account sumacc)
{
	balance = balance + sumacc.getBalance();
	return balance;

}

