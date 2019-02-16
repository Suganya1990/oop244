#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	double interestRate = 0.05;

	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* account, double balance)
	{
		
		SavingsAccount *account1 = nullptr;
		if (account!= nullptr && account[0] == 'S')
		{
			account1 = new SavingsAccount(balance, interestRate);
			return account1;

		}
		else
			return nullptr;

	}






}
