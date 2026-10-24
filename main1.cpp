#include <iostream>
#include <random>
#include <string>

#include "Player.h"
#include "Battle.h"

bool missionCaptureWarhouse(int currentHP, int weaponInfo, int valuesFirstAidKits, std::string name);

int randomGenerationEnemiesOneOrTwo();

int main()
{
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;

	Player Player(name);

	while (true)
	{
		std::cout << "\nYour name: " << Player.getName() << "\n";
		std::cout << "You are standing in the main hall of your base—what should you do next?\n"
			"1. Check your equipment and HP\n"
			"2. Go on a mission\n"
			"3. Exit\n"
			"\nEnter your choise: ";

		int playerChoise;
		std::cin >> playerChoise;

		switch (playerChoise)
		{
		case(1):
			std::cout << "You examine yourself and your weapon\n";
			std::cout << "Current HP: " << Player.getHealth() << "\n";
			std::cout << "Current weapon AKM, damage: " << Player.getWeaponInfo() << "\n";
			std::cout << "First aid kit: " << Player.getFirstAidKit() << "\n";
			std::cout << "Back, enter 0\n";
			std::cin >> playerChoise;
			if (playerChoise == 0)
			{
				break;
			}
			else
			{
				std::cout << "Incorrect input, please retry input\n";
				break;
			}

		case(2):
			std::cout << "You approach the terminal and review the list of available missions\n"
				"Mission 1: Сapture and hold the warehouse\n"
				"Mission 2: In development\n"
				"Mission 3: In development\n"
				"Back, enter 0\n"
				"Enter your choise: ";
			std::cin >> playerChoise;

			if (playerChoise == 1)
			{
				std::cout << "You must capture and hold the warehouse until friendly forces arrive\n"
					"Possible enemies ? 1-2\n"
					"Enter 1 - accept mission\n"
					"Enter 2 - back in main menu\n"
					"Enter your choise: ";
				std::cin >> playerChoise;
				
				if (playerChoise == 1)
				{
					if (missionCaptureWarhouse(Player.getHealth(), Player.getWeaponInfo(), Player.getFirstAidKit(), name))
					{
						std::cout << "Back to main menu, enter 0: ";
						std::cin >> playerChoise;
						if (playerChoise == 0)
						{
							break;
						}
						else
						{
							std::cout << "Incorrect input, retry";
							break;
						}
					}
				}
				else if (playerChoise == 2)
				{
					break;
				}
				else
				{
					std::cout << "Incorrect input, please retry input\n";
					break;
				}
			}
			else if (playerChoise == 2 || playerChoise == 3)
			{
				std::cout << "Mission still in development\n";
				break;
			}
			else if (playerChoise == 0)
			{
				break;
			}
			else
			{
				std::cout << "Incorrect input, please retry input\n";
				break;
			}

		case(3):
			std::cout << "Goodbye\n";
			return 0;

		default:
			std::cout << "Incorrect input, please retry input\n";
		}
	}
}

bool missionCaptureWarhouse(int currentHP, int weaponInfo, int valuesFirstAidKits, std::string name)
{
	std::cout << "\nYou arrive at the warehouse where weapons are stored.\n";
	std::cout << "Your current HP: " << currentHP << "\n";
	std::cout << "Your current weapon damage: " << weaponInfo << "\n";
	std::cout << "Values yours first aid kits: " << valuesFirstAidKits << "\n";

	int enemies = randomGenerationEnemiesOneOrTwo();
	std::cout << "You go into the warehouse and see " << enemies << " battle drones\n";

	//йобаное бля
	int step = 1;
	Battle Battle(enemies, step);
	Player Player(name);

	int enemiesHP = 0;

	while (true)
	{
		std::cout << "\n===CURRENT STEP: " << step << "===" << "\n";
		std::cout << "You go first\n"
			"1 - Attack\n"
			"2 - Use first aid kit\n"
			"3 - Enter your choise: ";

		int playerChoise;
		std::cin >> playerChoise;

		switch (playerChoise)
		{
		case(1):
			std::cout << "You attack the battle drone";
			enemiesHP = Battle.takingDamage(Player.getWeaponInfo());
			if (enemiesHP > 0)
			{
				std::cout << "the remaining health of the enemies: " << enemiesHP << "\n";
				std::cout << "The attack phase is over; the transition to the enemy’s attack.";
				break;
			}
			else
			{
				break;
			}

		case(2):
			if (Player.useFirstAidKit(Player.getFirstAidKit()))
			{
				std::cout << "You have been cured\n"
					"Current Health: " << Player.getHealth() << "\n";
				break;
			}
			else
			{
				std::cout << "There aren’t enough first‑aid kits\n";
				break;
			}
		}

		if (enemiesHP > 0)
		{
			std::cout << "Combat drones attacked you, the damage inflicted: " << Battle.getDamage() << "\n";
			Player.takingDamage(Battle.getDamage());
			std::cout << "Your current health: " << Player.getHealth() << "\n";
			step++;
		}
		else
		{
			break;
		}
	}

	if (enemiesHP == 0)
	{
		std::cout << "\nAll enemies is destroyed!\n";
		std::cout << "Congratulation!You won" << "\n";
		return true;
	}
	else
	{
		std::cout << "You are dead" << "\n";
		return false;
	}
}

int randomGenerationEnemiesOneOrTwo()
{
	static std::random_device enemies;
	static std::mt19937 gen(enemies());
	std::uniform_int_distribution<int> dist(1, 2);

	return dist(gen);
}