#include "Map.h"
#include <iostream>
#include "windows.h"
#include <chrono>
#include <random>
#include <stdlib.h>
#include "Enemy.h"
#define random(min, max) rand() % (max + 1 - min) + min

using std::cout;
using std::cin;

Map::Map()
{
	m_xPos = 0;
	m_yPos = 0;
	m_zPos = 0;
	m_finish = false;
	m_printed = false;
}

Map::Map(int x, int y, int z)
{
	m_xPos = x;
	m_yPos = y;
	m_zPos = z;
	m_finish = false;
	m_printed = false;
	mapCoords();
}

bool Map::GetFinish() { return m_finish; }

void Map::MovePlayer(int x, int y, int z)
{
	m_xPos += x;
	m_yPos += y;
	m_zPos += z;
}

int Map::GetRoomID() { return m_mapArray[m_yPos][m_xPos][m_zPos]; }

///////////////////////////////////////////////////////////////////////////////////////////////
/// MAIN ROOM CHECKER
///////////////////////////////////////////////////////////////////////////////////////////////


void Map::RunRoom(Items& Inventory, Player& player)
{
	int temp = GetRoomID();

	switch (temp) {

	case 1:
		m_background.setData("Background", 3, 236, 3, 195, "Images/Pantry.png");
		m_background.initalizeEntity();
		RunPantry(Inventory);
		break;
	case 2:
		RunPond(Inventory);
		break;
	case 3:
		RunShed(Inventory);
		break;
	case 4:
		m_background.setData("Background", 3, 236, 3, 195, "Images/Kitchen.png");
		m_background.initalizeEntity();
		RunKitchen(Inventory);
		break;
	case 5:
		RunGarden(Inventory);
		break;
	case 6:
		m_background.setData("Background", 3, 236, 3, 195, "Images/ServantsQuarters.png");
		m_background.initalizeEntity();
		RunServantsQuarters(Inventory);
		break;
	case 7:
		m_background.setData("Background", 3, 236, 3, 195, "Images/DiningRoom.png");
		m_background.initalizeEntity();
		RunDiningRoom(Inventory);
		break;
	case 8:
		m_background.setData("Background", 3, 236, 3, 195, "Images/Lobby.png");
		m_background.initalizeEntity();
		RunLobby(Inventory, player);
		break;
	case 9:
		m_background.setData("Background", 3, 236, 3, 195, "Images/Lounge.png");
		m_background.initalizeEntity();
		RunLounge(Inventory);
		break;
	case 10:
		m_background.setData("Background", 3, 236, 3, 195, "Images/FrontGarden.png");
		m_background.initalizeEntity();
		RunFrontGarden(Inventory);
		break;
	case 11:
		RunEnSuite(Inventory);
		break;
	case 12:
		RunMasterBedroom(Inventory);
		break;
	case 13:
		RunStudy(Inventory);
		break;
	case 14:
		RunGuestBedroom1(Inventory);
		break;
	case 15:
		RunLanding(Inventory);
		break;
	case 16:
		RunGameRoom(Inventory);
		break;
	case 17:
		RunGuestBedroom2(Inventory);
		break;
	case 18:
		RunBathRoom(Inventory);
		break;
	case 19:
		RunWineCellar(Inventory);
		break;
	}
}





///////////////////////////////////////////////////////////////////////////////////////////////
/// FIRST FLOOR
///////////////////////////////////////////////////////////////////////////////////////////////
#pragma region First_Floor

void Map::RunPantry(Items& Inventory)
{
	if (m_direction == 12) {
		m_direction = 2;
	}
		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Pantry\n\n";
			std::cout << "South: Kitchen\n\n";
			break;
		case 2:
			MovePlayer(0, 1, 0);
			m_printed = false;
			break;
		case 10:
			system("CLS");
			if (Inventory.GetKeyItem(1)) {
				std::cout << "You have already searched this";
			}
			else {
				std::cout << "You found some fish food";
				Inventory.SetKeyItem(1);
				Sleep(1000);
			}
			m_printed = false;
			break;
		case 11:
			system("CLS");
			if (Inventory.GetKeyItem(4)) {
				std::cout << "You have already searched this";
			}
			else {
				std::cout << "You found some baking powder";
				Inventory.SetKeyItem(4);
				Sleep(1000);
			}
			m_printed = false;
			break;
		default:
			system("CLS");
			std::cout << "\nYou can't go this way";
			Sleep(1000);
			m_printed = false;
			break;
		}
		m_direction = 0;
}

