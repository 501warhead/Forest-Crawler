#pragma once

#ifndef MAZE_H
#define MAZE_H

#include "Battle.h"

enum Command
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	LOOK,
	INTERACT,
	ME,
	null
};

class Maze
{
public:
	Maze();
	~Maze();
	void IssueCommand(Command cmd);
	Command parseCommand(std::string cmd);
	Room* Move(Direction dir);
	Room* GetHead() const;
	Room* GetTail() const;
	Room* GetReset() const;
	Player* GetPlayer() const;
	void AddRoom(Room* room, Direction dir);
	void SetReset(Room* room);
	void SetHead(Room* room);
	void SetTail(Room* room);
	Room* GetRoom(std::string name);
	void Interact();
	bool MoveCheck(Room* room, Direction dir);
	void PrintCharacter();
	bool HasWon() const;

	bool IsBattling() const;
	void SetBattle(Battle* b);
	Battle* GetBattle() const;
	void EndBattle();
private:
	void Init();
	Player* m_Player;
	std::vector<Room*> instances;
	Room* m_pHead;
	Room* m_pTail;
	Room* m_Reset;
	Battle* m_Bat;
	bool m_Won;
};

#endif