#pragma once

class Items
{
private:
	bool m_keys[8] = { 0,0,0,0,0,0,0,0 };
	/*
	1 = FrontDoor
	2 = Kitchen
	3 = Pantry
	4 = Master Bedroom
	5 = Ornate (dining room cabinet)
	6 = Guest Bedroom
	7 = Garden
	8 = Basement
	*/

	bool m_spells[6] = { 0,0,0,0,0,0 };
	/*
	1 = Summon Goblins
	2 = Summon Golem
	3 = Freeze
	4 = Burn
	5 = Mist
	6 = Root
	*/

	bool m_keyItems[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	/*
	1 = Roses (Potion)
	2 = Baking Powder (Potion)
	3 = Fireplace Poker (Potion)
	4 = Potion

	5 = Fish Food (Pond)
	6 = Gloves (Pond)
	7 = Pond Fish

	8 = Anchor (Hook)
	9 = Pool Cue (Hook)
	10 = Duct Tape (Hook)
	11 = Hook (Hook)

	12 = LockBox Code
	13 = Scissors
	*/

	bool m_dungeonItems[5] = { 0,0,0,0,0 };
	/*
	1 =
	2 =
	3 =
	4 =
	5 =
	*/


	int m_selected = 10;

public:

	Items();

	bool GetKey(int a);
	bool GetSpells(int a);
	bool GetKeyItem(int a);
	bool GetDungeonItem(int a);

	int GetSelected();
	void SetSelected(int a);

	void SetKey(int a);
	void SetSpells(int a);
	void SetKeyItem(int a);
	void SetDungeonItem(int a);

	void PrintItems();
};