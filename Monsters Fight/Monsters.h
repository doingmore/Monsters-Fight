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
	Creature(const std::string& name,const  char& symbol, int health, int damage, int gold)
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

class Monster : public Creature
{
public:
	enum class Type
	{
		dragon,
		orc,
		slime,
		max_types
	};

private:
	static const Creature& getDefaultCreature(Type type)
	{
		static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData
		{
		  { { "dragon", 'D', 20, 4, 100 },
			{ "orc", 'o', 4, 2, 25 },
			{ "slime", 's', 1, 1, 10 } }
		};

		return monsterData.at(static_cast<std::size_t>(type));
	}

public:
	Monster(Type type)
		: Creature{ getDefaultCreature(type) }
	{
	}
};


#endif // !Monsters_H
