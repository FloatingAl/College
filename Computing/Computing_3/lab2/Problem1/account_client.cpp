#include <iostream>
#include <string>
#include "Account.h"

int main()
{	
	double with1,with2;
	double dep1, dep2;
	double temp1,temp2,sum;	
	
	Account bank1;
	Account bank2(100.0); 	

	cout << "How much will you withdraw from the first account ?"<< endl;	
	cin >> with1;
	bank1.debit(with1);
	cout << "First account current balance: " << bank1.getBalance() << endl;

	cout << "\n";
	cout << "How much will you withdraw from the second account ?"<< endl;
	cin  >> with2;

	
	bank2.debit(with2); 
	cout << "Second Account current balance: " << bank2.getBalance() << endl; 
	
	cout << "\n";
	cout << "How much will you deposit for the first account ? " << endl;
	cin >> dep1;
	
	cout << "How much will you deposit for the second account ? " << endl;
	cin >> dep2;
	
	bank1.credit(dep1); 
	bank2.credit(dep2);
	cout << "\n";
	cout << "First account current balance:"<<  bank1.getBalance() << endl; 
	cout << "\n";
	cout << "Second account current balance:"<< bank2.getBalance() << endl;
	cout << "\n";
	//call function, adds both accounts, stores to sum and prints it out
	sum = bank1.addAccountBalance(bank2);
		
	cout << "The sum of both accounts is: " << sum << endl;


}
