#include <iostream>
#include "Shield.h"

using namespace std;

Shield::Shield(string name, int def) : Equipable(name, Slots::SHIELD)
{
	m_Def = def;
}

int Shield::getDef() const
{
	return m_Def;
}