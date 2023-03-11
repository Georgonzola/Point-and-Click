#pragma once
#include "ScreenEntity.h"
#include "Menu.h"

class Screen {
public:

//Menu
	ScreenEntity items [1];


	int arrLength = 1;

	Screen();

	

	void drawEntities();
	void deleteEntities();


};