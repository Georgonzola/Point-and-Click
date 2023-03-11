#pragma once
#include "Entity.h"
#include <iostream>
using std::string;


class Enemy : public Entity {
private:
	int m_xp;
	int m_type;
	string m_name;
public:

	Enemy(int h, int s, int l, string n, int xp, int t);

	int getExp();
	int getType();
	string getName();
};