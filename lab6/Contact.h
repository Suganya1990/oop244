#ifndef _SICT_CONTACT_H
#define _SICT_CONTACT_H
namespace sict {
	const int max_name_length = 20;
	class Contact {

		private:
			char m_name[max_name_length];
			long long* m_phonePTR; 
			long long m_currentSize;
		public:
			Contact();
			Contact(const char* name, const long long* phoneNumbers, int size);
			~Contact();
			bool isEmpty() const;
			void display() const;
			bool isValid(long long number) const;
			void phoneNumberDisplay(long long numbers) const;
	};

}
#endif // !_SICT_CONTACT_H
