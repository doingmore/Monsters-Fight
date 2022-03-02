#ifndef Player_H
#define Player_H

class Player : public Creature
{
protected:
	int m_level{ 1 };
public:
	Player(const std::string& name) : Creature{ name , '@' , 10 , 1 , 0 }
	{
	}

	int getLevel() { return m_level; }
	void levelUp() { m_level++; m_damage++; m_health = 10; }
	bool hasWon()
	{
		if (m_level > 20)
		{
			return true;
		}
		return false;
	}
};


#endif // !Player_H
