#include "Maze.h"

using namespace std;

Maze::Maze()
{
	Init();
	m_Bat = 0;
	m_Won = false;
	cout << "." << endl;
	string name;

	cout << "Enter the name of your hero: " << endl;
	getline(cin, name);

	m_Player = new Player(name);
	m_Player->setRoom(m_pHead);
}

void Maze::Init()
{
	RoomFactory* factory = new RoomFactory();
	Monster* mob = 0;
	Room* roomH = 0;

	factory->WithName("h1");
	factory->AddItem(new Item("House Key", 1, false));
	factory->SetDesc("The House\n\nA ragged house.");
	m_pHead = factory->BuildRoom();
	SetTail(m_pHead);

	factory->WithName("f1");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->AddItem(new Weapon("The Twig", 2));
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	factory->WithName("reset");
	factory->SetDesc("The Shrine\n\nYou appear to be in a clearing, above you the moon shining gently through as you look around.\nThe only thing of note in the clearing is rather eerie; a large, grey, stone-carved statue about twice your height depicting a\nhooded figure with angelic wings. It holds its hands out with palms turned upward, facing the moon as if expecting\nit to pour water down upon it's hands. Several candles are list around the base of the statue, it's plinth\ncoming up to your waist.");
	factory->AddItem(new Item("A Strange Key", 1, false));
	m_Reset = factory->BuildRoom();
	AddRoom(GetReset(), Direction::NORTH);

	factory->WithName("f2");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	
	mob = new Monster("Kobold", 2, 2);
	mob->AddItem(new Item("Health Potion", 3, false));
	factory->WithMob(mob);

	mob = new Monster("Koblad", 2, 2);
	factory->WithMob(mob);

	mob = new Monster("Kobald", 4, 2);
	factory->WithMob(mob);

	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("f3");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("f4");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::SOUTH);

	factory->WithName("f5");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	roomH = factory->BuildRoom();
	roomH->setNext(GetRoom("f1"), Direction::WEST);
	roomH->setNext(GetRoom("f2"), Direction::NORTH);
	AddRoom(roomH, Direction::WEST);
	roomH = 0;

	factory->WithName("f6");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::SOUTH);

	factory->WithName("f7");
	factory->SetDesc("The Forest\n\nDark woods surround you but\nyou notice that to the west seems to be the side of\nthe house you were in earlier.");
	factory->AddItem(new Weapon("The Sword of (Some) Power", 4));
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::SOUTH);
	//TODO emotes

	factory->WithName("f8");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("f9");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("f10");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	factory->WithName("f11");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	roomH = factory->BuildRoom();
	roomH->setNext(GetRoom("f4"), Direction::WEST);
	AddRoom(roomH, Direction::NORTH);
	roomH = 0;

	factory->WithName("f12");
	factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from,\nall just barely too dark to see through...");
	factory->GenRandom(LevelType::FOREST);
	roomH = factory->BuildRoom();
	roomH->setNext(GetRoom("f3"), Direction::WEST);
	AddRoom(roomH, Direction::NORTH);
	roomH = 0;

	//Transition Forest -> Ruins

	factory->WithName("r1");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	factory->WithName("r2");
	factory->GenRandom(LevelType::RUIN);
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	factory->WithName("r3");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	factory->WithName("r4");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("r5");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("r6");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	AddRoom(factory->BuildRoom(), Direction::SOUTH);

	factory->WithName("r7");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("r8");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->GenRandom(LevelType::RUIN);
	roomH = factory->BuildRoom();
	roomH->setNext(GetRoom("r5"), Direction::EAST);
	AddRoom(roomH, Direction::NORTH);
	roomH = 0;

	factory->WithName("r9");
	factory->GenRandom(LevelType::RUIN);
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	AddRoom(factory->BuildRoom(), Direction::EAST);

	factory->WithName("r10");
	factory->GenRandom(LevelType::RUIN);
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	factory->WithName("r11");
	factory->GenRandom(LevelType::RUIN);
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	roomH = factory->BuildRoom();
	roomH->setNext(GetRoom("r8"), Direction::SOUTH);
	AddRoom(roomH, Direction::WEST);
	roomH = 0;

	factory->WithName("r12");
	factory->GenRandom(LevelType::RUIN);
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	roomH = factory->BuildRoom();
	roomH->setNext(GetRoom("r5"), Direction::SOUTH);
	AddRoom(roomH, Direction::WEST);
	roomH = 0;

	//Boss room?
	factory->WithName("r13");
	factory->SetDesc("The Ruins\n\nAncient, crumbling ruins of a forgotten world\nlie around you, unused for centuries.\nThere are several ways to navigate such a\nsprawling place...");
	factory->WithMob(new Monster("The Guardian", 15, 100));
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	//Transition Ruins -> Dungeon

	factory->WithName("end");
	factory->SetDesc("The Shrine\n\nThis wasn't quite what you expected.\nAfter such a fight you thought the door would be the way out but... something isn't right. For some reason you're back here, staring at that stupid statue again. Why do you keep coming back here? Does this mean you can never leave? If you have to walk all that way again... No, something isn't right. The ways to leave this place aren't the same; they're all blocked off. What is going on here...?");
	factory->AddItem(new Item("A Picture", 1, false));
	AddRoom(factory->BuildRoom(), Direction::NORTH);

	mob = 0;
	delete factory;
}

