//
// -----------------------------------------------------------
//Suganya Maheswaran 
// 048298137
//
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>


#define NO_ERROR 0 // No error - the date is valid
#define CIN_FAILED 1 // istream failed on information entry
#define YEAR_ERROR 2 //Year value is invalid
#define MON_ERROR 3 // Month Value is invalid
#define DAY_ERROR 4 // Day value is invalid

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;


	class Date {

	private:
		int m_DateYear;
		int m_DateMonth;
		int m_DateDay;
		int m_ComparatorValue;
		int m_ErrorState; 
		int mdays(int, int)const;
		void errCode(int errorCode);
	
	public:
		Date();
		Date(int year, int month, int date);
		bool operator == (const Date& rhs) const;
		bool operator != (const Date& rhs) const;
		bool operator <  (const Date& rhs) const;
		bool operator >  (const Date& rhs) const;
		bool operator <= (const Date& rhs) const;
		bool operator >= (const Date& rhs) const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};


	std::ostream& operator<<(std::ostream& os, const Date& D);


	std::istream& operator>>(std::istream& is, Date& D);

	

}
#endif 