void Map::RunPond(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are by the Pond\n\n";
		std::cout << "2: Garden\n\n5: Search\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 2:
			MovePlayer(0, 1, 0);
			break;
		case 5:
			system("CLS");
			if (Inventory.GetKeyItem(6)) {
				std::cout << "You found nothing";
			}
			else if (Inventory.GetKeyItem(4) && Inventory.GetKeyItem(5) && Inventory.GetKeyItem(6) == false) {
				std::cout << "You lure the fish over and pick one out of the pond";
				Inventory.SetKeyItem(6);
				Sleep(3000);
			}
			else {
				std::cout << "There are some fish in the pond but you cannot get to them";
				Sleep(3000);
			}
			Sleep(1000);
			loop = true;
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}
	} while (loop == true);
}

void Map::RunShed(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the Shed\n\n";
		std::cout << "1: Garden\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 1:
			MovePlayer(-1, 1, 0);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}
	} while (loop == true);
}

void Map::RunKitchen(Items& Inventory)
{
	if (m_direction == 11){
		m_direction = 8;
	}
	if (m_direction == 12) {
		m_direction = 3;
	}

		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Kitchen\n\n";
			std::cout << "North: Pantry\nSouth East: Lobby\n\n";
			break;
		case 8:
			if (Inventory.GetKey(2)) {
				MovePlayer(0, -1, 0);
				m_printed = false;
			}
			else {

				system("CLS");
				std::cout << "The door is locked";
				Sleep(1500);
				m_printed = false;
			}
			break;
		case 3:
			MovePlayer(1, 1, 0);
			m_printed = false;
			break;
		case 10:
			system("CLS");
			if (Inventory.GetKeyItem(3)) {
				std::cout << "You have already used this";
			}
			else if (Inventory.GetKeyItem(0) && Inventory.GetKeyItem(1) && Inventory.GetKeyItem(2) && Inventory.GetKeyItem(3) == false) {
				std::cout << "You put all the ingredients into the pot and craft the potion";
				Inventory.SetKeyItem(3);
				Sleep(3000);
			}
			else {
				std::cout << "There is a pot with a recipe attatched, you need roses, baking powder, and a fireplace poker";
				Sleep(3000);
			}
			Sleep(1500);
			m_printed = false;
			break;
		default:
			system("CLS");
			std::cout << "\nYou can't go this way";
			Sleep(1500);
			m_printed = false;
			break;
		}
		m_direction = 0;
}

void Map::RunGarden(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the Garden\n\n";
		std::cout << "8: Pond\n9: Shed\n2: Lobby\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 2:
			MovePlayer(0, 1, 0);
			break;
		case 8:
			MovePlayer(0, -1, 0);
			break;
		case 9:
			if (Inventory.GetKeyItem(6)) {
				MovePlayer(1, -1, 0);
			}
			else {
				loop = true;
				system("CLS");
				std::cout << "There is a stray cat guarding the door, if only you had something to distract it with";
				Sleep(2000);
			}
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}

	} while (loop == true);
}

void Map::RunServantsQuarters(Items& Inventory)
{
	if (m_direction == 11) {
		m_direction = 1;
	}

		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Servants Quarters\n\n";
			std::cout << "South West: Lobby\n\n";
			break;
		case 1:
			MovePlayer(-1, 1, 0);
			m_printed = false;
			break;
		case 10:
			system("CLS");
			if (Inventory.GetKey(1)) {
				std::cout << "You have already searched this";
			}
			else {
				std::cout << "You found the kitchen key";
				Inventory.SetKey(1);
			}
			Sleep(1500);
			m_printed = false;
			break;
		default:
			system("CLS");
			std::cout << "\nYou can't go this way";
			Sleep(1500);
			m_printed = false;
			break;
		}
		m_direction = 0;
}

