// TODO: add file header comments here
#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;
namespace sict {

	Passenger::Passenger()
	{
		m_passengerName[0] = '\0';
		m_destination[0] = '\0';

	}

	Passenger::Passenger(const char* passangerName, const char* destination)
	{
		if (destination != nullptr && passangerName != nullptr && passangerName[0] != '\0'  && destination[0] != '\0' ) {
			strncpy(m_passengerName, passangerName, max_size);
			strncpy(m_destination, destination, max_size );

		}
		else {
			m_passengerName[0] = '\0';
			m_destination[0] = '\0';
		}
	}
	bool Passenger::isEmpty() const
	{
		if (m_destination[0] == '\0' || m_passengerName[0] == '\0')
			return true;
		else
			return false; 
	}

	void Passenger::display() const
	{
		if (isEmpty())
		{
			cout << "No passenger!" << endl;

		}

		else {


			cout << m_passengerName << " - " << m_destination << endl;
		}
	}

}
