#ifndef CRA_ACCOUNT
#define CRA_ACCOUNT

using namespace std;

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	
	class CRA_Account {


	private:
		char m_lastName [max_name_length +1];
		char m_firstName[max_name_length +1];
		int	m_sin;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	
	};
}




#endif // !