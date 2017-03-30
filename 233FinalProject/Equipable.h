#pragma once

#ifndef EQUIPABLE_H
#define EQUIPABLE_H

#include "Item.h"

enum Slots
{
	ARMOR = 0,
	SWORD,
	SHIELD
};

class Equipable : public Item
{
public:
	Equipable(std::string name, Slots slot);
	Slots getSlot() const;
private:
	Slots m_Slot;
};

#endif