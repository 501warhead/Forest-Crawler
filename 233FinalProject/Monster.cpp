#include "Monster.h";

using namespace std;

Monster::Monster(string Name, int dmg, int hp)
{
	m_Name = Name;
	m_Weap = 0;
	m_Dmg = dmg;
	m_Health = hp;
	m_Dead = false;
	m_Boss = false;
}

Monster::~Monster()
{
	m_Drops.clear();
	delete m_Weap;
}

void Monster::AddItem(Item* item)
{
	for (Item* i : m_Drops)
	{
		if (i->getName() == item->getName())
		{
			i->setAmt(item->getAmt() + i->getAmt());
			delete item;
			return;
		}
	}
	m_Drops.push_back(item);
}

void Monster::SetWeapon(Equipable* weapon)
{
	m_Weap = weapon;
}

void Monster::SetArmor(Equipable* armor)
{
	m_Armor = armor;
}

void Monster::SetHealth(int hp)
{
	m_Health = hp;
}

void Monster::SetMaxHealth(int hp)
{
	m_TotalH = hp;
}

void Monster::SetDamage(int dmg)
{
	m_Dmg = dmg;
}

void Monster::SetDrops(vector<Item*> drops)
{
	m_Drops = drops;
}

void Monster::RemoveItem(Item* item)
{
	vector<Item*>::iterator iter;
	for (iter = m_Drops.begin(); iter != m_Drops.end(); ++iter)
	{
		if ((*iter)->getName() == item->getName())
		{
			m_Drops.erase(iter);
			return;
		}
	}
}

void Monster::setDead(bool b)
{
	m_Dead = b;
}

void Monster::setBoss(bool b)
{
	m_Boss = b;
}

int Monster::GetHealth() const
{
	return m_Health;
}

int Monster::GetMaxHealth() const
{
	return m_TotalH;
}

int Monster::GetDamage() const
{
	return m_Dmg;
}

bool Monster::isDead() const
{
	return m_Dead;
}

bool Monster::isBoss() const
{
	return m_Boss;
}

Equipable* Monster::GetWeapon() const
{
	return m_Weap;
}

Equipable* Monster::GetArmor() const
{
	return m_Armor;
}

vector<Item*> Monster::GetDrops() const
{
	return m_Drops;
}

string Monster::GetName() const
{
	return m_Name;
}