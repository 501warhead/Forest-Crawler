#include "Equipable.h"
#include <iostream>

using namespace std;

Equipable::Equipable(string name, Slots slot) : Item(name, 1, true)
{
	m_Slot = slot;
}
//0 - armor
//1 - weapon
//2 - shield
Slots Equipable::getSlot() const
{
	return m_Slot;
}