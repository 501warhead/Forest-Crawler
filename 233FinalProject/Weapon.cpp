#include <iostream>
#include "Weapon.h"

using namespace std;

Weapon::Weapon(string name, int dmg) : Equipable(name, Slots::SWORD)
{
	m_Damage = dmg;
}

int Weapon::getDamage() const
{
	return m_Damage;
}