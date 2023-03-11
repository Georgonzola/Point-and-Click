#pragma once
#include "Texture.h"
#include <iostream>;

using std::string;

class ScreenEntity {
public:

	float m_left, m_right, m_top, m_bottom;
	const char* m_file;
	Texture m_texture;
	string m_name;



	ScreenEntity();

	ScreenEntity(string n, float l, float r, float t, float b, const char* tex);

	void setData(string n, float l, float r, float t, float b, const char* tex);

	void printData();

	void drawEntity();
	void initalizeEntity();
	void deleteEntity();

	void mapValues();
};