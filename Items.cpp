#include "Items.h"
#include "windows.h"
#include <iostream>

Items::Items()
{
}


///////////////////////////////////////////////////////////////////////////////////////////////
/// GETTERS
///////////////////////////////////////////////////////////////////////////////////////////////

bool Items::GetKey(int a){return m_keys[a];}

bool Items::GetSpells(int a){return m_spells[a];}

bool Items::GetKeyItem(int a){return m_keyItems[a];}

bool Items::GetDungeonItem(int a){return m_dungeonItems[a];}

int Items::GetSelected() { return m_selected; }
///////////////////////////////////////////////////////////////////////////////////////////////
/// SETTERS
///////////////////////////////////////////////////////////////////////////////////////////////

void Items::SetSelected(int a) { m_selected = a; }

void Items::SetKey(int a) { m_keys[a] = true; }

void Items::SetSpells(int a){ m_spells[a] = true; }

void Items::SetKeyItem(int a){ m_keyItems[a] = true; }

void Items::SetDungeonItem(int a){ m_dungeonItems[a] = true; }


//prints inventory
void Items::PrintItems()
{
	system("CLS");
	if (GetKeyItem(0)) {
		std::cout << "Roses\n";}

	if (GetKeyItem(1)) {
		std::cout << "Baking Powder\n";}

	if (GetKeyItem(2)) {
		std::cout << "Poker\n";}

	if (GetKeyItem(3)) {
		std::cout << "Potion\n";}

	if (GetKeyItem(4)) {
		std::cout << "Fish Food\n";}

	if (GetKeyItem(5)) {
		std::cout << "Gloves\n";}

	if (GetKeyItem(6)) {
		std::cout << "Pond Fish\n";}

	if (GetKeyItem(7)) {
		std::cout << "Anchor\n";}

	if (GetKeyItem(8)) {
		std::cout << "Pool Cue\n";}

	if (GetKeyItem(9)) {
		std::cout << "Duct Tape\n";}

	if (GetKeyItem(10)) {
		std::cout << "Hook\n";}

	if (GetKeyItem(11)) {
		std::cout << "Scissors\n";}

	if (GetKeyItem(12)) {
		std::cout << "Lockbox Code\n";}

	Sleep(5000);
}
