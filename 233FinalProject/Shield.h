#pragma once

#ifndef SHIELD_H
#define SHIELD_H

#include "Equipable.h"

class Shield : public Equipable
{
public:
	Shield(std::string name, int def);
	int getDef() const;
private:
	int m_Def;
};

#endif
