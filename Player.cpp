#include "Player.h"
Player::Player (int h, int s, int l, int a, int lv)
{
	m_health = h;
	m_maxHealth = h;
	m_strength = s;

	m_dead = false;
	m_luck = l;
	m_accessory = a;
	m_level = lv;
}

void Player::setLevel(int xp)
{
	m_level += xp;
	if (m_level >= 100){
		m_level -= 100;
		m_strength += 5;
	}
}

int Player::getAccessory(){return m_accessory;}
