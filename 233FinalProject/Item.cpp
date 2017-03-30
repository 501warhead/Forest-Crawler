#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(string name, int amt, bool equip = false)
{
	m_Name = name;
	m_Amt = amt;
	m_Eq = equip;
}

string Item::getName() const
{
	return m_Name;
}

int Item::getAmt() const
{
	return m_Amt;
}

bool Item::isEquip() const
{
	return m_Eq;
}

void Item::setAmt(int i)
{
	m_Amt = i;
}