void Map::RunDiningRoom(Items& Inventory)
{
	if (m_direction == 12) {
		m_direction = 6;
	}

		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Dining Room\n\n";
			std::cout << "East: Lobby\n\n";
			break;
		case 6:
			MovePlayer(1, 0, 0);
			m_printed = false;
			break;
		case 10:
			system("CLS");
			if (Inventory.GetKey(2) == true) {
				std::cout << "You have already searched this";
			}else{
				std::cout << "You found the pantry key";
				Inventory.SetKey(2);
			}
			Sleep(1500);
			m_printed = false;
			break;
		case 11:

			system("CLS");
			if (Inventory.GetKeyItem(7) == true) {
				std::cout << "You have already searched this";
			}
			else if (Inventory.GetKey(4) == false){
				std::cout << "There is an ornate cabinet that you cant open yet";
			}
			else {
				std::cout << "You open the ornate cabinet and take an old anchor";
				Inventory.SetKeyItem(7);
			}

			Sleep(1500);
			m_printed = false;
			break;
		default:
			system("CLS");
			std::cout << "\n\nInvalid input";
			Sleep(1500);
			m_printed = false;
			break;
		}
		m_direction = 0;
}

void Map::RunLobby(Items& Inventory, Player& player)
{
		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Lobby\n\n";
			std::cout << "North: Garden\nWest: DiningRoom\nNorth West: Kitchen\nEast: Lounge\nNorth East: Servants Quarters\nSouth: Front Garden\n\nLeft Stairs: Upstairs\n\n";
			break;
		case 2:
			MovePlayer(0, 1, 0);
			m_printed = false;
			break;
		case 4:
			MovePlayer(-1, 0, 0);
			m_printed = false;
			break;
		case 6:
			MovePlayer(1, 0, 0);
			m_printed = false;
			break;
		case 7:
			if (Inventory.GetKey(1)) {
				MovePlayer(-1, -1, 0);
				m_printed = false;
			}
			else {

				system("CLS");
				std::cout << "The door is locked";
				Sleep(1000);
				m_printed = false;
			}
			break;
		case 8:
			if (Inventory.GetKey(6)) {
				MovePlayer(0, -1, 0);
				m_printed = false;
			}
			else {

				system("CLS");
				std::cout << "The door is locked";
				Sleep(1500);
				m_printed = false;
			}
			break;
		case 9:
			MovePlayer(1, -1, 0);
			m_printed = false;
			break;
		case 5:
			if (Inventory.GetKeyItem(3)&& m_stairs == true) {
				MovePlayer(0, 0, 1);
				m_printed = false;
			}
			else if (Inventory.GetKeyItem(3) && m_stairs == false) {
				system("CLS");
				std::cout << "You approach the ghost blocking the stairs and lob the potion at him. He furiously turns towards you, poised to strike";
				Sleep(3000);
				Enemy Steph(60, 15, 7, "Stephen", 100, 0);
				battle(player, Steph);
				m_stairs = true;
				std::cout << "\n\nThe ghost concedes defeat and allows you to pass freely";
				Sleep(2500);
				MovePlayer(0, 0, 1);
				m_printed = false;
				
			}
			else {
				system("CLS");
				std::cout << "There is a ghost blocking the stairs. you need a potion to get rid of him";
				Sleep(2000);
				m_printed = false;
			}

			break;
		default:
			system("CLS");
			std::cout << "\nYou can't go this way";
			Sleep(1500);
			m_printed = false;
			break;
		}
		m_direction = 0;


}

void Map::RunLounge(Items& Inventory)
{
	if (m_direction == 12) {
		m_direction = 4;
	}

		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Lounge\n\n";
			std::cout << "West: Lobby\n\n";
			break;
		case 4:
			MovePlayer(-1, 0, 0);
			m_printed = false;
			break;
		case 10:

			system("CLS");
			if (Inventory.GetKeyItem(2) == true) {
				std::cout << "You have already searched this";
			}
			else {
				std::cout << "You found a fireplace poker";
				Inventory.SetKeyItem(2);
			}


			Sleep(1500);
			m_printed = false;
			break;

		case 11:
			system("CLS");
			if (Inventory.GetKeyItem(12)) {
				std::cout << "You have already searched this";
			}
			else {
				std::cout << "You found some scissors";
				Inventory.SetKeyItem(12);
			}
			Sleep(1500);
			m_printed = false;
			break;
		default:
			system("CLS");
			std::cout << "\nYou can't go this way";
			Sleep(1500);
			m_printed = false;
			break;
		}
		m_direction = 0;
}

