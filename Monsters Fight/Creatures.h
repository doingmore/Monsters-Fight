#ifndef Monsters_H
#define Monsters

#include <string>
#include <array>
#include <string_view>

class Creature
{
protected:
	std::string m_name;
	char m_symbol{};
	int m_health{};
	int m_damage{};
	int m_gold{};

public:
	Creature(const std::string& name,const char& symbol, int health, int damage, int gold)
		: m_name{ name }
		, m_symbol{ symbol }
		, m_health{ health }
		, m_damage{ damage }
		, m_gold{ gold }
	{
	}

	char getSymbol() const { return m_symbol; }
	const std::string& getName() const { return m_name; }
	int getGold() const { return m_gold; }
	int getHealth() const { return m_health; }
	int getDamage() const { return m_damage; }

	// functions
	void reduceHealth(int reduce)
	{
		this->m_health -= reduce;
	}
	bool isDead()
	{
		if (this->m_health <= 0)
		{
			return true;
		}
		return false;
	}
	void addGold(int gold)
	{
		this->m_gold += gold;
	}
};


#endif // !Monsters_H
