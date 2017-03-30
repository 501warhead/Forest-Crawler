#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "Room.h"

class Player
{
public:
	Player(std::string name);
	~Player();
	
	int getHealth() const;
	int GetDamage() const;
	Equipable* GetWeapon() const;
	Equipable* GetArmor() const;
	Equipable* GetShield() const;
	Room* getRoom() const;
	std::string getName() const;
	std::vector<Item*> getInventory() const;

	bool IsBattling() const;

	void setHealth(int amt);
	void SetBattle(bool b);
	void Attack(Monster* target);
	void setWeapon(Equipable* weap);
	void setArmor(Equipable* arm);
	void setShield(Equipable* shield);
	void setRoom(Room* room);
	void addItem(Item* item, bool text);
	bool removeItem(std::string name);
	void setInv(std::vector<Item*> inv);
	bool hasItem(std::string name);
private:
	int m_Health;
	std::string m_Name;
	std::vector<Item*> m_Inv;
	Equipable* m_Weapon;
	Equipable* m_Armor;
	Equipable* m_Shield;
	Room* m_Room;
	bool m_Bat;
};


#endif