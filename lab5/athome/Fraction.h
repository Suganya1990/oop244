/*------------------------------
*Name: Suganya Maheswaran
*student ID: 048298137
*email: smaheswaran4@myseneca.ca
*date: June 20 2018
*
--------------------------------*/

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
			Fraction operator * (const Fraction& rhs) const;
			bool operator==(Fraction& rhs) const;
			bool operator!= (Fraction& rhs) const; 
			Fraction& operator+=(const Fraction& rhs);
	};

}
#endif
