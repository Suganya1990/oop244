/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 5/25/2018
// Author Suganya Maheswaran
// Description
// Lab 2
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef _SICT_KINGDOM_
#define _SICT_KINGDOM_

namespace sict {

	struct Kingdom {
		char m_name[32];
		int m_population;

	};
	void display(const Kingdom& country);
	void display( const Kingdom* country,  int size);

}


#endif
