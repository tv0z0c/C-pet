#pragma once

#include <string>

class Player
{
private:
	std::string name;
	int health;
	int damage;
	int firstAidKit;

public:
	explicit Player(std::string name);
	
	std::string getName(void);

	int getHealth(void);

	int getWeaponInfo(void);

	int getFirstAidKit(void);

	bool useFirstAidKit(int kits);

	int takingDamage(int damage);
};