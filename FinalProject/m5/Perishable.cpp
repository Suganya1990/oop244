#include<iostream>
#include "Perishable.h"
#include "Product.h"
using namespace std;
namespace AMA {

	Perishable::Perishable() : Product::Product('P')
	{
		Date();
	}
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Product::store(file, false);
		file << ',' << m_expDate;
		if (newLine)
			file << endl;
		return file;

	}
	std::fstream& Perishable::load(std::fstream& file)
	{
		Product::load(file);
		file.ignore();
		m_expDate.read(file);
		file.ignore();
		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		Product::write(os, linear);
		if (isClear() & !isEmpty())
		{
			if (linear)
			{
				 m_expDate.write(os);
			}
			if (!linear)
			{
				os << "\n";
				os << " Expiry date: ";
				m_expDate.write(os);

			}

		}
		return os;

	}

	const Date& Perishable::expiry() const
	{
		return m_expDate; 
	}

	std::istream& Perishable::read(std::istream& is)
	{
		is.clear();
		Product::read(is);
	if(m_PError.isClear())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			m_expDate.read(is);
		
		}
		
			if (m_expDate.errCode() == CIN_FAILED)
			{
				m_PError.clear();
				Product::message("Invalid Date Entry");
			}
		if (m_expDate.errCode() == YEAR_ERROR)
			{
				Product::message("Invalid Year in Date Entry");
			}
		if (m_expDate.errCode() == MON_ERROR)
			{
				Product::message("Invalid Month in Date Entry");
			}
		 if (m_expDate.errCode() == DAY_ERROR)
			{
				Product::message("Invalid Day in Date Entry");
				}
		if(m_expDate.errCode())
				is.setstate(ios::failbit);
			
			else
			{
				m_PError.clear();
			}
		
		return is;
	}

	Perishable::~Perishable() {};
}
