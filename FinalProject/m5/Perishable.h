#ifndef AMA_PERISHABLE_H
#define AMA_PRISHABLE_H
#include<iostream>
#include<fstream>
#include "Product.h"
#include "Date.h"



namespace AMA {

	class Perishable : public Product
	{

	private:
		Date m_expDate; 
	public:
		Perishable();
		~Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const; 
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const; 



	};


}
#endif // !1
