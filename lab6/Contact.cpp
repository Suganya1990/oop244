#include <iostream>
#include <string>
#include <cstring>
#include "Contact.h"


using namespace std;

namespace sict {


	Contact::Contact()
	{
		m_name[0] = '\0';
		m_currentSize = 0;
		m_phonePTR = nullptr;

	}

	Contact::Contact(const char* name, const long long* phoneNumbers, int size)
	{


		m_phonePTR = nullptr;
		int counter = 0;
		if (name)
		{
			m_currentSize = 0;
			strncpy(m_name, name, max_name_length - 1);
			m_name[max_name_length - 1] = '\0';

			for (int i = 0; i < size; i++)
			{
				if (isValid(phoneNumbers[i]))
					m_currentSize++;
			}
			m_phonePTR = new long long[m_currentSize];
			for (int i = 0; i < size; i++)
			{
				if (isValid(phoneNumbers[i]))
				{
					m_phonePTR[counter] = phoneNumbers[i];
					counter++;
				}

			}

		}
		else
			*this = Contact();
	}

		Contact::~Contact()
		{
			delete[] m_phonePTR;
			m_phonePTR = nullptr;
		}
		bool Contact::isValid(long long numbers) const
		{

			string countryCodeFirstDigit;
			string countryCodeSecondDigit;
			string areaCodeFirstDigit;
			string areaCode;
			string phoneNumber;
			string phoneNumberFirstDigit;

			string phone;

			phone = to_string(numbers);
			int len = 0;
			len = phone.length();

			if (len >= 11 && len <=12)
			{ 
				if (len == 11)
			{

				phoneNumber = phone.substr(5, 6);
				phoneNumberFirstDigit = phone[4];
				areaCode = phone.substr(2, 2);
				areaCodeFirstDigit = phone[1];
				countryCodeSecondDigit = phone[0];
				countryCodeFirstDigit[0] = 0;


				//cout << "(+" << countryCodeFirstDigit << countryCodeSecondDigit << ")" << " " << areaCodeFirstDigit << areaCode << " " << phoneNumberFirstDigit << phoneNumber << endl;
				if (phoneNumberFirstDigit[0] != 0 && areaCodeFirstDigit[0] != 0 && countryCodeSecondDigit[0] != 0)
				{
					return true;
				}
				else
					return false;
			}

				else if (len == 12)
			{
				phoneNumber = phone.substr(6, 6);
				phoneNumberFirstDigit[0] = phone[5];
				areaCode = phone.substr(3, 2);
				areaCodeFirstDigit[0] = phone[2];
				countryCodeSecondDigit = phone[1];
				countryCodeFirstDigit[0] = phone[0];
				if (phoneNumberFirstDigit[0] != 0 && areaCodeFirstDigit[0] != 0 && countryCodeFirstDigit[0] != 0)
				{
				//	cout << "(+" << countryCodeFirstDigit << countryCodeSecondDigit << ")" << " " << areaCodeFirstDigit << areaCode << " " << phoneNumberFirstDigit << phoneNumber << endl;

					return true;
				}
				else
					return false;
			}
			}
			else
				return false;
		}

		void Contact::phoneNumberDisplay(long long numbers) const
		{

			string countryCodeFirstDigit;
			string countryCodeSecondDigit;
			string areaCodeFirstDigit;
			string areaCode;
			string phoneNumber2;
			string phoneNumber1;
			string phoneNumberFirstDigit;

			string phone;

			phone = to_string(numbers);
			int len = 0;
			len = phone.length();

	
				if (len == 11)
				{
					phoneNumber2 = phone.substr(7, 4);
					phoneNumber1 = phone.substr(5, 2);
					phoneNumberFirstDigit = phone[4];
					areaCode = phone.substr(2, 2);
					areaCodeFirstDigit = phone[1];
					countryCodeSecondDigit = phone[0];
					countryCodeFirstDigit[0] = 0;
					cout << "(+" << countryCodeFirstDigit << countryCodeSecondDigit << ")" << " "
						<< areaCodeFirstDigit << areaCode << " " << phoneNumberFirstDigit
						<< phoneNumber1 << "-" << phoneNumber2<< endl;

				
				}

				else if (len == 12)
				{
					phoneNumber2 = phone.substr(8, 4);
					phoneNumber1 = phone.substr(6,2);
					phoneNumberFirstDigit = phone[5];
					areaCode = phone.substr(3, 2);
					areaCodeFirstDigit = phone[2];
					countryCodeSecondDigit = phone[1];
					countryCodeFirstDigit = phone[0];
						cout << "(+" << countryCodeFirstDigit << countryCodeSecondDigit << ")" << " "
							<< areaCodeFirstDigit << areaCode << " " << phoneNumberFirstDigit 
							<< phoneNumber1 <<"-"<<phoneNumber2<< endl;

					
				}

		}

		bool Contact::isEmpty() const

		{
			if ((m_name == nullptr || m_name[0] == '\0') && m_phonePTR == nullptr && m_currentSize == 0)
			{

				return 0;
			}
			else {

				return 1;
			}
		}

		void Contact::display() const
		{
			if (!isEmpty())
				cout << "Empty contact!" << endl;
			else
			{
				cout << m_name << endl;
				for (int i = 0; i < m_currentSize; i++)
				{
					phoneNumberDisplay(m_phonePTR[i]);
				}
			}
		}

	}


