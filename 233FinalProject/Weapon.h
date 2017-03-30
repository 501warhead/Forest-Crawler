#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "Shield.h"

class Weapon : public Equipable
{
public:
	Weapon(std::string name, int dmg);
	int getDamage() const;
private:
	int m_Damage;
};

#endif
