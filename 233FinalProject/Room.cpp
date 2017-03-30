#include "Room.h"

using namespace std;

Room::Room(string name)
{
	m_Name = name;
	NORTH = 0;
	SOUTH = 0;
	EAST = 0;
	WEST = 0;
}

Room::~Room()
{
	NORTH = 0;
	SOUTH = 0;
	EAST = 0;
	WEST = 0;
	m_Mobs.clear();
	m_Inv.clear();
}

string Room::getName() const
{
	return m_Name;
}

Room* Room::getNext(Direction direct) const
{
	switch (direct)
	{
	case Direction::NORTH:
		return NORTH;
	case Direction::SOUTH:
		return SOUTH;
	case Direction::EAST:
		return EAST;
	case Direction::WEST:
		return WEST;
	default:
		return 0;
	}
}

vector<Item*> Room::getInv() const
{
	return m_Inv;
}

vector<Monster*> Room::GetMobs() const
{
	return m_Mobs;
}

string Room::getDesc() const
{
	return m_Desc;
}

Direction Room::getOpp(Direction dir) const
{
	switch (dir)
	{
	case Direction::NORTH: return Direction::SOUTH;
	case Direction::SOUTH: return Direction::NORTH;
	case Direction::EAST: return Direction::WEST;
	case Direction::WEST: return Direction::EAST;
	default: return Direction::UNSET;
	}
}

void Room::setDesc(string desc)
{
	m_Desc = desc;
}

void Room::setNext(Room* next, Direction direct)
{
	switch (direct)
	{
	case Direction::NORTH:
		NORTH = next;
		return;
	case Direction::SOUTH:
		SOUTH = next;
		return;
	case Direction::EAST:
		EAST = next;
		return;
	case Direction::WEST:
		WEST = next;
		return;
	default:
		return;
	}
}

void Room::addItem(Item* item)
{
	m_Inv.push_back(item);
}

void Room::setInventory(vector<Item*> inv)
{
	m_Inv = inv;
}

void Room::setMobs(vector<Monster*> mobs)
{
	m_Mobs = mobs;
}

bool Room::removeItem(string name)
{
	vector<Item*>::iterator iter;
	for (iter = m_Inv.begin(); iter != m_Inv.end(); ++iter)
	{
		if ((*iter)->getName() == name)
		{
			m_Inv.erase(iter);
			return true;
		}
	}
	return false;
}