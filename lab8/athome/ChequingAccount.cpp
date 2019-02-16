#include <iostream>
#include <iomanip>
#include "Account.h"
#include "ChequingAccount.h"
using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double intialBalance, double transactionFee, double montlyFee) : Account(intialBalance)
	{
		if (transactionFee > 0)
			m_transactionFee = transactionFee;
		else
			m_transactionFee = 0;
		if (montlyFee > 0)
			m_monthlyFee = montlyFee;
		else
			m_monthlyFee = 0; 

	}
	bool ChequingAccount::credit(double creditAmount)
	{
		if (creditAmount > 0)
		{
			Account::debit(m_transactionFee);

			Account::credit(creditAmount);
			
			return true;
		
		}
		else return false;
	}
	bool ChequingAccount::debit(double balance)
	{
		if (balance > 0)
		{
			Account::debit(balance);
			Account::debit(m_transactionFee);

			
			return true;

		}
		else
			return false;
	}
	void ChequingAccount::monthEnd()
	{
	Account::debit(m_transactionFee);
		Account::debit(m_monthlyFee);

	}
	void ChequingAccount::display(std::ostream& os) const
	{
double accountbalance = balance();
		os << "Account type: Chequing" << endl;

		os << "Balance: $" <<fixed<<setprecision(2) << accountbalance << endl;
		os << "Per Transaction Fee: " << m_transactionFee<< endl;
		os << "Monthly Fee: " << m_monthlyFee << endl;


	}

}
