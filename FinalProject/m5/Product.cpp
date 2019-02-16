#include <fstream>
#include <iostream>
#include <cstring>
#include<string>
#include<iomanip>
#include"Product.h"
#include"ErrorState.h"
namespace AMA {

	void Product::name(const char* name)
	{
		/*if (m_nameptr != nullptr) {
			delete m_nameptr;
			m_nameptr = nullptr;
		}*/

		if (name != nullptr)
		{
			int size = strlen(name);
			if (size > max_name_length)
				size = max_name_length;
			m_nameptr = new char[size+1];
			strncpy(m_nameptr, name, size);
			m_nameptr[size] = '\0';
		}
	}

	const char* Product::name() const
	{
		if (m_nameptr!= nullptr)
			return m_nameptr;
		return nullptr;
	}
	const char* Product::sku() const
	{
		return m_productSku;
	}
	const char* Product::unit() const
	{
		return m_unitName;

	}
	bool Product::taxed() const
	{	
		return m_taxStatus;

	}
	double Product::price() const
	{
		return m_priceOfUnit;
	}
	double Product::cost() const
	{
		if (taxed())
			return(price()*(TAX_RATE + 1));
		else
			return price();

	}
	void Product::message(const char* msg) 
	{
		m_PError.message(msg);
	}

	bool Product::isClear() const
	{
		return m_PError.isClear();
	}
	Product::Product(char letter)
	{
			m_productType = letter;
			m_productSku[0] = '\0';
			m_unitName[0] = '\0';
			m_nameptr = nullptr;
			m_unitsOnHand = 0;
			m_unitsNeeded = 0;
			m_priceOfUnit = 0.00;
			m_taxStatus = false;
			//message("safe state");
	}
	Product::Product(const char* sku, const char* pName, const char* pUnit, int uHand, bool taxStatus, 
		double price, int qNeeded)
	{
			strncpy(m_productSku, sku, MAX_SKU_CHAR);
			strncpy(m_unitName, pUnit, MAX_UNIT_CHAR-1);
			name(pName);
			m_unitsOnHand = uHand;
			m_taxStatus = taxStatus;
			m_priceOfUnit = price;
			m_unitsNeeded = qNeeded;
	}

	Product& Product::operator=(const Product& product)
	{
		if (this != &product)
		{
			strncpy(m_productSku, product.m_productSku, max_sku_length);
			m_productSku[strlen(product.m_productSku) + 1] = '\0';
			strncpy(m_unitName, product.m_unitName, max_unit_length);
			m_unitName[strlen(product.m_unitName) + 1] = '\0';
				m_unitsOnHand = product.m_unitsOnHand;
			m_taxStatus = product.m_taxStatus;
			m_priceOfUnit = product.m_priceOfUnit;
			m_unitsNeeded = product.m_unitsNeeded;
			message(product.m_PError.message());
			//if(m_nameptr!= nullptr) // This is a weird check
			name(product.m_nameptr);
		}
		return *this;
	}


	Product::Product(const Product &copy)
	{
		if (copy.m_nameptr != nullptr)
		{
			m_nameptr = nullptr;
			*this = copy;//calls assignment operator

		}
	}
		
	 //what do i do with the pointer
	Product::~Product()
	{
		delete[] m_nameptr;
		m_PError.isClear();
	}
	std::fstream& Product::store(std::fstream& file, bool newLine) const
	