void Map::RunFrontGarden(Items& Inventory)
{
	if (m_direction == 12) {
		m_direction = 8;
	}

		switch (m_direction) {
		case 0:
			system("CLS");
			std::cout << "You are in the Front Garden\n\n";
			std::cout << "North: Lobby\n\n";
			break;
		case 8:
			if (Inventory.GetKey(0)) {
				MovePlayer(0, -1, 0);
				m_printed = false;
			}

			else {
				system("CLS");
				std::cout << "The door is locked";
				Sleep(1500);
				m_printed = false;
			}

			break;
		case 10:
			system("CLS");
			// 0 = roses 12 = scissors

			if (Inventory.GetKeyItem(0) == true) {
				std::cout << "You have already taken the flowers";
			}
			else if (Inventory.GetKeyItem(12) == false) {
				std::cout << "There are some roses but you have nothing to cut them with";
			}
			else {
				std::cout << "You cut the roses and kept them for later";
				Inventory.SetKeyItem(0);
			}

			Sleep(1500);
			m_printed = false;
			break;

		case 11:
			system("CLS");

			if (Inventory.GetKey(0) == true) {
				std::cout << "You have alrady looked under the rock";
			}
			else {
				std::cout << "You found the front door key under the rock";
				Inventory.SetKey(0);
			}

			Sleep(1500);
			m_printed = false;
			break;
		default:
			system("CLS");
			std::cout << "\nYou can't go this way";
			Sleep(1500);
			m_printed = false;
			break;
		}
		m_direction = 0;
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////
/// SECOND FLOOR
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma region Second_Floor
void Map::RunEnSuite(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the En-Suite\n\n";
		std::cout << "2: Master Bedroom\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 2:
			MovePlayer(0, 1, 0);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}
	} while (loop == true);
}

void Map::RunMasterBedroom(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the Master Bedroom\n\n";
		std::cout << "8: En-Suite\n3: Landing\n\n5: Search\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 8:
			MovePlayer(0, -1, 0);
			break;
		case 3:
			MovePlayer(1, 1, 0);
			break;
		case 5:
			system("CLS");
			if (Inventory.GetKey(5)) {
				std::cout << "You found nothing";
			}
			else {
				std::cout << "You found the guest key";
				Inventory.SetKey(5);
			}
			Sleep(1000);
			loop = true;
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}

	} while (loop == true);
}

void Map::RunStudy(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the Study\n\n";
		std::cout << "1: Landing\n\n5: Search\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 1:
			MovePlayer(-1, 1, 0);
			break;
		case 5:
			system("CLS");
			if (Inventory.GetKey(3) == true && Inventory.GetKey(4) == true) {
				std::cout << "You found nothing";
			}
			else if (Inventory.GetKey(3) == true && Inventory.GetKeyItem(11) == false) {
				std::cout << "There is a lockbox but you dont know the code";
			}
			else if (Inventory.GetKeyItem(11) == true && Inventory.GetKey(4) == false) {
				std::cout << "You open the lockbox with the code you found, you found the garden key";
				Inventory.SetKey(4);
			}
			else {
				std::cout << "You found the master key & an ornate key, there is a lockbox but you dont know the code";
				Inventory.SetKey(6);
				Inventory.SetKey(3);
				Sleep(1000);
			}
			Sleep(1000);
			loop = true;
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}

	} while (loop == true);
}

void Map::RunGuestBedroom1(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in Guest Bedroom 1\n\n";
		std::cout << "2: Guest Bed 2\n6: Landing\n\n5: Search\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 2:
			MovePlayer(0, 1, 0);
			break;
		case 6:
			MovePlayer(1, 0, 0);
			break;
		case 5:
			system("CLS");
			if (Inventory.GetKeyItem(11)) {
				std::cout << "You found nothing";
			}
			else {
				std::cout << "You found the lockbox code";
				Inventory.SetKeyItem(11);
			}
			Sleep(1000);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}

	} while (loop == true);
}

