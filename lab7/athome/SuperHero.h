#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include<iostream>
#include <string>
#include "Hero.h"

using namespace std;

namespace sict {
	class SuperHero : public Hero {
	private:
		int m_superPower;
		int m_superDefence;
	public:
		SuperHero();
		SuperHero(const char* name, int numHealth, int numAttackStrenght, int power, int defence);
		int attackStrength() const;
		int defend() const;
		void operator -= (int attack);

	};
	
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif 
