#pragma once

class Battle
{
private:
	int enemies;
	int step;
	int HP;
	int damage;

public:
	explicit Battle(int enemies, int step);

	int takingDamage(int amountOfDamage);

	int getStep(void);

	int getHP(void);
	
	int getDamage(void);
};