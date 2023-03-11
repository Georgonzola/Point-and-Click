#include "Enemy.h"


Enemy::Enemy(int h, int s, int l, string n, int xp, int t)
{
	m_health = h;
	m_maxHealth = h;
	m_strength = s;
	m_name = n;
	m_dead = false;
	m_luck = l;
	m_xp = xp;
	m_type = t;
}

int Enemy::getExp(){return m_xp;}

int Enemy::getType(){return 0;}


string Enemy::getName() { return string(m_name); }