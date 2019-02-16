#include "SavingsAccount.h" 
#include "Chequing.h"


namespace sict {

	// define interest rate
	//
	double interestRate = 0.05;
	double transactionFee = 0.5;
	double monthlyFee = 2.00;

	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* account, double balance)
	{
		
		iAccount* account1 = nullptr;
		if (account!= nullptr && account[0] == 'S')
		{
			account1 = new SavingsAccount(balance, interestRate);
			return account1;

		}
		else if (account != nullptr && account[0] == 'C')
		{
			account1 = new ChequingAccount(balance, transactionFee, monthlyFee);
			return account1;

		}
		else
			return nullptr;

	}






}
