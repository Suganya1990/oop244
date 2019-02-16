
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"
namespace sict {

	class ChequingAccount : public Account{
	double	m_transactionFee;
	double	m_monthlyFee;

	public:
		ChequingAccount(double, double, double); 
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;

	};

}

#endif