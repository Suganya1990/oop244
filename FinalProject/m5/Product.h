#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <iostream>
#include <fstream>
#include "ErrorState.h"
#include "iProduct.h"


namespace AMA {

//Predefined consts  max numbers for each name (product sku, unit descriptor, product name) and tax rate
		const int MAX_SKU_CHAR = 7, max_sku_length = 7; //I had two names because Product and MyProduct is has two different const names
		const int MAX_UNIT_CHAR = 10, max_unit_length = 10;
		const int MAX_NAME_CHAR = 75, max_name_length = 75;
		const double TAX_RATE = .13;

	class Product : public iProduct {

		private:
			char m_productType; 
			char m_productSku[MAX_SKU_CHAR];
			char m_unitName[MAX_UNIT_CHAR+1];
			char* m_nameptr;
			int m_unitsOnHand;
			int m_unitsNeeded;
			double m_priceOfUnit;
			bool  m_taxStatus;
			
		protected:
			ErrorState m_PError;

			
			//stores the name in dynamically allocated memory
			void name(const char*);
			//returns the address of the name of product
			const char* name() const;
			//query returns the address of the C-style that holds the sku of the product
			const char* sku() const; 
			//returns the address of the C-style string that holds the unit of the product
			const char* unit() const;
			//returns tax status
			bool taxed() const;
			//returns the price of a single item
			double price() const;
			//returns the price of a single unit plus tax;
			double cost() const;
			//stores the message in the ErrorState object
			void message(const char*);
			//query returns true if the errorstte object is clear; false otherwise; 
			bool isClear() const;
		public:
			//0 to 1 constructor;
			Product(char type = 'N');
			//7 argument constrcuctor
			Product(const char* sku, const char* pName, const char* pUnit, int uHand = 0, bool taxStatus = 0,
				double price = 0.00, int qNeeded = 0);
			//copy constructor
			Product(const Product &);

			//assignment operator
			Product& operator = (const Product&);
			
			//Destructor
			~Product();
			//
			std::fstream& store(std::fstream& file, bool newLine = true) const;
			//
			std::fstream& load(std::fstream& file);
				//
			std::ostream& write(std::ostream& os, bool linear) const;

			std::istream& read(std::istream& is);

			bool operator==(const char*) const;
			//
			double total_cost() const;
			//
			void quantity(int);
			//
			bool isEmpty() const;
			//
			int qtyNeeded() const;
			//
			int quantity() const;
			//
			bool operator>(const char*) const;
			//
			bool operator>(const iProduct&) const;
			//
			int operator +=(int);
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);


}
#endif // ! _AMA_PRODUCT_H
