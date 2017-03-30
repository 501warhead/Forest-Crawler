#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
	Item(std::string name, int Amt, bool equip);
	std::string getName() const;
	int getAmt() const;
	bool isEquip() const;

	void setAmt(int i);
private:
	std::string m_Name;
	int m_Amt;
	bool m_Eq;
};

#endif
