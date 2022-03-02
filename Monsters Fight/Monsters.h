#ifndef Monsters_H
#define Monsters_H

class Monster : public Creature
{
public:
	enum class Type
	{
		dragon,
		orc,
		slime,
		max_type
	};

private:
	static const Creature& getDefaultCreature(Type type)
	{
		static const std::array<Creature, static_cast<std::size_t>(Type::max_type)> monsterData
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

	static Monster getRandomMonster()
	{
		int number = getRandomNumber(0, static_cast<int>(Type::max_type) - 1);

		return Monster{ static_cast<Type>(number) };
	}
};

#endif // !Monsters_H
