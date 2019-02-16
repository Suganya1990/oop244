#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<cstring>
#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// includes error checking: checks if the name of the row is valid.
	//
	

	

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationSum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			populationSum = populationSum + population[i + 1] - population[i];


		}
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Population change from 2000 to 2004 is " << populationSum / 1000000.00 << " million"<<endl;



		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005


		if (violentCrimeRate[0] > violentCrimeRate[4])

			cout << "Violent Crime trend is " << "down" << endl;
		else

			cout << "Violent Crime trend is " << "up" << endl;





		// Q3 print the GTA number accurate to 0 decimal places

		double averageGTA= average(grandTheftAuto, n);
		averageGTA = averageGTA / 1000000;

		cout << "There are "<< averageGTA   <<" million Grand Theft Auto incidents on average a year" << endl;
int min_ = min(violentCrimeRate,n);
	int max_ = max(violentCrimeRate,n);

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << min_ << endl;
		cout << "The Maximum Violent Crime rate was " << max_<<endl;
	}
}
