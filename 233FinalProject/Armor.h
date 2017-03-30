#pragma once

#ifndef ARMOR_H
#define ARMOR_H

#include "Weapon.h"

class Armor : public Equipable
{
public:
	Armor(std::string name, int resist);
	int getRes() const;
private:
	int m_Res;
};

#endif