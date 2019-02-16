#ifndef CRA_ACCOUNT
#define CRA_ACCOUNT

using namespace std;

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {


	private:
		char m_lastName [max_name_length +1];
		char m_firstName[max_name_length +1];
		int	m_sin;
		int m_tax_yrs[max_yrs];
		double  m_balance[max_yrs]; 
			int taxYear = 0;


	public:
		void set(const char* familyName, const char* givenName, int Sin);
		bool isEmpty() const;
		void set(int year, double balance);
		void display() const;
		bool sinValid(); 


	};
}




#endif // !
