#include <iostream>
#include "Armor.h"

using namespace std;

Armor::Armor(string name, int resist) : Equipable(name, Slots::ARMOR)
{
	m_Res = resist;
}

int Armor::getRes() const
{
	return m_Res;
}