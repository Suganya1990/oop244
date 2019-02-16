
#ifndef PASSENGER_H
#define PASSENGER_H

namespace sict {
	const int max_size = 32;
	class Passenger {
	private:
		
		char m_passengerName[max_size];
		char m_destination[max_size];
	/*	int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
*/

	public:
		Passenger();
//		Passenger();
		Passenger(const char* passangerName, const char* destination);
		bool isEmpty() const;
		void display() const;

	};

}
#endif // !1
