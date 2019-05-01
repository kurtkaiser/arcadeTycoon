/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include <string> 
#include <ctime>
#include <cstdlib>
#include <stdlib.h> 
#include "arcade.hpp"
#include "game.hpp"
#include "pinball.hpp"
#include "menu.hpp"
#include <array>
#include <string>
using std::string;
using std::cout;
using std::endl;

// Default constructor 
Arcade::Arcade() {
	money = 100000;
	day = 1;
	bonus = 0;
	maintenanceType = 2;
	Menu buyMenu;
	pinballCount = 0;
	pinballMax = 10;
	pinballs = new Game*[pinballMax];
	cabinetCount = 0;
	cabinetMax = 10;
	cabinets = new Game*[cabinetMax];
	coinDropCount = 0;
	coinDropMax = 10;
	coinDrops = new Game*[coinDropMax];
}

// Used to start, first day buying takes place first
void Arcade::firstDay() {
	srand(time(NULL));
	changeAge(pinballs, 0, pinballCount, -2);
	changeAge(cabinets, 0, cabinetCount, -2);
	changeAge(coinDrops, 0, coinDropCount, -2);
	buyMenu.setEnd(1);
	maintenanceMenu.setDirections(" ------ Daily Maintenance Options ------  \n");
	maintenanceMenu.setOption1("1. Untrained Staff - Half price, machines are more likely to breakdown.\n");
	maintenanceMenu.setOption2("2. Certified Technician - Breakdowns occur at an average rate.\n");
	maintenanceMenu.setOption3("3. Electrical Engineer - Twice the price, machine breakdowns are rare.\n");
	maintenanceMenu.setStart(1);
	maintenanceMenu.setEnd(3);
}

// Used on all days to allow purchase of new games
void Arcade::gameShop() {
	int amount = 1;
	cout << " -------- Arcade Warehouse Shop --------\n";
	buyMenu.setOption1("Pinball Machines: ");
	amount = buyMenu.getUserChoice();
	buyMenu.setDirections("");
	if (amount > 0) buyPinballs(amount);
	buyMenu.setOption1("Arcade Cabinets: ");
	amount = buyMenu.getUserChoice();
	if (amount > 0) buyCabinets(amount);
	buyMenu.setOption1("Coin Drops Machines: ");
	amount = buyMenu.getUserChoice();
	if (amount > 0) buyCoinDrops(amount);
	buyMenu.setDirections("You can purchase 0 or 1 of each game.\n");
}

// Adds particular game if user purchased it, expands games array if needed by calling the increaseArraySize function
void Arcade::buyPinballs(int amount) {
	int count = 0;
	if (pinballCount + amount > pinballMax) {
		pinballMax = pinballMax + 10;
		pinballs = increaseArraySize(pinballs, pinballMax, pinballCount);
	}
	while (count < amount) {
		Game *tempPinball = new Pinball;
		pinballs[pinballCount + count] = tempPinball;
		count++;
	}
	pinballCount = pinballCount + amount;
	money = money - pinballs[0]->getCost() * amount;
}

// Adds particular game if user purchased it, expands games array if needed by calling the increaseArraySize function
void Arcade::buyCabinets(int amount) {
	int count = 0;
	if (cabinetCount + amount > cabinetMax) {
		cabinetMax = cabinetMax + 10;
		cabinets = increaseArraySize(cabinets, cabinetMax, cabinetCount);
	}
	while (count < amount) {
		Game *tempCabinet = new Cabinet;
		cabinets[cabinetCount + count] = tempCabinet;
		count++;
	}
	cabinetCount = cabinetCount + amount;
	money = money - cabinets[0]->getCost() * amount;
}

// Adds particular game if user purchased it, expands games array if needed by calling the increaseArraySize function
void Arcade::buyCoinDrops(int amount) {
	int count = 0;
	if (coinDropCount + amount > coinDropMax) {
		coinDropMax = coinDropMax + 10;
		coinDrops = increaseArraySize(coinDrops, coinDropMax, coinDropCount);
	}
	while (count < amount) {
		Game *tempCoinDrop = new CoinDrop;
		coinDrops[coinDropCount + count] = tempCoinDrop;
		count++;
	}
	coinDropCount = coinDropCount + amount;
	money = money - coinDrops[0]->getCost() * amount;
}

// Copies an game array, increases capacity of that array by ten and returns it
Game** Arcade::increaseArraySize(Game** gameArray, int max, int count) {
	Game** tempGames = new Game*[max];
	for (int i = 0; i < count; i++) {
		tempGames[i] = gameArray[i];
	}
	return tempGames;
}