Maze::~Maze()
{
	delete m_Player;
	m_pHead = 0;
	m_pTail = 0;
	vector<Room*>::iterator iter;
	for (iter = instances.begin(); iter != instances.end(); ++iter)
	{
		delete *iter;
	}
}

void Maze::IssueCommand(Command cmd)
{
	Direction dir = Direction::UNSET;
	switch (cmd)
	{
	case NORTH:
		dir = Direction::NORTH;
		break;
	case EAST:
		dir = Direction::EAST;
		break;
	case SOUTH:
		dir = Direction::SOUTH;
		break;
	case WEST:
		dir = Direction::WEST;
		break;
	case LOOK:
		cout << m_Player->getRoom()->getDesc();
		if (!m_Player->getRoom()->getInv().empty()) { cout << "\nSomething interesting catches your eye..."; }
		cout << endl;
		break;
	case INTERACT:
		Interact();
		break;
	case ME:
		PrintCharacter();
		break;
	case null:
		cout << "You flail about running in circles only to realize you can't do that." << endl;
		break;
	default:
		break;
	}

	if (dir != Direction::UNSET)
	{
		if (MoveCheck(m_Player->getRoom(), dir))
		{
			Move(dir);
		}
	}
}

void Maze::PrintCharacter()
{
	cout << m_Player->getName() << endl;
	cout << "Health; " << m_Player->getHealth() << "/20" << endl;
	cout << "Armor; " << ((m_Player->GetArmor() == 0) ? "None" : m_Player->GetArmor()->getName() + ", " + to_string(((Armor*) m_Player->GetArmor())->getRes()) + " resistance") << endl;
	cout << "Shield; " << ((m_Player->GetShield() == 0) ? "None" : m_Player->GetShield()->getName() + ", " + to_string(((Shield*)m_Player->GetShield())->getDef()) + " defense") << endl;
	cout << "Weapon; " << ((m_Player->GetWeapon() == 0) ? "None" : m_Player->GetWeapon()->getName() + ", " + to_string(((Weapon*)m_Player->GetWeapon())->getDamage()) + " attack") << endl;
	cout << "Items; " << endl;
	if (m_Player->getInventory().empty())
	{
		cout << "Empty!" << endl;
	}
	else
	{
		int count = 1;
		for (Item* i : m_Player->getInventory())
		{
			cout << count << ". " << i->getName() << " (" << i->getAmt() << ")" << endl;
		}
	}
}

Room* Maze::GetHead() const
{
	return m_pHead;
}

Room* Maze::GetTail() const
{
	return m_pTail;
}

Room* Maze::GetReset() const
{
	return m_Reset;
}

Player* Maze::GetPlayer() const
{
	return m_Player;
}

void Maze::AddRoom(Room* room, Direction dir)
{
	m_pTail->setNext(room, dir);
	Room* old = m_pTail;
	instances.push_back(room);
	m_pTail = room;
	m_pTail->setNext(old, old->getOpp(dir));
	old = 0;
}

void Maze::SetReset(Room* room)
{
	m_Reset = room;
}

void Maze::SetHead(Room* room)
{
	m_pHead = room;
}

void Maze::SetTail(Room* room)
{
	m_pTail = room;
}

