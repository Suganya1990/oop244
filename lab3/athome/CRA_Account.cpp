
#include <iostream>
#include <cmath>
#include<cstring>
#include "CRA_Account.h"
using namespace std;
namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
	
		if (sin > min_sin && sin < max_sin)
		{
			m_sin = sin;
			if (sinValid() && (familyName[0] != '\0') && (givenName[0] != '\0'))
			{
				strncpy(m_lastName, familyName, max_name_length);
			strncpy(m_firstName, givenName, max_name_length);

			}

			else{
				m_sin = 0;
			}



		}
		m_lastName[41] = '/0';
		m_firstName[41] = '/0';
	}


	bool CRA_Account::isEmpty() const
	{
		if (m_sin == 0){

			return true;
		}
		else
		{

			return false;
		}
	}
	void CRA_Account::display() const
	{
		int positive = 0;
		cout << "Family Name: " << m_lastName << endl;
		cout << "Given Name : " << m_firstName << endl;
		cout << "CRA Account: " << m_sin << endl;

		for (int taxYear = 0; taxYear < max_yrs; taxYear++)
		{
			if (m_balance[taxYear] > 2) {
				cout << "Year (" << m_tax_yrs[taxYear] << ") balance owing: " << m_balance[taxYear] << endl;
			}

			else if (m_balance[taxYear] < -2) {

				positive = fabs(m_balance[taxYear]);

				cout << "Year (" << m_tax_yrs[taxYear] << ") refund due: " << positive << endl;

			}
			else
			{
				cout << "Year (" << m_tax_yrs[taxYear] << ") No Balance owing or refund due!" << endl;
			}
		}
		if (m_sin == 0)
		{
			cout << "Account object is empty!" << "\n" << endl;
		}

	}


	void CRA_Account::set(int year, double balance)
	{
		//	if (sinValid() && taxYear >'0' && taxYear < max_yrs) 
		//	{		
		m_tax_yrs[taxYear] = year;

		m_balance[taxYear] = balance;

		//	}	
		taxYear++;


	}

	bool CRA_Account::sinValid()
	{
		int checkDigit = m_sin % 10;

		int totalSum1 = 0;
		int totalSum2 = 0;
		int sum = 0;
		int totalSum = 0;
		m_sin = m_sin - checkDigit;
		for (int i = 1; i <= 8; i++)
		{
			int tmp = pow(10, i);
			sum = ((m_sin / tmp) % 10);
			if (i % 2 == 0)
			{

				totalSum1 = totalSum1 + sum;
			}
			else {
				sum = sum * 2;
				if (sum > 9) {

					sum = sum / 10 + sum % 10;

				}
				totalSum2 = sum + totalSum2;
			}

		}
		totalSum = totalSum1 + totalSum2;

		if (((totalSum + checkDigit) % 10) == 0)
		{
			return true;

		}
		else
			return false;


	}

}