void Map::RunLanding(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are on the Landing\n\n";
		std::cout << "4: Guest Bed 1\n1: Guest Bed 2\n7: Master Bedroom\n6: Game Room\n9: Study\n3: Bathroom\n\n5: Downstairs\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 4:
			if (Inventory.GetKey(5)) {
				MovePlayer(-1, 0, 0);
			}
			else {
				loop = true;
				system("CLS");
				std::cout << "The door is locked";
				Sleep(1000);
			}
			break;
		case 1:
			if (Inventory.GetKey(5)) {
				MovePlayer(-1, 1, 0);
			}
			else {
				loop = true;
				system("CLS");
				std::cout << "The door is locked";
				Sleep(1000);
			}
			break;
		case 6:
			MovePlayer(1, 0, 0);
			break;
		case 7:
			if (Inventory.GetKey(3)) {
				MovePlayer(-1, -1, 0);
			}
			else {
				loop = true;
				system("CLS");
				std::cout << "The door is locked";
				Sleep(1000);
			}
			break;
		case 9:
			MovePlayer(1, -1, 0);
			break;
		case 3:
			MovePlayer(1, 1, 0);
			break;
		case 5:
			MovePlayer(0, 0, -1);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}

	} while (loop == true);
}

void Map::RunGameRoom(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the Game Room\n\n";
		std::cout << "4: Landing\n\n5: Search\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 4:
			MovePlayer(-1, 0, 0);
			break;
		case 5:
			system("CLS");
			if (Inventory.GetKeyItem(8)) {
				std::cout << "You found nothing";
			}
			else {
				std::cout << "You found a pool cue";
				Inventory.SetKeyItem(8);
			}
			Sleep(1000);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}
	} while (loop == true);
}

void Map::RunGuestBedroom2(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in Guest Bedroom 2\n\n";
		std::cout << "8: Guest Bed 1\n9: Landing\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 8:
			MovePlayer(0, -1, 0);
			break;
		case 9:
			MovePlayer(1, -1, 0);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}

	} while (loop == true);
}

void Map::RunBathRoom(Items& Inventory)
{
	bool loop = true;
	int temp;
	do {
		system("CLS");
		std::cout << "You are in the Bathroom\n\n";
		std::cout << "7: Landing\n\n5: Search\n\n";
		std::cin >> temp;
		loop = false;
		switch (temp) {
		case 0:
			Inventory.PrintItems();
			loop = true;
			break;
		case 7:
			MovePlayer(-1, -1, 0);
			break;
		case 5:
			system("CLS");
			if (Inventory.GetKeyItem(5)) {
				std::cout << "You found nothing";
			}
			else {
				std::cout << "You found some gloves";
				Inventory.SetKeyItem(5);
			}
			Sleep(1000);
			break;
		default:
			loop = true;
			std::cout << "\n\nInvalid input";
			Sleep(1000);
			break;
		}
	} while (loop == true);
}

void Map::RunWineCellar(Items& Inventory)
{
}

#pragma endregion


