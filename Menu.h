#pragma once
#include "Texture.h"
#include "Map.h"
#include "Items.h"
const int items = 9;



class Menu {
public:


	// stores values for the highlight texture for both the movement and inventory
	Texture highlights[17];

	//sotres the coords for the movement sections
	float moveCoords[8][4] = {
		{35, 42 ,232, 239},
		{49, 55, 245, 251},
		{61, 68, 258, 265},
		{49, 55, 272, 278},
		{35, 42, 284, 291},
		{22, 28, 272, 278},
		{9, 16 , 258, 265},
		{22, 28, 245, 251},
	};

	//stores the coords for the inventory sections
	float inventoryLeft = 250;
	float inventoryRight = 338;
	float inventoryBar[9][2] = {
		{43,54},
		{59,70},
		{75,86},
		{91,102},
		{107,118},
		{123,134},
		{139,150},
		{155,166},
		{171,182},
	};



	Menu();
	void mapValues();
	void checkClick(double x, double y, Map& map, Items& inventory, Player& player);
	void checkHover(double mousex, double mousey);
	void initalizeEntities();
	void deleteEntities();



};