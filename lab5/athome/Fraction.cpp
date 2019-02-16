/*------------------------------
*Name: Suganya Maheswaran
*student ID: 048298137
*email: smaheswaran4@myseneca.ca
*date: June 20 2018
*
--------------------------------*/

#include<iostream>
#include"Fraction.h"

using namespace std;
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		
		m_numerator = 0;
		m_denominator = 0;

	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator)
	{
	
		if (numerator > 0 && denominator > 0)
		{
			m_denominator = denominator;
			m_numerator = numerator;
			reduce();
		}
		else {
			*this = Fraction();
		}


	}


	// TODO: implement the max query
	int Fraction::max() const

	{
		if (m_numerator > m_denominator)
			return m_numerator;
		else
			return m_denominator;
	};

	// TODO: implement the min query
	int Fraction::min() const
	{
		if (m_numerator < m_denominator)
			return m_numerator;
		else
			return m_denominator;
	};

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier


	void Fraction::reduce()
	{
		int temp =  gcd();
		m_numerator = m_numerator / temp;
		m_denominator = m_denominator / temp;

	};

	// TODO: implement the display query
	void Fraction::display() const

	{
		if (isEmpty())
			cout << "no fraction stored";
		else if (m_denominator == 1)
			cout << m_numerator;
		else
			cout << m_numerator << "/" << m_denominator;
	
	};
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{

		if (m_numerator == 0 && m_denominator == 0)
			return true;
		else
			return false;
	};


	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		if (!(this->isEmpty() || rhs.isEmpty()))
		{
			int n = (this->m_numerator * rhs.m_denominator) +
				(rhs.m_numerator * this->m_denominator);
			int d = (this->m_denominator * rhs.m_denominator);
			return Fraction(n, d);
		}
		else
			return Fraction();

	}
	Fraction Fraction::operator * (const Fraction& rhs) const
	{
		if (!(this->isEmpty() || rhs.isEmpty()))
		{
			int num = this->m_numerator * rhs.m_numerator;
			int deno = this->m_denominator * rhs.m_denominator;
			Fraction(num, deno).reduce();
			return Fraction(num, deno);
		}
		else
			return Fraction();

	};
	bool Fraction::operator==(Fraction& rhs) const

	{
		if ((!(this->isEmpty() && rhs.isEmpty())) && (this->m_numerator == rhs.m_numerator) && (this->m_denominator == rhs.m_denominator))
			return true;
		else
			return false;


	};
	bool Fraction::operator!= (Fraction& rhs) const
	{
		if ((!(this->isEmpty() && rhs.isEmpty())) && (this->m_numerator != rhs.m_numerator) && (this->m_denominator != rhs.m_denominator))
			return true;
		else
			return false;


	}
	Fraction& Fraction::operator+=(const Fraction& rhs)
	{
		
		if (!(this->isEmpty() || rhs.isEmpty()))
		{
			*this = *this + rhs;
			
			return *this;
		}
		else
		{
			return *this = Fraction();
		}
	}
	
}