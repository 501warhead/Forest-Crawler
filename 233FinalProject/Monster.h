#pragma once

#ifndef MONSTER_H
#define MONSTER_H

#include "Armor.h"
#include <vector>

class Monster
{
public:
	//Constructors/Deconstructors
	Monster(std::string Name, int dmg, int hp);
	~Monster();


	//Set/Adding functions
	void AddItem(Item* item);
	void SetWeapon(Equipable* weapon);
	void SetArmor(Equipable* armor);
	void SetHealth(int hp);
	void SetMaxHealth(int hp);
	void SetDamage(int dmg);
	void SetDrops(std::vector<Item*> drops);
	void RemoveItem(Item* item);
	void setDead(bool b);
	void setBoss(bool b);


	//Getters
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetDamage() const;
	bool isDead() const;
	bool isBoss() const;
	Equipable* GetWeapon() const;
	Equipable* GetArmor() const;
	std::vector<Item*> GetDrops() const;
	std::string GetName() const;
	
private:
	std::string m_Name;
	Equipable* m_Weap;
	Equipable* m_Armor;
	std::vector<Item*> m_Drops;
	int m_Dmg;
	int m_Health;
	int m_TotalH;
	bool m_Dead;
	bool m_Boss;
};

#endif