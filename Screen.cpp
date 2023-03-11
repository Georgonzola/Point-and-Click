#include "Screen.h"
#include <iostream>

using std::cout;
using std::endl;

Screen::Screen()
{
}





void Screen::drawEntities()
{
	for (int i = 0; i < arrLength; i++) {
		items[i].drawEntity();
	}
}

void Screen::deleteEntities()
{
	for (int i = 0; i < arrLength; i++) {
		items[i].deleteEntity();
	}
}
