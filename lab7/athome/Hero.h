#ifndef SICT_HERO_H
#define SICT_HERO_H

#include<iostream>
#include <string>

using namespace std;


namespace sict {
	const int max_hero_name = 41;
	const int max_rounds = 100;
	class Hero
	{
	protected:
		char m_name[max_hero_name];
		int m_health;
		int m_attackStrength;
	public:
		Hero();
		Hero(const char* name, int numHealth, int numAttackStength);
		void operator -= (int attack);
		bool isAlive() const;
		int attackStrength() const;

		friend 	ostream& operator<<(ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !