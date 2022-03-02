#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time 
#include <random> 

#include "RandomNumber.h"
#include "Creatures.h"
#include "Player.h"
#include "Monsters.h"


void fight(Player& character, Monster& m)
{
	int gold{ 0 };
	int turn{ 1 };
	while (!character.isDead() && !m.isDead())
	{
		if (turn % 2 == 0)
		{
			character.reduceHealth(m.getDamage());
			std::cout << "The " << m.getName() << " hit you with " << m.getDamage()
				<< " damage." << "\n";
			if (character.isDead())
			{
				std::cout << character.getName() << " you been killed " << " you lose the game." << '\n';
			}
		}
		else
		{
			m.reduceHealth(character.getDamage());
			std::cout << character.getName() << " hit the " << m.getName() << " with " << character.getDamage()
				<< " damage." << "\n";
			if (m.isDead())
			{
				std::cout << "You killed the " << m.getName() << '\n';
				character.levelUp();
				gold = 2 * getRandomNumber(1, character.getLevel());
				character.addGold(gold);
				std::cout << "Now you get up on next level " << character.getLevel() << "." << " Found "
					<< gold << " gold and recover full health." << '\n';
			}
		}
		turn++;
	}
}


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	std::string name;
	std::cout << "Wellcome!" << " " << "Enter name on your character" << '\n';
	std::cin >> name;

	Player character{ name };

	char chose;
	while (!character.isDead())
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << character.getName() << ", you have encountered with " << m.getName() << '\n'
			<< " (R)un or (F)ight: " << '\n';
		std::cin >> chose;
		if (chose == 'f' || chose == 'F')
		{
			fight(character, m);
		}
		else if (chose == 'r' || chose == 'R')
		{
			while (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You failed to flee." << '\n';
				std::cout << "The " << m.getName() << " hit you with " << m.getDamage() << " damage." << '\n';
				character.reduceHealth(m.getDamage());
				if (character.isDead())
				{
					std::cout << name << " you been killed " << " you lose the game." << '\n';
					break;
				}
			}
			if (!character.isDead())
			{
				std::cout << "You escaped successful." << '\n';
			}
		}
		if (character.getLevel() > 20)
		{
			std::cout << "Congratulates you win the game and achieve the goal." << '\n'
				<< "You have " << character.getGold() << " gold." << '\n';
			break;
		}
	}
	return 0;
}