Command Maze::parseCommand(string cmd)
{
	if (cmd == "n" || cmd == "N") return Command::NORTH;
	else if (cmd == "w" || cmd == "W") return Command::WEST;
	else if (cmd == "s" || cmd == "S") return Command::SOUTH;
	else if (cmd == "e" || cmd == "E") return Command::EAST;
	else if (cmd == "i" || cmd == "I") return Command::INTERACT;
	else if (cmd == "l" || cmd == "L") return Command::LOOK;
	else if (cmd == "me") return Command::ME;
	else return Command::null;
}

Room* Maze::Move(Direction dir)
{
	Room* next = m_Player->getRoom()->getNext(dir);
	if (next == 0)
	{
		m_Player->setRoom(m_Reset);
	}
	else
	{
		m_Player->setRoom(next);
	}
	if (!next->GetMobs().empty())
	{
		cout << "Oh no! You have been beset upon by enemies! It's time to d-d-d-duel." << endl;
		m_Bat = new Battle(m_Player, next->GetMobs());
	}
	return (m_Player->getRoom());
}

Room* Maze::GetRoom(string name)
{
	vector<Room*>::iterator iter;
	for (iter = instances.begin(); iter != instances.end(); ++iter)
	{
		if ((*iter)->getName() == name)
		{
			return *iter;
		}
	}
	return 0;
}

void Maze::Interact()
{
	cout << "You look about to see if there is anything around and..." << endl;
	if (m_Player->getRoom()->getName() == "end")
	{
		cout << "Time seems to slow in this place as you look\nabout, searching for something... you aren't\nsure what. Eventually you approach\nthe statue, looking on the plinth\nwhere you notice something that seems to\nshine. Curious, you head over to it.\n\n"
			<< "What looks like a picture frame is\nflipped upside down. You furrow your brow as you\npick it up, going to turn it over and look at it.\nThe frame itself seems empty, a pitch black space\ninside the wooden outline. You stare at it for a long moment.\n" << endl;
		cout << ".";
		_sleep(1000);
		cout << ".";
		_sleep(1000);
		cout << "." << endl;
		_sleep(5000);

		cout << "Eventually another adventurer would find this place again,\nclueless of your own adventures. All that they would\nfind would be a picture frame standing upright\non the plinth off the odd statue, a random adventurer\nlooking out from within." << endl;
		m_Won = true;
		return;
	}
	else if (!m_Player->getRoom()->getInv().empty())
	{
		string ss;
		string tag = "";
		for (Item* i : m_Player->getRoom()->getInv())
		{
			if (i->isEquip()) //If the item is an equipable item
			{
				//class Equipable : public Item
				Equipable* e = (Equipable*) i; //Casting the item that is flagged equipable up to equipable
				//class Armor : public Equipable
				Armor* a = 0;
				//class Shield : public Equipable
				Shield* s = 0;
				//class Weapon : public Equipable
				Weapon* w = 0;
				string input;
				switch (e->getSlot()) //However, even though within the inventory returned from getInv() the slot returned is always -8000000, or somewhere around there, meaning some data is lost upon being stored as an Item. Am I missing something?
				{
				case Slots::ARMOR:
					a = (Armor*)e;
					cout << "...You found a piece of armor! " << a->getName() << ", with " << a->getRes() << " defense. Equip it? (You will throw away your old armor)" << endl;
					cout << "> ";
					cin >> input;
					if (input == "yes" || input == "Yes")
					{
						cout << "You have equiped " << a->getName() << "!" << endl;
						m_Player->setArmor(a);
						m_Player->getRoom()->removeItem(e->getName());
					}
					else
					{
						cout << "You leave " << a->getName() << " where you found it." << endl;
					}
					break;
				case Slots::SHIELD:
					s = (Shield*)e;
					cout << "...You found a shield! " << s->getName() << ", with " << s->getDef() << " defense. Equip it? (You will throw away your old shield)" << endl;
					cout << "> ";
					cin >> input;
					if (input == "yes" || input == "Yes")
					{
						cout << "You have equiped " << s->getName() << "!" << endl;
						m_Player->setShield(s);
						m_Player->getRoom()->removeItem(e->getName());
					}
					else
					{
						cout << "You leave " << s->getName() << " where you found it." << endl;
					}
					break;
				case Slots::SWORD:
					w = (Weapon*)e;
					cout << "...You found a weapon! " << w->getName() << ", with " << w->getDamage() << " attack. Equip it? (You will throw away your old weapon)" << endl;
					cout << "> ";
					cin >> input;
					if (input == "yes" || input == "Yes")
					{
						cout << "You have equiped " << w->getName() << "!" << endl;
						m_Player->setWeapon(w);
						m_Player->getRoom()->removeItem(e->getName());
					}
					else
					{
						cout << "You leave " << w->getName() << " where you found it." << endl;
					}
					break;
				default:
					cout << e->getSlot() << endl;
					break;
				}
			}
			else
			{
				if (i->getAmt() == 1)
				{
					ss += tag + to_string(i->getAmt()) + " " + i->getName();
				}
				else
				{
					ss += tag + to_string(i->getAmt()) + " " + i->getName() + "s";
				}
				tag = ", ";
				m_Player->addItem(i, false);
				m_Player->getRoom()->removeItem(i->getName());
			}
		}
		if (ss != ""){cout << "...found " << ss << " in the room!" << endl;}
	}
	else
	{
		cout << "...find nothing." << endl;
	}
}

