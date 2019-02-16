#ifndef AMA_ERROR_H
#define AMA_ERROR_H
#include<ostream>

namespace	AMA {

	class ErrorState {
	private:
		char *m_errorMsg;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;

	};

	std::ostream& operator<<(std::ostream& os, const ErrorState& errorInstance);


}

#endif // 
