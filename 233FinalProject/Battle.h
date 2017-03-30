#pragma once

#ifndef BATTLE_H
#define BATTLE_H

#include "RoomFactory.h"

enum BattleAction
{
	ATTACK,
	DEFEND,
	CONSUME
};

class Battle
{
public:
	Battle(Player* player, std::vector<Monster*> mobs);
	~Battle();
	Player* GetPlayer() const;
	std::vector<Monster*> GetMobs() const;

	void Attack();
	void Defend();
	void Consume();

	void ParseInput();
private:
	void PassTime();
	Player* m_Play;
	std::vector<Monster*> m_Mobs;
	bool m_Def;
};

#endif
