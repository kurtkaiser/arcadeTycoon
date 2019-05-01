/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#ifndef Arcade_HPP
#define Arcade_HPP
#include "game.hpp"
#include "cabinet.hpp"
#include "coinDrop.hpp"
#include "pinball.hpp"
#include "menu.hpp"
#include <string>
using std::string;

// Defines the interface of the Arcade class
class Arcade
{
private:
	// Defining private variables
	int money;
	int day;
	int bonus;
	Menu buyMenu;
	Menu maintenanceMenu;
	int pinballCount;
	int pinballMax;
	int cabinetCount;
	int cabinetMax;
	int coinDropCount;
	int coinDropMax;
	int maintenanceType;
	string dailyNews;
	Pinball* pinballObjects;
	Game** pinballs;
	Cabinet* cabinetObjects;
	Game** cabinets;
	Game** coinDrops;
	CoinDrop* coinDropObjects;
public:
	// Default Constructor
	Arcade();
	// Defining public variables and methods
	void firstDay();
	void gameShop();
	void buyPinballs(int);
	void buyCabinets(int);
	void buyCoinDrops(int);
	Game** increaseArraySize(Game**, int, int);
	int getRandomNumber(int);
	void randomEvent();
	bool getAge(Game**, int);
	void startOfDay();
	void calculateProfit();
	void changeAge(Game**, int, int, int);
	bool gameOver();
	void outputNumbers();
	void deleteArrays();
};
#endif