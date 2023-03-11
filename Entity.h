#pragma once

class Entity
{
protected:

	int m_health;
	int m_maxHealth;
	int m_strength;
	int m_luck;
	bool m_dead;

public:
	Entity();
	Entity(int h, int s, int l);

	void takeDamage(int d);
	void heal(int h);
	bool getDead();

	int getDamage();
	int getHealth();
	int getLuck();
};


