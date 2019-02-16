#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {
	

	//returns the current balance of the account
	double Account::balance() const
	{
		return m_balance;
	}

		//  constructor initializes account balance, defaults to 0.0 
	Account::Account(double balance)
	{
		if (balance > 0)
			m_balance = balance;
		else
			m_balance = 0;
	}

		// credit adds +ve amount to the balance 
	bool Account::credit (double credit)
	{
		if (credit > 0)
		{
			m_balance = m_balance + credit;
			return true;
		}
		else
			return false;
			
	}

		//  debit subtracts a +ve amount from the balance
	bool Account::debit(double debitAmount)
	{
		int temp = 0; 
		
		if (debitAmount > 0)
		{
			temp = m_balance;

			temp = temp - debitAmount;
				if (temp < 0)
				{
					return false;
				}
				else
				{
					m_balance = temp;
					return true;
				}
		}
		return false; 
	}





}