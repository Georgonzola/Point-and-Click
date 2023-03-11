#pragma once
#include "Entity.h"

class Player : public Entity {
private:

	int m_accessory;
	int m_level;
public:

	Player(int h, int s, int l, int a, int lv);

	void setLevel(int xp);
	int getAccessory();

};
