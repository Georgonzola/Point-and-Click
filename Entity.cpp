#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(int h, int s, int l)
{
	m_health = h;
	m_maxHealth = h;
	m_strength = s;
	m_dead = false;
	m_luck = l;
}

void Entity::takeDamage(int d)
{
	m_health -= d;
	if (m_health <= 0) {
		m_dead = true;
	}
}

void Entity::heal(int h)
{
	m_health += h;
	if (m_health > m_maxHealth) {
		m_health = m_maxHealth;
	}
}

bool Entity::getDead(){return m_dead;}

int Entity::getDamage(){return m_strength;}

int Entity::getHealth(){return m_health;}

int Entity::getLuck(){return m_luck;}

