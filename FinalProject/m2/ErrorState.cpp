#include<iostream>
#include <cstring>
#include<string>
#include "ErrorState.h"

using namespace std;

	namespace AMA {

	ErrorState::ErrorState(const char* errorMessage)
	{
		if (errorMessage != nullptr)
		{
			m_errorMsg = nullptr;
			message(errorMessage);

		}
		else
		{
			m_errorMsg = nullptr;
		}
	}

	//Destructor
	ErrorState::~ErrorState()
	{
		clear();
	}
	void ErrorState::clear()
	{
		delete m_errorMsg;
		m_errorMsg = nullptr;
	}
	bool ErrorState::isClear() const
	{
		if (m_errorMsg == nullptr)
			return true;
		else
			return false;

	}
	void ErrorState::message(const char* str)
	{
		if (isClear() == false)
			clear();
		m_errorMsg = new char[strlen(str) + 1];
		strncpy(m_errorMsg, str, strlen(str) + 1);
		m_errorMsg[strlen(str)] = '\0';

	}

	const char* ErrorState::message() const
	{

		return m_errorMsg;

	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& errorInstance)
	{

		if (errorInstance.isClear() == false)
		{

			os << errorInstance.message();
		}
		return os;

	}
}