void Map::mapCoords()
{
	for (int i = 0; i < 7; i++) {
		lobbyCoords[i][0] = -1 + (1 - -1) * (lobbyCoords[i][0] / 350);
		lobbyCoords[i][1] = -1 + (1 - -1) * (lobbyCoords[i][1] / 350);

		lobbyCoords[i][2] = 1 + (-1 - 1) * ((lobbyCoords[i][2] - 0) / (300 - 0));
		lobbyCoords[i][3] = 1 + (-1 - 1) * ((lobbyCoords[i][3] - 0) / (300 - 0));
	}

	for (int i = 0; i < 3; i++) {
		frontGardenCoords[i][0] = -1 + (1 - -1) * (frontGardenCoords[i][0] / 350);
		frontGardenCoords[i][1] = -1 + (1 - -1) * (frontGardenCoords[i][1] / 350);

		frontGardenCoords[i][2] = 1 + (-1 - 1) * ((frontGardenCoords[i][2] - 0) / (300 - 0));
		frontGardenCoords[i][3] = 1 + (-1 - 1) * ((frontGardenCoords[i][3] - 0) / (300 - 0));
	}

	for (int i = 0; i < 3; i++) {
		diningRoomCoords[i][0] = -1 + (1 - -1) * (diningRoomCoords[i][0] / 350);
		diningRoomCoords[i][1] = -1 + (1 - -1) * (diningRoomCoords[i][1] / 350);

		diningRoomCoords[i][2] = 1 + (-1 - 1) * ((diningRoomCoords[i][2] - 0) / (300 - 0));
		diningRoomCoords[i][3] = 1 + (-1 - 1) * ((diningRoomCoords[i][3] - 0) / (300 - 0));
	}

	for (int i = 0; i < 3; i++) {
		kitchenCoords[i][0] = -1 + (1 - -1) * (kitchenCoords[i][0] / 350);
		kitchenCoords[i][1] = -1 + (1 - -1) * (kitchenCoords[i][1] / 350);

		kitchenCoords[i][2] = 1 + (-1 - 1) * ((kitchenCoords[i][2] - 0) / (300 - 0));
		kitchenCoords[i][3] = 1 + (-1 - 1) * ((kitchenCoords[i][3] - 0) / (300 - 0));
	}

	for (int i = 0; i < 3; i++) {
		pantryCoords[i][0] = -1 + (1 - -1) * (pantryCoords[i][0] / 350);
		pantryCoords[i][1] = -1 + (1 - -1) * (pantryCoords[i][1] / 350);

		pantryCoords[i][2] = 1 + (-1 - 1) * ((pantryCoords[i][2] - 0) / (300 - 0));
		pantryCoords[i][3] = 1 + (-1 - 1) * ((pantryCoords[i][3] - 0) / (300 - 0));
	}

	for (int i = 0; i < 2; i++) {
		servantsQuartersCoords[i][0] = -1 + (1 - -1) * (servantsQuartersCoords[i][0] / 350);
		servantsQuartersCoords[i][1] = -1 + (1 - -1) * (servantsQuartersCoords[i][1] / 350);

		servantsQuartersCoords[i][2] = 1 + (-1 - 1) * ((servantsQuartersCoords[i][2] - 0) / (300 - 0));
		servantsQuartersCoords[i][3] = 1 + (-1 - 1) * ((servantsQuartersCoords[i][3] - 0) / (300 - 0));
	}

	for (int i = 0; i < 3; i++) {
		loungeCoords[i][0] = -1 + (1 - -1) * (loungeCoords[i][0] / 350);
		loungeCoords[i][1] = -1 + (1 - -1) * (loungeCoords[i][1] / 350);

		loungeCoords[i][2] = 1 + (-1 - 1) * ((loungeCoords[i][2] - 0) / (300 - 0));
		loungeCoords[i][3] = 1 + (-1 - 1) * ((loungeCoords[i][3] - 0) / (300 - 0));
	}

}

