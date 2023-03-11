#include <iostream>
#include "Menu.h"

using std::cout;
using std::endl;

//https://www.dafont.com/alagard.font


Menu::Menu()
{
	mapValues();
	initalizeEntities();
}

//maps coordinate values to opengl coords
void Menu::mapValues()
{
	inventoryLeft = -1 + (1 - -1) * (inventoryLeft / 350);
	inventoryRight = -1 + (1 - -1) * (inventoryRight / 350);

	for (int i = 0; i < items; i++) {
		inventoryBar[i][0] =  1 + (-1 - 1) * ((inventoryBar[i][0] - 0) / (300 - 0));
		inventoryBar[i][1] = 1 + (-1 - 1) * ((inventoryBar[i][1] - 0) / (300 - 0));
	}

	for (int i = 0; i < 8; i++) {
		moveCoords[i][0] = -1 + (1 - -1) * (moveCoords[i][0] / 350);
		moveCoords[i][1] = -1 + (1 - -1) * (moveCoords[i][1] / 350);

		moveCoords[i][2] = 1 + (-1 - 1) * ((moveCoords[i][2] - 0) / (300 - 0));
		moveCoords[i][3] = 1 + (-1 - 1) * ((moveCoords[i][3] - 0) / (300 - 0));
	}
}

//checks whether mouse coordiantes are in bounds for the boxes for clicking
void Menu::checkClick(double mousex, double mousey, Map& map, Items& inventory, Player& player) {
	for (int i = 0; i < items; i++) {

		if ((mousex >= inventoryLeft && mousex <= inventoryRight) && (mousey <= inventoryBar[i][0] && mousey >= inventoryBar[i][1])) {
			cout <<  "\nInventory section " << i + 1 << " clicked\n";
			inventory.SetSelected(i);
		}
	}

	for (int i = 0; i < 8; i++) {

		if ((mousex >= moveCoords[i][0] && mousex <= moveCoords[i][1]) && (mousey <= moveCoords[i][2] && mousey >= moveCoords[i][3])) {
			switch (i) {
			case 0:
				cout << "\nNorth Clicked\n";
				map.setDirection(8);
				break;
			case 1:
				cout << "\nNorth East Clicked\n";
				map.setDirection(9);
				break;
			case 2:
				cout << "\nEast Clicked\n";
				map.setDirection(6);
				break;
			case 3:
				cout << "\nSouth East Clicked\n";
				map.setDirection(3);
				break;
			case 4:
				cout << "\nSouth Clicked\n";
				map.setDirection(2);
				break;
			case 5:
				cout << "\nSouth West Clicked\n";
				map.setDirection(1);
				break;
			case 6:
				cout << "\nWest Clicked\n";
				map.setDirection(4);
				break;
			case 7:
				cout << "\nNorth West Clicked\n";
				map.setDirection(7);
				break;
			}
			map.RunRoom(inventory, player);
			return;
		}
	}

	map.checkCoords(mousex, mousey, inventory, player);

}

//checks whether mouse coordiantes are in bounds for the boxes for hover
void Menu::checkHover(double mousex, double mousey)
{
	for (int i = 0; i < items; i++) {
		if ((mousex >= inventoryLeft && mousex <= inventoryRight) && (mousey <= inventoryBar[i][0] && mousey >= inventoryBar[i][1])) {
			highlights[i].useColour();
		}
	}

	for (int i = 0; i < 8; i++) {
		if ((mousex >= moveCoords[i][0] && mousex <= moveCoords[i][1]) && (mousey <= moveCoords[i][2] && mousey >= moveCoords[i][3])) {
			highlights[i+9].useColour();
		}
	}


}

//initialises highlight textures
void Menu::initalizeEntities()
{
	for (int i = 0; i < items; i++) {
		highlights[i].setVariables(inventoryLeft, inventoryRight, inventoryBar[i][0], inventoryBar[i][1], "");
		highlights[i].Initialize(1);
	}

	for (int i = 0; i < 8; i++) {
		highlights[i+9].setVariables(moveCoords[i][0], moveCoords[i][1], moveCoords[i][2], moveCoords[i][3], "");
		highlights[i+9].Initialize(1);
	}

}

void Menu::deleteEntities()
{

}
