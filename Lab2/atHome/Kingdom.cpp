/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 5/25/2018
// Author Suganya Maheswaran
// Description
//Lab2
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
 ***********************************************************/
#include <iostream>
#include "Kingdom.h"
using namespace std;
namespace sict {


	void display(const Kingdom& country)
	{

		cout << country.m_name << ", population " << country.m_population << endl;

	}
	void display(const Kingdom* country, int size)
	{
		int population = 0;
		
		cout<<"------------------------------"<<endl;
		cout<<"Kingdoms of SICT"<<endl;
		
		cout<<"------------------------------"<<endl;
		
		for(int i =0; i<size; i++)
		{
	//		display(*country);

		cout << i+1 << ". " << country[i].m_name << ", population " << country[i].m_population<< endl;
			population+= country[i].m_population;
	//		country = country +1;
		}

		cout<<"------------------------------"<<endl;
		cout<<"Total population of SICT: "<< population<<endl;
		
		cout<<"------------------------------"<<endl;
		
	}
}




