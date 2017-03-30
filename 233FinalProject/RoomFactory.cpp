#include "RoomFactory.h"

using namespace std;

RoomFactory::RoomFactory()
{
	m_Name = "default_room_name";
}

void RoomFactory::WithName(string name)
{
	m_Name = name;
}

void RoomFactory::WithMob(Monster* mob)
{
	m_Mobs.push_back(mob);
}

void RoomFactory::AddItem(Item* item)
{
	for (Item* i : m_Inv)
	{
		if (i->getName() == item->getName())
		{
			i->setAmt(item->getAmt() + i->getAmt());
			delete item;
			return;
		}
	}
	m_Inv.push_back(item);
}

void RoomFactory::RemoveItem(Item* item)
{
	return this->RemoveItem(item->getName());
}

void RoomFactory::RemoveItem(std::string name)
{
	vector<Item*>::iterator iter;
	for (m_Inv.begin(); iter != m_Inv.end(); ++iter)
	{
		if ((*iter)->getName() == name)
		{
			m_Inv.erase(iter);
			return;
		}
	}
}

void RoomFactory::SetRoom(Room* room, Direction direct)
{
	switch (direct)
	{
	case Direction::NORTH:
		m_Rooms[0] = room;
		return;
	case Direction::EAST:
		m_Rooms[1] = room;
		return;
	case Direction::SOUTH:
		m_Rooms[2] = room;
		return;
	case Direction::WEST:
		m_Rooms[3] = room;
		return;
	default:
		return;
	}
}

void RoomFactory::SetDesc(string desc)
{
	m_Desc = desc;
}

//Unfortunately, this code basically threw either bad allocation or the data didnt save correctly. Commented out, adventure is terrible now :(
void RoomFactory::GenRandom(LevelType type)
{
	//srand(time(0));
	//int val = (rand() % 100 + 1);

	//switch (type)
	//{
	//case LevelType::FOREST:
	//	if (val < 50 && val > 45) //46 - 49
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 2 + 1), false));
	//	}
	//	else if (val < 75) //50 - 74
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 3 + 2), false));
	//	}
	//	else if (val < 100) //75 - 99
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 5 + 3), false));
	//	}
	//	else if (val > 100) //100+
	//	{
	//		AddItem(new Weapon("The Blade of Luck", (rand() % 30 + 1)));
	//	}
	//	break;
	//case LevelType::RUIN:
	//	if (val < 50 && val > 45) //46 - 49
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 2 + 1), false));
	//	}
	//	else if (val < 75) //50 - 74
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 3 + 2), false));
	//	}
	//	else if (val < 100) //75 - 99
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 5 + 3), false));
	//	}
	//	else if (val > 100) //100+
	//	{
	//		AddItem(new Armor("The Armor of Fortune", (rand() % 30 + 1)));
	//	}
	//	break;
	//case LevelType::DUNGEON:
	//	if (val < 50 && val > 45) //46 - 49
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 2 + 1), false));
	//	}
	//	else if (val < 75) //50 - 74
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 3 + 2), false));
	//	}
	//	else if (val < 100) //75 - 99
	//	{
	//		AddItem(new Item("Health Potion", (rand() % 5 + 3), false));
	//	}
	//	else if (val > 100) //100+
	//	{
	//		AddItem(new Shield("The Shield of Prosperity", (rand() % 30 + 1)));
	//	}
	//	break;
	//default:
	//	break;
	//}

	//srand(time(0));
	//val = (rand() % 100 + 1);
	//int lval = 0;
	//int amt = (rand() % ((type == LevelType::DUNGEON) ? 3 : ((type == LevelType::RUIN) ? 2 : 1) + 2) + 1);
	//Monster mob = Monster("", 0, 0);
	//switch (type)
	//{
	//case LevelType::FOREST:
	//	if (val < 60 && val > 30)
	//	{
	//		for (int i = 0; i <= amt; ++i)
	//		{
	//			mob = Monster("Kobold", 2, 4);
	//			lval = (rand() % 50 + 1);
	//			if (lval < 5)
	//			{
	//				mob.AddItem(new Weapon("Stolen Candle", 4));
	//			}
	//			else if (lval < 15)
	//			{
	//				mob.AddItem(new Armor("Some random greens", 6));
	//			}
	//			else if (lval == 50)
	//			{
	//				mob.AddItem(new Shield("Hogger-hide shield. Poor guy.", 10));
	//			}
	//			m_Mobs.push_back(&mob);
	//		}
	//	}
	//	break;
	//case LevelType::RUIN:
	//	if (val < 60 && val > 30)
	//	{
	//		for (int i = 0; i <= amt; ++i)
	//		{
	//			mob = Monster("Stone Golem", 2, 20);
	//			lval = (rand() % 50 + 1);
	//			if (lval < 5)
	//			{
	//				mob.AddItem(new Weapon("The Golem's Fist", 10));
	//			}
	//			else if (lval < 15)
	//			{
	//				mob.AddItem(new Shield("The Golem's Face", 5));
	//			}
	//			else if (lval == 50)
	//			{
	//				mob.AddItem(new Armor("T-60 BOS Sentinel MK. VI Chestpiece", 40));
	//			}
	//			m_Mobs.push_back(&mob);
	//		}
	//	}
	//	break;
	//case LevelType::DUNGEON:
	//	if (val < 60 && val > 30)
	//	{
	//		for (int i = 0; i <= amt; ++i)
	//		{
	//			mob = Monster("Spooky Scary Skeleton", 4, 10);
	//			lval = (rand() % 50 + 1);
	//			if (lval < 5)
	//			{
	//				mob.AddItem(new Weapon("The Thigh Bone is connected to the...", 12));
	//			}
	//			else if (lval < 15)
	//			{
	//				mob.AddItem(new Armor("Dharok's Platechest", 8));
	//			}
	//			else if (lval == 50)
	//			{
	//				mob.AddItem(new Weapon("The \"Bonestorm\"", 30));
	//			}
	//			m_Mobs.push_back(&mob);
	//		}
	//	}
	//	break;
	//default:
	//	break;
	//}
	/*
	Randomly generated things;
	Items;
	Health Potions
	
	Mobs:
	Kobold
	Radscorpion
	Deathclaw
	Stone Construct
	Steel Construct
	The Iron Sentinel
	The Eternal Colossus

	*/
}

Room* RoomFactory::BuildRoom()
{
	Room* room = new Room(m_Name);
	room->setInventory(m_Inv);
	room->setMobs(m_Mobs);

	room->setDesc(m_Desc);

	Reset();

	return room;
}

void RoomFactory::Reset()
{
	m_Name = "";
	m_Inv.clear();
	m_Mobs.clear();
	m_Rooms[0] = 0;
	m_Rooms[1] = 0;
	m_Rooms[2] = 0;
	m_Rooms[3] = 0;
	m_Desc = "";
}