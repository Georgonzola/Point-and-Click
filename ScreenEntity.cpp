#include "ScreenEntity.h"
#include <iostream>

using std::cout;
using std::endl;


ScreenEntity::ScreenEntity()
{
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;
	m_file = 0;
	m_texture.setVariables(0, 0, 0, 0, 0);
	m_name = "";
}

ScreenEntity::ScreenEntity(string n, float l, float r, float t, float b, const char* tex)
{
	m_left = l;
	m_right = r;
	m_top = t;
	m_bottom = b;
	m_file = tex;
	m_texture.setVariables(l, r, t, b, tex);
	m_texture.Initialize(0);
	m_name = n;
}

void ScreenEntity::setData(string n, float l, float r, float t, float b, const char* tex)
{
	m_left = l;
	m_right = r;
	m_top = t;
	m_bottom = b;
	m_file = tex;
	mapValues();
	m_texture.setVariables(m_left, m_right, m_top, m_bottom, tex);
	m_texture.Initialize(0);
	m_name = n;
}

void ScreenEntity::printData()
{
	cout << m_name << endl;
	cout << m_left << endl;
	cout << m_right << endl;
}



void ScreenEntity::drawEntity(){m_texture.use();}
void ScreenEntity::initalizeEntity() { m_texture.Initialize(0); }
void ScreenEntity::deleteEntity(){m_texture.del();}


//maps coordiantes to opengl coords
void ScreenEntity::mapValues()
{
	for (int i = 0; i < 1; i++) {
		m_left = -1 + (1 - -1) * (m_left / 350);
		m_right = -1 + (1 - -1) * (m_right / 350);

		m_top = 1 + (-1 - 1) * ((m_top - 0) / (300 - 0));
		m_bottom = 1 + (-1 - 1) * ((m_bottom - 0) / (300 - 0));
	}
}