//Check whether user has clicked an on screen item
void Map::checkCoords(double mousex, double mousey, Items& inventory, Player& player)
{


	/*
	
	Pantry		= 1
	Kitchen		= 4
	S.Quarters	= 6
	DiningRoom	= 7
	Lobby		= 8
	Lounge		= 9
	F.Garden	= 10
	
	*/

	switch (m_mapArray[m_yPos][m_xPos][m_zPos]) {
	case 8:
		for (int i = 0; i < 7; i++) {
			if ((mousex >= lobbyCoords[i][0] && mousex <= lobbyCoords[i][1]) && (mousey <= lobbyCoords[i][2] && mousey >= lobbyCoords[i][3])) {

				switch (i) {
				case 0:
					cout << "\nWest Clicked\n";
					m_direction = 4;
					break;
				case 1:
					cout << "\nNorth West Clicked\n";
					m_direction = 7;
					break;
				case 2:
					cout << "\nUpstairs Clicked\n";
					m_direction = 5;
					break;
				case 3:
					cout << "\nNorth Clicked\n";
					m_direction = 8;
					break;
				case 4:
					cout << "\nNorth East Clicked\n";
					m_direction = 9;
					break;
				case 5:
					cout << "\nEast Clicked\n";
					m_direction = 6;
					break;
				case 6:
					cout << "\nSouth Clicked\n";
					m_direction = 2;
					break;

				}
				
				//cout << "\nLobby section " << i + 1 << " clicked\n";
			}}
		RunRoom(inventory,player);
		break;
	case 1:
		for (int i = 0; i < 3; i++) {
			if ((mousex >= pantryCoords[i][0] && mousex <= pantryCoords[i][1]) && (mousey <= pantryCoords[i][2] && mousey >= pantryCoords[i][3])) {
				m_direction = i + 10;
			}
		}
		RunRoom(inventory, player);
		break;

	case 4:
		for (int i = 0; i < 3; i++) {
			if ((mousex >= kitchenCoords[i][0] && mousex <= kitchenCoords[i][1]) && (mousey <= kitchenCoords[i][2] && mousey >= kitchenCoords[i][3])) {
				m_direction = i + 10;
			}
		}
		RunRoom(inventory, player);
		break;


	case 6:
		for (int i = 0; i < 2; i++) {
			if ((mousex >= servantsQuartersCoords[i][0] && mousex <= servantsQuartersCoords[i][1]) && (mousey <= servantsQuartersCoords[i][2] && mousey >= servantsQuartersCoords[i][3])) {
				m_direction = i + 10;
			}
		}
		RunRoom(inventory, player);
		break;

	case 7:
		for (int i = 0; i < 3; i++) {
			if ((mousex >= diningRoomCoords[i][0] && mousex <= diningRoomCoords[i][1]) && (mousey <= diningRoomCoords[i][2] && mousey >= diningRoomCoords[i][3])) {
				m_direction = i + 10;
			}
		}
		RunRoom(inventory, player);
		break;


	case 9:
		for (int i = 0; i < 3; i++) {
			if ((mousex >= loungeCoords[i][0] && mousex <= loungeCoords[i][1]) && (mousey <= loungeCoords[i][2] && mousey >= loungeCoords[i][3])) {
				m_direction = i + 10;
			}
		}
		RunRoom(inventory, player);
		break;

	case 10:
		for (int i = 0; i < 3; i++) {
			if ((mousex >= frontGardenCoords[i][0] && mousex <= frontGardenCoords[i][1]) && (mousey <= frontGardenCoords[i][2] && mousey >= frontGardenCoords[i][3])) {
				m_direction = i + 10;
			}
		}
		RunRoom(inventory, player);
		break;
	}



}



void Map::setDirection(int dir)
{
	m_direction = dir;
	std::cout << m_direction << std::endl;
}

