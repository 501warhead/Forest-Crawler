#pragma once

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Monster.h"

enum class Direction
{
	NORTH = 0,
	EAST,
	SOUTH,
	WEST,
	UNSET
};

enum class LevelType
{
	FOREST = 1,
	RUIN,
	DUNGEON
};

class Room
{
public:
	Room(std::string name);
	~Room();
	std::string getName() const;
	Room* getNext(Direction direct) const;
	std::vector<Item*> getInv() const;
	std::vector<Monster*> GetMobs() const;
	std::string getDesc() const;
	Direction getOpp(Direction dir) const;

	void setDesc(std::string desc);
	void setNext(Room* next, Direction direct);
	void addItem(Item* item);
	void setInventory(std::vector<Item*> inv);
	void setMobs(std::vector<Monster*> mobs);
	bool removeItem(std::string name);
private:
	Room* NORTH;
	Room* SOUTH;
	Room* EAST;
	Room* WEST;
	std::string m_Desc;
	std::string m_Name;
	std::vector<Item*> m_Inv;
	std::vector<Monster*> m_Mobs;
};

#endif
