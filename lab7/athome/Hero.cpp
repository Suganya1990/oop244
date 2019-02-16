#include<iostream>
#include<cstring>
#include<string.h>
#include"Hero.h"


using namespace std;

namespace sict {
	Hero::Hero()
	{
		//m_name = nullptr;
		//sets my object to an empty state
		m_name[0] = '\0';
		m_health = 0;
		m_attackStrength = 0;

	}

	Hero::Hero(const char* name, int numHealth, int numAttackStength)
	{
		//assigns valid data into my member functions
		if (name != nullptr && name[0] != '\0' && numHealth != 0 && numAttackStength != 0)
		{
			//copys name into object m_name
			strncpy(m_name, name, max_hero_name - 1);
			m_name[max_hero_name] = '\0';
			m_health = numHealth;
			m_attackStrength = numAttackStength;

		}
		else
			*this = Hero();


	}

	void Hero::operator -= (int attack)
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



	bool Hero::isAlive() const
	{
		if (m_health > 0)
			return true;
		else
			return false;

	}

	int Hero::attackStrength() const

	{
		if (m_name[0] == '\0' && m_health == 0 && m_attackStrength)

			return 0;
		else
			return m_attackStrength;
	}

	ostream& operator<<(ostream& os, const Hero& hero)
	{
		if (hero.m_name == '\0' || hero.m_name == nullptr)
			os << "No Hero";
		os << hero.m_name;
		return os;
	}


	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero temp1 = first;
		Hero temp2 = second;
		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		for (int i = 0; i < max_rounds; i++)
		{
			temp2 -= temp1.attackStrength();
			if (temp2.isAlive() == false)
			{
				cout << "Winner is " << first << " in " << i + 1 << " rounds." << endl;
				return first;
			}
			temp1 -= temp2.attackStrength();
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
		