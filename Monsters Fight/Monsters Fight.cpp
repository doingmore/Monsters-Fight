#include <iostream>
#include <string>
#include <string_view>

#include "Monsters.h"


/*
The goal of the game is to collect as much gold as you can before you die
or get to level 20.
*/


int main()
{
    Monster m{ Monster::Type::orc };
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    return 0;
}