		{
		file << m_productType << ","
			<< m_productSku << "," 
			<< m_nameptr << ","
			<< m_unitName << "," 
		 <<  m_taxStatus <<','
			<< m_priceOfUnit<< ","
			<< m_unitsOnHand <<","
			<< m_unitsNeeded;
		if (newLine == true)
			file << std::endl;
		
		return file; 

		}

	
	std::fstream& Product::load(std::fstream& file) //what do i do with the pointer
	{

		if (file.is_open())
		{ 
			Product temp;
		char * name = new char[max_name_length + 1];
	
			file.getline(temp.m_productSku, max_sku_length, ',');
			file.getline(name, max_name_length, ',');
			temp.name(name);
			delete[] name;
			file.getline(temp.m_unitName, max_name_length, ',');
			file >> temp.m_taxStatus;
			file.ignore();
			file >> temp.m_priceOfUnit;
			file.ignore();
			file >> temp.m_unitsOnHand;
			file.ignore();
			file>> temp.m_unitsNeeded;
		
			*this = temp;
		}
		

		//delete [] temp.m_nameptr;
		return file;
	}

	
	std::ostream& Product::write(std::ostream& os, bool linear) const
	{
		if (m_PError.isClear())
		{
			if (linear)
			{
				os << std::setw(max_sku_length) << std::left << sku() << '|';
				if (m_nameptr != nullptr)
				{
					os << std::setw(20) << std::left << name() << '|';
				
				//os << std::setw(20) << std::left << " " << '|';
				os << std::setw(7) << std::fixed << std::setprecision(2) << std::right << cost() << '|';
				os << std::setw(4) << std::right << quantity() << '|'
					<< std::setw(10) << std::left << m_unitName << '|'
					<< std::setw(4) << std::right << qtyNeeded() << '|';

			
				}
				else {
					os << "Other branch" << std::endl;
				}
			}

			if (!linear)
			{
				os << " Sku: " << sku() << std::endl;
				if (m_nameptr != nullptr)
					os << " Name (no spaces): " << name() << std::endl;
				else
					os << " Name (no spaces): " << " " << std::endl;
				os << " Price: " << price() << std::endl;//Check this
				if (taxed())
					os << " Price after tax: " << cost() << std::endl;
				else
					os << " Price after tax: N/A" << std::endl;
				os << " Quantity on Hand: " << m_unitsOnHand << " "<< unit()<<std::endl;
				os << " Quantity needed: " << m_unitsNeeded  ;
			}
		} 
		else
		os <<m_PError.message();
		return os;
	}
	std::istream& Product::read(std::istream& is)
	{
	
			char sku[max_sku_length + 1];
			char* name = new char[max_name_length + 1];
			char unit[max_unit_length + 1];
			int  quantity, qtyNeeded;
			double price;
			char taxedL;
			bool taxable;
			std::cout << " Sku: ";
			is.getline(sku, max_sku_length, '\n');
		std::cout << " Name (no spaces): ";
		is.getline(name, max_name_length, '\n');
		
			std::cout << " Unit: ";
			is.getline(unit, max_unit_length, '\n');
			std::cout << " Taxed? (y/n): ";
			is >> taxedL;
			if (taxedL == 'Y' || taxedL == 'y')
				taxable = true;
			else if (taxedL == 'N' || taxedL == 'n')
				taxable = false;
			else {

				m_PError.message("Only (Y)es or (N)o are acceptable");
					is.setstate(std::ios::failbit);
					return is;
			}
			if (!is.fail())
			{
				std::cout << " Price: ";
				is >> price;
				if (is.fail())
				{
					m_PError.message("Invalid Price Entry");
					is.setstate(std::ios::failbit);
					return is;
				}
			}
			if (!is.fail())
			{
				std::cout << " Quantity on hand: ";
				is >> quantity;
				if (is.fail())
				{
					m_PError.message("Invalid Quantity Entry");
					is.setstate(std::ios::failbit);
					return is;
				}
			}
			if (!is.fail())
			{
				std::cout << " Quantity needed: ";
				is >> qtyNeeded;
				if (is.fail())
				{
					m_PError.message("Invalid Quantity Needed Entry");
					is.setstate(std::ios::failbit);
					return is;
				}
			}
				
			*this = Product(sku, name, unit, quantity, taxable, price, qtyNeeded);

			is.ignore();
			


			return is;
	}
	bool Product::operator==(const char* str) const
	{
		if(strncmp(this->sku(), str, max_sku_length)==0)
			return true;
			return false; 
	}
	double Product::total_cost() const
	{
		
		return this->cost()* this->m_unitsOnHand;

	}
	
	void Product::quantity(int units)
	{
		this->m_unitsOnHand = 0;
		this->m_unitsOnHand = units;
	}
	
	bool Product::isEmpty() const
	{
		if (m_productSku[0] == '\0' && m_unitName[0] == '\0' && m_nameptr == nullptr && m_unitsOnHand == 0
			&& m_unitsNeeded == 0 && m_priceOfUnit == 0.0)
			return true;
		return false;
	}

	int Product::qtyNeeded() const
	{
		
		return this->m_unitsNeeded;
	}
	int Product::quantity() const
	{
		
		return this->m_unitsOnHand;
	}
	bool Product::operator>(const char*rhs) const
	{
		int result = strncmp(this->sku(), rhs, max_sku_length);
		if (result > 0)
			return true;
		else
			return false;

	}

	bool Product::operator>(const iProduct& rhs) const
	{
		int str1 = strlen(this->name());
		int str2 = strlen(rhs.name());
		int size = 0;
		if (str1 > str2)
			 size = str1;
		else
			size = str2;
		return strncmp(m_nameptr, rhs.name(), size);

	}

	int Product::operator+=(int No_units)
	{
		if (No_units > 0)
		{
			this->m_unitsOnHand += No_units;
			return m_unitsOnHand;
		}
		return m_unitsOnHand;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& s)
	{
	
		s.write(os, true);
		return os;
	}
	
	std::istream& operator>>(std::istream& is, iProduct& s)
	{
		s.read(is);
		return is;
	}
	double operator+=(double& cost, const iProduct& P)
	{

		cost += P.total_cost();
		return cost;


	}

}
