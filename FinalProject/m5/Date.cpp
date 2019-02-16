// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"
using namespace std;
namespace AMA {

  // number of days in month mon_ and year year_
 //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
  void Date::errCode(int errorCode)
  {
	  m_ErrorState = errorCode;
	
  }
  Date::Date()
  {
	  m_DateYear = 0;
	  m_DateMonth = 0;
	  m_DateDay = 0;
	  errCode(0);
	  m_ComparatorValue = 0;
  }
  Date::Date(int year, int month, int date)
  {
	  int daysinMonth;
	  if (year >= min_year && year <= max_year)
	  {
		  m_DateYear = year;
	  }
	  else
	  {
		  errCode(YEAR_ERROR);
		
	  }

	  if((year >= min_year && year <= max_year) && (month >= 1  && month <= 12))
	  {
		  m_DateMonth = month;

	  }
	  else
	  {
		  errCode(MON_ERROR);
		  *this = Date();
	  }

	daysinMonth =  mdays(m_DateMonth, m_DateYear);
	if ((year >= min_year && year <= max_year) && (month >= 1 && month <= 12) && (date >= 1 && date <= daysinMonth))
	{
		m_DateDay = date;
		errCode(NO_ERROR);
		m_ComparatorValue = m_DateYear * 372 + m_DateMonth * 13 + m_DateDay;
	}
	else
	{
		errCode(DAY_ERROR);
		*this = Date();
	}

  }
  bool Date::operator == (const Date& rhs) const
  {
	  if (this->m_ComparatorValue == rhs.m_ComparatorValue)
		  return true;
	  else 
		  return false;
  }
  bool Date::operator != (const Date& rhs) const

  {
	  if (this->m_ComparatorValue != rhs.m_ComparatorValue)
		  return true;
	  else
		  return false;

  }
  bool Date::operator > (const Date& rhs) const
  {
	  if (this->m_ComparatorValue > rhs.m_ComparatorValue)
		  return true;
	  else
		  return false;
  }
  bool Date::operator < (const Date& rhs) const
  {

	  if (this->m_ComparatorValue < rhs.m_ComparatorValue)
		  return true;
	  else
		  return false;
  }
  bool Date::operator <= (const Date& rhs) const
  {
	  if (this->m_ComparatorValue <=  rhs.m_ComparatorValue)
		  return true;
	  else
		  return false;
  }
  bool Date::operator >= (const Date& rhs) const
  {
	  if (this->m_ComparatorValue >= rhs.m_ComparatorValue)
		  return true;
	  else
		  return false;
  }
  int Date::errCode() const
  {
	  return m_ErrorState;
  }
  bool Date::bad() const
  {
	  if (m_ErrorState != NO_ERROR)
		  return true;
	  else
		  return false;
  }
  std::istream& Date::read(std::istream& istr)
  {
	  char c = '\0';
	  istr >> m_DateYear >> c >> m_DateMonth>>c >> m_DateDay;
	  if (istr.fail())
	  {
		  *this = Date();
		  errCode(CIN_FAILED);
	  }
	  else if (m_DateYear < min_year || m_DateYear > max_year)
	  {
		  *this = Date();
		  errCode(YEAR_ERROR);
	  }
	  else if (m_DateMonth < 1 || m_DateMonth > 12)
	  {
		  *this = Date();
		  errCode(MON_ERROR);
	  }

	  else if (m_DateDay < 1 || m_DateDay > mdays(m_DateMonth, m_DateYear))
	  {
		  *this = Date();
		  errCode(DAY_ERROR);
	  }
	  else
	  {
		  errCode(NO_ERROR);
	  }
	  return istr;
  }  
  std::ostream& Date::write(std::ostream& ostr) const
  {

	  ostr << m_DateYear << "/";
		  
	  if (m_DateMonth < 10) {
		  ostr << "0";
	  }
	  ostr << m_DateMonth << "/";
	  if (m_DateDay < 10) {
		  ostr << "0";
	  }
	  ostr << m_DateDay;
	  return ostr;
  }
  std::ostream& operator<<(std::ostream& os, const Date& D) {
	  return D.write(os);
  }
  std::istream& operator>>(std::istream& is, Date& D) {
	  return D.read(is);
  }
}