//We'll parse room movement here in an almost event-like way.
//Whenever "move" is called move will format a string like this; "roomName_Direction" and then throw it through here.
//Now, as we dont want to get too intricate we'll just make static ones where the string will match up with what we're looking for
//and require some item or event to have occured already. AKA lot of code

bool Maze::MoveCheck(Room* room, Direction dir)
{
	string form = room->getName() + "_";
	if (dir == Direction::NORTH)
	{
		form += "north";
	}
	else if (dir == Direction::EAST)
	{
		form += "east";
	}
	else if (dir == Direction::SOUTH)
	{
		form += "south";
	}
	else if (dir == Direction::WEST)
	{
		form += "west";
	}
	if (form == "h1_north" && !m_Player->hasItem("House Key"))
	{
		cout << "Surprisingly enough, while the door seemed to be just barely holding on\nto it's hinges it still stands\nsturdy enough to stop you from leaving, seemingly locked.\nPerhaps a key is around here somewhere?" << endl;
		return false;
	}
	else if (form == "h1_east" || form == "h1_south" || form == "h1_west")
	{
		cout << "You search for something on the walls to no avail." << endl;
		return false;
	}

	if (form == "f1_east" || form == "f1_west")
	{
		cout << "It doesn't look like you can head this way..." << endl;
		return false;
	}
	else if (form == "f1_south")
	{
		cout << "The door seems to have shut closed behind you, locking..." << endl;
		return false;
	}

	if (form == "reset_north" || form == "reset_west")
	{
		cout << "You don't seem to be able to find a path through this direction." << endl;
		return false;
	}
	else if (form == "reset_south")
	{
		cout << "Something odd seems to have occured\nas you entered the clearing.\nYou can't find a way back..." << endl;
		return false;
	}

	if (form == "f6_west")
	{
		cout << "You search the side of the house\nbut don't find anything." << endl;
		return false;
	}

	if (form == "end_west" || form == "end_north" || form == "end_south" || form == "end_east")
	{
		cout << "This path is blocked... They all seemed blocked... What is this?" << endl;
		return false;
	}
	if (form != "h1_north") { cout << "You step into the unknown and..." << endl; }
	else { cout << "The key fits nicely into the lock, you open the door and..." << endl; }

	if (room->getNext(dir) == 0)
	{
		cout << "...something seems to click,\nall the light around you seeming to fade away\nwithout so much as a whisper.\nYou stumble around in the darkness for a while,\nbumping into a few trees,\nbefore you return to a vaguely familiar clearing,\na statue of an Angel\nstanding in the middle..." << endl;
		m_Player->setHealth(m_Player->getHealth() - 2);
	}
	else
	{
		string next = room->getNext(dir)->getName();
		if (form == "h1_north")
		{
			cout << "...Step out into the woods." << endl;
		}
		else if (*next.cbegin() == 'f')
		{
			cout << "...find a small clearing in the woods." << endl;
		}
		else if (next == "reset" || next == "end")
		{
			cout << "...find a large clearing with an odd statue..." << endl;
		}
	}
	return true;
}

bool Maze::HasWon() const
{
	return m_Won;
}

bool Maze::IsBattling() const
{
	return !(m_Bat == 0);
}

void Maze::SetBattle(Battle* b)
{
	m_Bat = b;
}

Battle* Maze::GetBattle() const
{
	return m_Bat;
}

void Maze::EndBattle()
{
	delete m_Bat;
	m_Bat = 0;
	m_Player->SetBattle(false);
}