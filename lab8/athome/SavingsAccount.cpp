#include <iostream>
#include <iomanip>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

namespace sict {


	SavingsAccount::SavingsAccount (double intialBalance, double rate) : Account(intialBalance)
	{
		if (rate > 0)
		{
			m_interest = rate;
		}
		else
			m_interest = 0;
	}


	// TODO: perform month end transactions
	void SavingsAccount::monthEnd()
	{
		double interestamount = 0;
		interestamount = balance() * m_interest;
		credit(interestamount);


	}
	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& os) const
	{
		double accountbalance = balance();
		os << "Account type: Savings" << endl;
	//	;
		os << "Balance: $" <<setprecision(2)<<fixed << accountbalance << endl;
		os << "Interest Rate (%): " << m_interest * 100 << endl;
		 

	}

}
