//name:Suganya Maheswaran
//stduent id : 048298137
//email: smaheswaran4@myseneca.ca
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict{


 
	class Fraction {
		
	// TODO: declare instance variables 
		int m_numerator;
		int m_denominator; 
	// TODO: declare private member functions
	private:
		int max() const;
		int min() const;
		void reduce();
		int gcd() const; 
	



public:
	Fraction();
	Fraction(int numerator, int denominator);
	// TODO: declare public member functions
	bool isEmpty() const;
	void display() const;
	// TODO: declare the + operator overload
	Fraction operator+(const Fraction& rhs) const;
	};
}
#endif
