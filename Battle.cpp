#include "Battle.h"

#include <algorithm>

Battle::Battle(int enemies, int step)
	: enemies(enemies), step(step), HP(30), damage(6)
{
	if (enemies > 1)
	{
		HP = 30;
		damage = 6;
	}
	else if (enemies == 1)
	{
		HP = 15;
		damage = 3;
	}
}

int Battle::getStep(void)
{
	return step;
}

int Battle::getHP(void)
{
	return HP;
}

int Battle::getDamage(void)
{
	return damage;
}

int Battle::takingDamage(int amountOfDamage)
{
	const int MIN_HP = 0;
	//HP -= amountOfDamage;
	HP = std::max(HP - amountOfDamage, MIN_HP);
	return HP;
}