// Gives the game variety by creating a random daily eventType
void Arcade::randomEvent() {
	int dailyEvent = 0;
	int eventType;
	if (maintenanceType == 2) {
		dailyEvent = getRandomNumber(3);
	}
	else {
		if (maintenanceType == 1 && getRandomNumber(2) == 1) {
				dailyEvent = 1;
		}
		else if (maintenanceType == 3 && getRandomNumber(8) == 1) {
				dailyEvent = 1;
		}
		else {
			dailyEvent = getRandomNumber(2);
			dailyEvent++;
		}
	}
	dailyNews = "Not much happened at the arcade today.";
	switch (dailyEvent)
	{
	case 1:
		eventType = getRandomNumber(3);
		if (eventType == 1) {
			if (pinballCount > 0) {
				pinballs[--pinballCount] = new Game;
				dailyNews = "A pinball machine died today.";
			}
		}
		else if (eventType == 2) {
			if (cabinetCount > 0) {
				cabinets[--cabinetCount] = new Game;
				dailyNews = "An arcade cabinet machine died today.";
			}
		}
		else if (eventType == 3) {
			if (coinDropCount > 0) {
				coinDrops[--coinDropCount] = new Game;
				dailyNews = "A coin drop machine died today.";
			}
		}
		break;
	case 2:
		// Boom in attendence
		eventType = getRandomNumber(500);
		bonus = (eventType + 500) * pinballCount;
		dailyNews = "Attendance has boomed. Get ready for a $";
		dailyNews = dailyNews + std::to_string((eventType + 500)) + " bonus!";
		break;
	case 3:
		// Bonus Machine
		eventType = getRandomNumber(3);
		if (eventType == 1) {
			if (getAge(pinballs, pinballCount)) {
				buyPinballs(pinballs[0]->getFreeMachine());
				changeAge(pinballs, pinballCount - pinballs[0]->getFreeMachine(), pinballCount, -3);
				dailyNews = "A wealthly collector gave you a pinball machine for free!";
			}

		}
		else if (eventType == 2) {
			if (getAge(cabinets, cabinetCount)) {
				buyCabinets(cabinets[0]->getFreeMachine());
				changeAge(cabinets, cabinetCount - cabinets[0]->getFreeMachine(), cabinetCount, -3);
				dailyNews = "A collector gave you an arcade cabinet machine for free!";
			}

		}
		else if (eventType == 3) {
			if (getAge(coinDrops, coinDropCount)) {
				buyCoinDrops(coinDrops[0]->getFreeMachine());
				changeAge(coinDrops, coinDropCount - coinDrops[0]->getFreeMachine(), coinDropCount, -3);
				dailyNews = "A friend gave you a coin drop machine for free!";
			}
		}
		break;
		// If eventType == 4, no random eventType that day
	}
}

// Checks games' ages to see if enough experience to win one
bool Arcade::getAge(Game** parents, int count) {
	bool oldEnough = false;
	for (int i = 0; i < count; i++) {
		if (parents[i]->getAge() > 2) {
			oldEnough = true;
			break;
		}
	}
	return oldEnough;
}

// Returns a random number
int Arcade::getRandomNumber(int high) {
	int maximum = RAND_MAX / high * high;
	int randomNum = rand();
	while (maximum <= randomNum) {
		randomNum = rand();
	}
	randomNum = randomNum % high + 1;
	return randomNum;
}

// Run at the beginning of each day, subtracts food cost and ages games
void Arcade::startOfDay() {
	// Increase by one day
	day++;
	int dailyMaintenanceCost = 0;
	// User selects the maintenance for the day
	maintenanceType = maintenanceMenu.getUserChoice();
	// Increase Age Subtract Food Cost
	if (pinballCount > 0) {
		changeAge(pinballs, 0, pinballCount, 1);
		dailyMaintenanceCost = pinballs[0]->getMaintenanceCost() * pinballCount;
	}
	if (cabinetCount > 0) {
		changeAge(cabinets, 0, cabinetCount, 1);
		dailyMaintenanceCost = dailyMaintenanceCost + cabinets[0]->getMaintenanceCost() * cabinetCount;
	}
	if (coinDropCount > 0) {
		changeAge(coinDrops, 0, coinDropCount, 1);
		dailyMaintenanceCost = dailyMaintenanceCost + coinDrops[0]->getMaintenanceCost() * coinDropCount;
	}
	if (maintenanceType == 1) dailyMaintenanceCost = dailyMaintenanceCost / 2;
	if (maintenanceType == 3) dailyMaintenanceCost = dailyMaintenanceCost * 2;
	money = money - dailyMaintenanceCost;
}

// Run to calculate amount of money made each day
void Arcade::calculateProfit() {
	// Add Revenue
	if (pinballCount > 0)
		money = money + pinballs[0]->getRevenue() * pinballCount;
	if (cabinetCount > 0)
		money = money + cabinets[0]->getRevenue() * cabinetCount;
	if (coinDropCount > 0)
		money = money + coinDrops[0]->getRevenue() * coinDropCount;
	// Add possible bonus
	money = money + bonus;
	bonus = 0;
}

// used to adjust games age
void Arcade::changeAge(Game** games, int start, int end, int age) {
	for (int i = start; i < end; i++) {
		games[i]->setAge(age);
	}
}

// Update users on various metrics
void Arcade::outputNumbers() {
	cout << "\n----- Day " << day << " -----\n";
	cout << "News: " << dailyNews << endl;
	cout << "Money: " << money << endl;
	cout << "Pinball Count: " << pinballCount << endl;
	cout << "Cabinet Count: " << cabinetCount << endl;
	cout << "CoinDrop Count: " << coinDropCount << endl;
}

// Notify user they are out of money
bool Arcade::gameOver() {
	bool over = false;
	if (money < 1) {
		over = true;
		cout << " Sorry, you are out of money. \n";
		cout << " -*-*--*--*-*-*- Game Over -*-*-*-*-*-*-*-\n";
		cout << "Total days played: " << day << endl;
	}
	return over;
}

// Delete arrays to prevent memory leaks
void Arcade::deleteArrays() {
	for (int i = 0; i < pinballCount; ++i)
		delete[] pinballs[i];
	delete[] pinballs;
	for (int i = 0; i < pinballCount; ++i)
		delete[] cabinets[i];
	delete[] cabinets;
	for (int i = 0; i < pinballCount; ++i)
		delete[] coinDrops[i];
	delete[] coinDrops;
}