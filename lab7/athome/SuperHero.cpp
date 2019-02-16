#include<iostream>
#include<cstring>
#include<string.h>
#include"Hero.h"
#include"SuperHero.h"

using namespace std;

namespace sict {

	SuperHero::SuperHero()
	{
		m_superPower = 0;
		m_superDefence = 0;
	}
	SuperHero::SuperHero(const char* name, int numHealth, int numAttackStrength, int power, int defence) : Hero(name, numHealth, numAttackStrength)
	{
		if (power > 0 && defence > 0)
		{
			strncpy(m_name, name, max_hero_name);
			m_attackStrength = numAttackStrength;
			m_health = numHealth;
			m_superPower = power;
			m_superDefence = defence;


		}
	}
	int SuperHero::attackStrength() const
	{


		return m_attackStrength + m_superPower;

	}

	int SuperHero::defend() const
	{
		return m_superDefence;
	}

	void SuperHero::operator -= (int attack)
	{
		if (attack > 0)
		{
			m_health = m_health - attack;
			if (m_health < 0)
			{
				m_health = 0;

			}
		}


	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero temp1 = first;
		SuperHero temp2 = second;
		int damage1 = 0;
		int damage2 = 0;
		
		cout << "Super Fight! " << first << " vs " << second << " : ";
		for (int i = 0; i < max_rounds; i++)
		{
			damage2 = temp1.attackStrength() - temp2.defend();
			temp2 -= damage2;
			if (temp2.isAlive() == false)
			{
				cout << "Winner is " << first << " in " << i + 1 << " rounds." << endl;
				return first;
			}
			damage1 = temp2.attackStrength() - temp1.defend();
			temp1 -= damage1;
			if (temp1.isAlive() == false)
			{
				cout << "Winner is " << second << " in " << i + 1 << " rounds." << endl;
				return second;
			}
		}
		cout << "Winner is " << first << " in 100 rounds." << endl;
		return first;


	}



}