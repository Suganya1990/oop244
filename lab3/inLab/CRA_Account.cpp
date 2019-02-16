
#include <iostream> 
#include<cstring>
#include<cstring>
#include "CRA_Account.h"
using namespace std; 
namespace sict {



		void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
			bool valid = (sin >= min_sin && sin <= max_sin);
			if (valid)
			{
				m_sin = sin;
				strncpy(m_lastName, familyName, max_name_length);
					strncpy(m_firstName, givenName, max_name_length);
			}
			else
			{
				m_sin = 0;
			}


		}
		
		bool CRA_Account::isEmpty() const 
		{
			return (m_sin == 0);
		}

		void CRA_Account::display() const
		{
			cout << "Family Name: " << m_lastName <<  endl;
			cout << "Given Name : " << m_firstName <<  endl;
			cout << "CRA Account: " << m_sin << endl;


			if (m_sin == 0)
			{
				cout << "Account object is empty!" << "\n" << endl;
			}
		}
	}

