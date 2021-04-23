
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
	double balance;
public:
//default constructor
Account() 
{
  balance = 0;
}
//constructor
  Account(double balance_){
 
    if(balance >= 0){	
		balance = balance_;    	
    }
    else{
	balance = 0;
	cout << "The initial balance was invalid." << endl;
    }

  }

  double credit(double amount);
  double debit(double amount);
  double getBalance();
  double addAccountBalance(Account sumacc);

};
