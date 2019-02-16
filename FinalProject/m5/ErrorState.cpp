#include<iostream>
#include <cstring>
#include "ErrorState.h"

	namespace AMA {

	ErrorState::ErrorState(const char* errorMessage)
	{
		if (errorMessage != nullptr)
		{
			int size = strlen(errorMessage);
			m_errorMsg = new char[size + 1];


			for (int i = 0; i < size; i++)
			{
				strncpy(this->m_errorMsg, errorMessage, size);

			}
			this->m_errorMsg[size] = '\0';
		}
		else
			this->m_errorMsg = nullptr;
	}

	//Destructor
	ErrorState::~ErrorState()
	{
		delete[] m_errorMsg;
		m_errorMsg = nullptr;
	}
	void ErrorState::clear()
	{
		this->~ErrorState();
	}
	bool ErrorState::isClear() const
	{
		if (m_errorMsg == nullptr)
			return true;
	
			return false;

	}
	void ErrorState::message(const char* str)
	{
		if (str == nullptr || str[0] == '\0')
		{
			delete[] m_errorMsg;
			m_errorMsg = nullptr;
		}
		else
		{
			if (this->m_errorMsg != nullptr)
				delete[] this->m_errorMsg;
			int size = strlen(str) + 1;
			m_errorMsg= new char[size];
			strncpy(this->m_errorMsg, str, size);
			m_errorMsg[size - 1] = '\0';
		}
		
	}

	const char* ErrorState::message() const
	{

		return m_errorMsg;

	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& errorInstance)
	{

		if (errorInstance.isClear()==false)
		{

			os << errorInstance.message();
		}
		return os;

	}
}