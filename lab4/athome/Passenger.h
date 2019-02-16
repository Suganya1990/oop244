//name: Suganya Maheswaran
//STUDENT ID-  048298137
//email smaheswaran4@myseneca.ca
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {
	const int max_size = 32;
	class Passenger {
	private:
		
		char m_passengerName[max_size];
		char m_destination[max_size];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
	

	public:
		Passenger();
		Passenger(const char* passangerName, const char*  destinationName, int years, int month, int day);
		Passenger(const char* passangerName, const char* destination);
		const char* name() const;
		bool canTravelWith(const Passenger& other) const;
		bool isEmpty() const;
		void display() const;

	};

}
#endif
