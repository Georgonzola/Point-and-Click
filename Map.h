#pragma once
#include <iostream>
#include "Items.h"
#include "ScreenEntity.h"
#include "Player.h"
#include "Enemy.h"

using std::string;

class Map
{
private:

	ScreenEntity m_background;
	bool m_stairs = false;
	int m_direction;
	int m_xPos;
	int m_yPos;
	int m_zPos;

	bool m_printed;

	bool m_finish;

	int m_mapArray[4][3][3] =

	{		   //Floor 1 //Floor 2		  //Floor 1	//Floor 2		  //Floor 1	//Floor 2

		{{'X',	 1,		   11},		{'X',	2,		  'X'},		{'X',	3,		 'X'}},
		{{'X',	 4,		   12},		{'X',	5,		  'X'},		{'X',	6,		 13}},
		{{'X',	 7,		   14},		{'X',	8,		  15},		{'X',	9,		 16}},
		{{'X',	 'X',	   17},		{'X',	10,		  'X'},		{'X',	'X',	 18}}

	};

	/*
	Pantry		= 1
	Pond		= 2
	Shed		= 3
	Kitchen		= 4
	Garden		= 5
	S.Quarters	= 6
	DiningRoom	= 7
	Lobby		= 8
	Lounge		= 9
	F.Garden	= 10

	EnSuite		= 11
	Mst.Room	= 12
	Study		= 13
	Gst.Room.1	= 14
	Landing		= 15
	GameRoom	= 16
	Gst.Room.2	= 17
	BathRoom	= 18

	WineCellar	= 19
	*/

	bool m_completionMap[4][3][3] =
	{
		{{0,0,0}, {0,0,0}, {0,0,0}},
		{{0,0,0}, {0,0,0}, {0,0,0}},
		{{0,0,0}, {0,0,0}, {0,0,0}},
		{{0,0,0}, {0,0,0}, {0,0,0}},
	};


	float frontGardenCoords[3][4]{
	//flowers
	{3,36,135,178},
	//rock
	{196,233,151,178},
	//door
	{95,141,81,158},
	};

	float diningRoomCoords[3][4]{
	//platter
	{60,98,102,130},
	//cupboard
	{178,226,51,114},
	//exit
	{3,235,170,194},
	};

	float kitchenCoords[3][4]{
	//pot
	{131,183,61,97},
	//pantry
	{28,71,32,105},
	//exit
	{3,235,170,194},
	};

	float pantryCoords[3][4]{
	//fish food item
	{49,88,108,169},
	//baking powder item	
	{111,190,61,109},
	//exit
	{3,235,170,194},
	};

	float servantsQuartersCoords[2][4]{
	//box
	{15,116,36,134},
	//exit
	{3,235,170,194},
	};

	float loungeCoords[3][4]{
	//poker
	{70,100,62,115},
	//cabinet
	{167,228,86,113},
	//exit
	{3,235,170,194},
	};

	//doors/stairs left to right
	float lobbyCoords[7][4]{
		{12,25,26,153},
		{35,65,20,75},
		{70,100,3,75},
		{104,135,20,75},
		{173,203,20,75},
		{213,226,26,153},
		{3,235,170,194},
	};

public:

	Map();
	Map(int x, int y, int z);

	bool GetFinish();

	void MovePlayer(int x, int y, int z);
	void DisplayMap();
	void DrawRoom();


	int GetRoomID();

	void RunRoom(Items& Inventory, Player& player);

	void RunPantry(Items& Inventory);
	void RunPond(Items& Inventory);
	void RunShed(Items& Inventory);
	void RunKitchen(Items& Inventory);
	void RunGarden(Items& Inventory);
	void RunServantsQuarters(Items& Inventory);
	void RunDiningRoom(Items& Inventory);
	void RunLobby(Items& Inventory, Player& player);
	void RunLounge(Items& Inventory);
	void RunFrontGarden(Items& Inventory);

	void RunEnSuite(Items& Inventory);
	void RunMasterBedroom(Items& Inventory);
	void RunStudy(Items& Inventory);
	void RunGuestBedroom1(Items& Inventory);
	void RunLanding(Items& Inventory);
	void RunGameRoom(Items& Inventory);
	void RunGuestBedroom2(Items& Inventory);
	void RunBathRoom(Items& Inventory);
	void RunWineCellar(Items& Inventory);


	void mapCoords();

	void checkCoords(double mousex, double mousey, Items& inventory, Player& player);


	void setDirection(int dir);
	bool getPrinted();
	void setPrinted(bool val);

	void battle(Player& player, Enemy enemy);
};