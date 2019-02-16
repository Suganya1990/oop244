
//name: Suganya Maheswaran
//STUDENT ID-  048298137
//email smaheswaran4@myseneca.ca


// TODO: add file header comments here
#include <iostream>
#include <cstring>
#include<iomanip>
#include "Passenger.h"

using namespace std;
namespace sict {

	Passenger::Passenger()
	{
		m_passengerName[0] = '\0';
		m_destination[0] = '\0';
		m_departureDay = 0;
		m_departureMonth = 0;
		m_departureYear = 0;
		//cout << "passenger()" << endl;
	}

	Passenger::Passenger(const char* passangerName, const char*  destinationName, int years, int month, int day)
	{
		if (destinationName != nullptr && passangerName != nullptr && passangerName[0] != '\0'  && destinationName[0] != '\0'
			&& (years >= 2017 && years <= 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
			strncpy(m_passengerName, passangerName, max_size);
			m_passengerName[max_size - 1] = '\0';
			strncpy(m_destination, destinationName, max_size);
			m_destination[max_size - 1] = '\0';
			m_departureYear = years;
		
			m_departureMonth = month;
	
			m_departureDay = day;
		}
		else
			*this = Passenger();
	}

	Passenger::Passenger(const char* passangerName, const char* destination)
	{
		cout << "passenger(const char*, const char*)" << endl;
		if (destination != nullptr && passangerName != nullptr && passangerName[0] != '\0'  && destination[0] != '\0') {
			strncpy(m_passengerName, passangerName, max_size);
			strncpy(m_destination, destination, max_size);

		}
		else
			*this = Passenger();
		
	}
	bool Passenger::isEmpty() const
	{
		if (m_destination[0] == '\0' || m_passengerName[0] == '\0' || m_departureDay == 0 || m_departureMonth == 0 || m_departureYear == 0)
			return true;
		else
			return false;
	}

	const char* Passenger::name() const
	{

		return m_passengerName;



	}
	bool Passenger::canTravelWith(const Passenger& other) const
	{
		
		if (this->m_departureDay != other.m_departureDay)
			return false;
		if (this->m_departureMonth != other.m_departureMonth)
			return false;
			
		if (this->m_departureYear != other.m_departureYear)
			return false;
		if ( strcmp(this->m_destination, other.m_destination) == 0);
		return true;
	}
	void Passenger::display() const
	{
	
		
		if (m_departureMonth < 10)
		{

		}


		if (isEmpty())
		{
			cout << "No passenger!" << endl;

		}

		else {


			cout<< m_passengerName << " - " << m_destination <<
				" on " << m_departureYear << "/"  << setfill('0') << setw(2) << m_departureMonth << "/"
				<< setfill('0') << setw(2) << m_departureDay << endl;
			
		}
	}

}