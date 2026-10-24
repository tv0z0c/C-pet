#include "Player.h"

#include <algorithm>
#include <iostream>

Player::Player(std::string name)
	: name(name), health(30), damage(8), firstAidKit(1)
{
}

std::string Player::getName(void)
{
	return name;
}

int Player::getHealth(void)
{
	return health;
}

int Player::getWeaponInfo(void)
{
	return damage;
}

int Player::getFirstAidKit(void)
{
	return firstAidKit;
}

bool Player::useFirstAidKit(int kits)
{
	if (kits <= 0)
	{
		return false;
	}
	else
	{
		const int MAX_HP = 30;
		health = std::min(health + 20, MAX_HP);
		return true;
	}
}

int Player::takingDamage(int damage)
{
	health -= damage;

	if (health <= 0)
	{
		std::cout << "You are dead, game is finished";
		return 0;
	}
	return health;
}