#include "Player.h"
#include <string>

using namespace std;

/*
class Player
{
public:
Player(std::string name, std::vector<Item>* inventory, Room* room);
~Player();
std::string getName() const;
int getHealth() const;
void setHealth(int amt);
std::vector<Item>* getInventory() const;
Room* getRoom() const;

void Attack(Monster* target);
void setWeapon(Equipable* weap);
void setArmor(Equipable* arm);
void setShield(Equipable* shield);
void setRoom(Room* room);
void addItem(Item* item);
bool removeItem(std::string name);
void setInv(std::vector<Item>* inv);
bool hasItem(std::string name);
private:
int m_Health;
std::string m_Name;
std::vector<Item>* m_Inv;
Equipable* m_Weapon;
Equipable* m_Armor;
Equipable* m_Shield;
Room* m_Room;
};
*/

Player::Player(string name)
{
	m_Name = name;
	m_Room = 0;
	m_Health = 20;
	m_Weapon = 0;
	m_Armor = 0;
	m_Shield = 0;
	m_Bat = false;
}

Player::~Player()
{
	m_Room = 0;
	delete m_Weapon;
	delete m_Armor;
	delete m_Shield;
}

Equipable* Player::GetWeapon() const
{
	return m_Weapon;
}

Equipable* Player::GetArmor() const
{
	return m_Armor;
}

Equipable* Player::GetShield() const
{
	return m_Shield;
}

string Player::getName() const
{
	return m_Name;
}

int Player::getHealth() const
{
	return m_Health;
}

void Player::setHealth(int amt)
{
	m_Health = amt;
	if (m_Health > 20)
	{
		m_Health = 20;
	}
}

vector<Item*> Player::getInventory() const
{
	return m_Inv;
}

Room* Player::getRoom() const
{
	return m_Room;
}

bool Player::IsBattling() const
{
	return m_Bat;
}

int Player::GetDamage() const
{
	if (m_Weapon != 0)
	{
		Weapon* w = (Weapon*)m_Weapon;
		return w->getDamage() + 1;
	}
	else
	{
		return 1;
	}
}

void Player::SetBattle(bool b)
{
	m_Bat = b;
}

void Player::Attack(Monster* target)
{
	//Big TODO.
}

void Player::setWeapon(Equipable* weap)
{
	m_Weapon = weap;
}

void Player::setArmor(Equipable* arm)
{
	//Armor* a = (Armor*) &arm;
	m_Armor = arm;
}

void Player::setShield(Equipable* shield)
{
	m_Shield = shield;
}

void Player::setRoom(Room* room)
{
	m_Room = room;
}

void Player::addItem(Item* item, bool text)
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

	if (text)
	{
		cout << "You have picked up " << item->getAmt() << " of " << item->getName() << endl;
	}
}

bool Player::removeItem(string name)
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

void Player::setInv(vector<Item*> inv)
{
	m_Inv = inv;
}

bool Player::hasItem(string name)
{
	if (!m_Inv.empty())
	{
		vector<Item*>::iterator iter;
		for (iter = m_Inv.begin(); iter != m_Inv.end(); ++iter)
		{
			if ((*iter)->getName() == name)
			{
				return true;
			}
		}
	}
	return false;
}