#pragma once


#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H

#include "Player.h"
#include <random>
#include <time.h>

class RoomFactory
{
public:
	RoomFactory();
	void WithName(std::string name);
	void WithMob(Monster* mob);
	void AddItem(Item* Item);
	void RemoveItem(Item* Item);
	void RemoveItem(std::string name);
	void SetRoom(Room* room, Direction direct);
	void SetDesc(std::string desc);
	void Reset();

	void GenRandom(LevelType type);

	Room* BuildRoom();
private:
	std::string m_Name;
	std::vector<Item*> m_Inv;
	std::vector<Monster*> m_Mobs;
	std::string m_Desc;
	Room* m_Rooms[4];
	//0 - north 1 - east 2 - south - 3 west
};

#endif