bool Map::getPrinted(){return m_printed;}
void Map::setPrinted(bool val) { m_printed = val; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void Map::DisplayMap() {

}


//draws main game section
void Map::DrawRoom()
{
	m_background.drawEntity();
}

//battle loop
void Map::battle(Player& player, Enemy enemy)
{


	//stores user input
	int temp = 0;
	
	// checks whether status effects are active
	bool playerRoot = false;
	bool playerInflame = false;
	bool enemyInflame = false;

	//counts the number of rounds a status effect has been active for
	int enemyStatCount = 0;
	int playerStatCount = 0;
	int playerStatCount1 = 0;

	//loops if user input wrong number
	bool inputLoop = true;

	//loops if player or enemy arent dead
	bool battleComplete = false;



	//stores enemy random choice
	int choice = 0;

	do {

		do {

			system("CLS");

			cout << "You are in a battle with " << enemy.getName() << ".\n";


			cout << "\nYou have " << player.getHealth() << " health.\n";

			cout << enemy.getName() << " has " << enemy.getHealth() << " health.";

			cout << "\nChoose your spell:\n\n1: Strike\n2: Heal\n3: Root\n4: Inflame\n\n";

			cin >> temp;
			system("CLS");
			switch (temp) {
			case 1:
				enemy.takeDamage(player.getDamage());
				cout << "You strike the enemy for " << player.getDamage() << " damage\n";
				inputLoop = false;
				break;
			case 2:
				player.heal(30);
				cout << "You heal for 30 health\n";
				inputLoop = false;
				break;
			case 3:
				if (player.getLuck() >= random(0, 10)) {

					if (playerRoot == true) {
						cout << "You tried to root the enemy, but it was already stuck to the ground\n";
					}
					else {
						playerRoot = true;
						cout << "You successfully rooted the enemy\n";
					}
				}
				else {
					cout << "Your spell failed, you dealt 10 base damage instead\n";
					enemy.takeDamage(10);
				}
				inputLoop = false;
				break;
			case 4:
				if (player.getLuck() >= random(0, 10)) {
					if (playerInflame == true) {
						cout << "You tried to set the enemy alight, but alas it was already on fire\n";
					}
					else {
						playerInflame = true;
						cout << "You successfully set the enemy alight\n";
					}


				}
				else {
					cout << "Your spell failed, you dealt 10 base damage instead\n";
					enemy.takeDamage(10);
				}
				inputLoop = false;
				break;
			default:
				system("CLS");
				cout << "Invalid Input";
				Sleep(1500);
				inputLoop = true;
				break;
			}

		} while (inputLoop == true);

		Sleep(1500);

		if (enemy.getDead() == true) {
			system("CLS");
			cout << "You have slain the enemy and can now progress forwards";
			Sleep(1500);
			battleComplete = true;
			return;
		}
		else {

			choice = random(0, 3);
			switch (choice) {
			case 0:
				cout << "\nThe enemy strikes for " << enemy.getDamage() << " damage";
				player.takeDamage(enemy.getDamage());
				break;
			case 1:
				cout << "\nThe enemy heals for 25 health";
				enemy.heal(25);
				break;
			case 2:
				if (enemy.getLuck() >= random(0, 10)) {
					if (enemyInflame == true) {
						cout << "\nThe enemy tried set you alight, but alas you were already on fire\n";
					}
					else {
						enemyInflame = true;
						cout << "\nThe enemy successfully set you alight\n";
					}
				}
				else {
					cout << "\nThe enemy's spell failed, it dealt 10 base damage instead\n";
					player.takeDamage(10);
				}
				break;
			default:
				cout << "\nThe enemy strikes for " << enemy.getDamage() << " damage";
				player.takeDamage(enemy.getDamage());
			}
			Sleep(1500);
		}
		
		if (player.getDead() == true) {
			system("CLS");
			cout << "You have died a sorrowful death";
			Sleep(1500);
			exit(1);
		}

		if (enemyInflame == true) {
			enemyStatCount += 1;
			cout << "\n\nYou recieved 10 damage from inflame";
			player.takeDamage(10);
			Sleep(1500);
			if (enemyStatCount >= 5 && player.getDead() == false) {
				cout << "\n\nInflame wore off";
				enemyInflame = false;
				enemyStatCount = 0;
				Sleep(1000);
			}
		}

		if (player.getDead() == true) {
			system("CLS");
			cout << "You have died a sorrowful death";
			Sleep(1500);
			exit;
		}

		if (playerInflame == true && enemy.getDead()==false) {
			playerStatCount += 1;
			cout << "\n\nThe enemy recieved 10 damage from inflame";
			enemy.takeDamage(10);
			Sleep(1500);
			if (playerStatCount >= 5 && player.getDead() == false) {
				cout << "\n\nInflame wore off";
				playerInflame = false;
				playerStatCount = 0;
				Sleep(1000);
			}

		}

		if (playerRoot == true && enemy.getDead() == false) {
			playerStatCount1 += 1;
			cout << "\n\nEnemy took 5 damage from root, you absorbed the energy";
			enemy.takeDamage(5);
			player.heal(5);
			Sleep(1500);
			if (playerStatCount1 >= 5 && enemy.getDead() == false) {
				cout << "\n\nRoot wore off";
				playerRoot = false;
				playerStatCount1 = 0;
				Sleep(1000);
			}
		}


		if (enemy.getDead() == true) {
			system("CLS");
			cout << "You have slain the enemy and can now progress forwards";
			Sleep(1500);
			battleComplete = true;
		}

	} while (battleComplete == false);
}
