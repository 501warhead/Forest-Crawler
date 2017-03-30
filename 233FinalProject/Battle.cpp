#include "Battle.h";

using namespace std;

Battle::Battle(Player* player, vector<Monster*> mobs)
{
	m_Play = player;
	m_Play->SetBattle(true);
	m_Mobs = mobs;
	ParseInput();
}

Battle::~Battle()
{
	m_Play->SetBattle(false);
	for (Monster* mob : m_Mobs)
	{
		if (!mob->GetDrops().empty())
		{
			string ss;
			string prefix = "";
			for (Item* i : mob->GetDrops())
			{
				m_Play->addItem(i, false);
				mob->RemoveItem(i);
				ss += prefix + i->getName() + " (" + to_string(i->getAmt()) +")";
				prefix = ", ";
			}
			cout << "You discovered " << ss << " on the body of the " << mob->GetName() << endl;
		}
	}
	m_Play = 0;
}

Player* Battle::GetPlayer() const
{
	return m_Play;
}

vector<Monster*> Battle::GetMobs() const
{
	return m_Mobs;
}

void Battle::Attack()
{
	cout << "Who do you want to attack?" << endl;
	int slot = 1;
	int input;
	for (Monster* mob : m_Mobs)
	{
		if (!mob->isDead())
		{
			cout << slot << ". " << mob->GetName() << endl;
			++slot;
		}
	}
	cout << "> ";
	cin >> input;
	if (!cin)
	{
		cout << "Error; Please select one of the above." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return ParseInput();
	}
	else
	{
		if (input < slot)
		{
			int count = 1;
			for (Monster* mob : m_Mobs)
			{
				if (!mob->isDead())
				{
					if (count == input)
					{
						mob->SetHealth(mob->GetHealth() - m_Play->GetDamage());
						cout << "You strike the " << mob->GetName() << " for " << m_Play->GetDamage() << "!" << endl;
						if (mob->GetHealth() <= 0)
						{
							cout << "You have slain the " << mob->GetName() << "!" << endl;
							mob->setDead(true);
						}
						int co = 0;
						for (Monster* mob : m_Mobs)
						{
							if (mob->isDead()) { ++co; }
						}
						if (co >= m_Mobs.size())
						{
							cout << "You have defeated the creatures!" << endl;
							return;
						}
						else
						{
							return PassTime();
						}
					}
					else
					{
						++count;
					}
				}
				if (count > slot)
				{
					break;
				}
			}
			return PassTime();
		}
		else
		{
			cout << "Error; Please select one of the above." << endl;
			return ParseInput();
		}
	}
	
}

void Battle::Defend()
{
	m_Def = true;
	return PassTime();
}

void Battle::Consume()
{
	Item* pot = 0;
	for (Item* it : m_Play->getInventory())
	{
		if (it->getName() == "Health Potion")
		{
			pot = it;
		}
	}
	if (pot != 0)
	{
		m_Play->setHealth(m_Play->getHealth() + 5);
		if (pot->getAmt() > 1)
		{
			pot->setAmt(pot->getAmt() - 1);
		}
		else
		{
			m_Play->removeItem(pot->getName());
			delete pot;
		}
		return PassTime();
	}
	else
	{
		cout << "You're all out of health potions!" << endl;
		return ParseInput();
	}
}

void Battle::ParseInput()
{
	int input;
	cout << "Battle Menu;" << endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Consume Health Potion (if you have one)" << endl;
	cout << "4. Inspect enemies & yourself" << endl;
	cout << "> ";
	cin >> input;
	int count = 0;
	if (cin)
	{
		switch (input)
		{
		case 1: return Attack();
		case 2: return Defend();
		case 3: return Consume();
		case 4:
			cout << endl;
			cout << "Inspection!" << endl;
			cout << "-------------------------------" << endl;
			cout << "You; " << m_Play->getName() << endl;
			cout << "Health; " << m_Play->getHealth() << "/20" << endl;
			cout << "Armor; " << ((m_Play->GetArmor() == 0) ? "None" : m_Play->GetArmor()->getName() + ", " + to_string(((Armor*)m_Play->GetArmor())->getRes()) + " resistance") << endl;
			cout << "Shield; " << ((m_Play->GetShield() == 0) ? "None" : m_Play->GetShield()->getName() + ", " + to_string(((Shield*)m_Play->GetShield())->getDef()) + " defense") << endl;
			cout << "Weapon; " << ((m_Play->GetWeapon() == 0) ? "None" : m_Play->GetWeapon()->getName() + ", " + to_string(((Weapon*)m_Play->GetWeapon())->getDamage()) + " attack") << endl;
			cout << "Items; " << endl;
			if (m_Play->getInventory().empty())
			{
				cout << "Empty!" << endl;
			}
			else
			{
				int count = 1;
				for (Item* i : m_Play->getInventory())
				{
					cout << count << ". " << i->getName() << " (" << i->getAmt() << ")" << endl;
				}
			}
			cout << "-------------------------------" << endl;
			cout << "Enemies; " << endl;
			for (Monster* mob : m_Mobs)
			{
				cout << count << ". " << mob->GetName() << ", " << mob->GetHealth() << " hp, " << mob->GetDamage() << " strength." << endl;
				++count;
			}
			cout << "-------------------------------" << endl;
			return ParseInput();
		default:
			return ParseInput();
		}
	}
	else
	{
		cout << "Error; Invalid input." << endl;
		cin.clear();
		return ParseInput();
	}

}

void Battle::PassTime()
{
	if (m_Play->getHealth() > 0)
	{
		int count = 0;
		for (Monster* m : m_Mobs)
		{
			if (!m->isDead())
			{
				Armor* a = 0;
				Shield* s = 0;
				if (m_Play->GetArmor() != 0)
				{
					a = (Armor*)m_Play->GetArmor();
				}
				if (m_Play->GetShield() != 0)
				{
					s = (Shield*)m_Play->GetShield();
				}
				//since this is like a fucking headache and a half, basically what I'm doing is checking to see if the player
				//is defending. If they are defending I ask; Do you have a shield? Are you wearing armor? And do calculations based off
				//of these things, to avoid calling methods on a null object. It's basically just filtering down so I avoid the
				//null pointer doing a->GetRes() when a = 0 would give me
				int damage = m_Def ? ((a == 0) ? ((s == 0) ? m->GetDamage() - 1 : m->GetDamage() - s->getDef()) : ((s == 0) ? m->GetDamage() - a->getRes() : m->GetDamage() - (a->getRes() + s->getDef()))) : ((a == 0) ? m->GetDamage() : m->GetDamage() - a->getRes());
				if (damage < 0) { damage = 0; }
				cout << m->GetName() << " hits you for " << damage << "!" << endl;
				m_Play->setHealth(m_Play->getHealth() - damage);
			}
			else
			{
				cout << m->GetName() << " is dead!" << endl;
				++count;
			}
		}
		if (count >= m_Mobs.size())
		{
			cout << "You have defeated the creatures!" << endl;
			return;
		}
		else
		{
			m_Def = false;
			return ParseInput();
		}
	}
	else
	{
		return;
	}

}