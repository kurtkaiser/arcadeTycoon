/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include "game.hpp"
#include "cabinet.hpp"
#include "pinball.hpp"
#include "coinDrop.hpp"
#include "arcade.hpp"
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	// Declare needed variables
	int choice = 0;
	Menu mainMenu;
	// Output intro to game
	mainMenu.setDirections("  *-*-*-*-*-*-*-*-*- Arcade Tycoon *-*-*-*-*-*-*-*-*-\n");
	mainMenu.setStart(1);
	mainMenu.setOption2("2. Exit\n");
	choice = mainMenu.getUserChoice();
	// Adjust menu for later use
	mainMenu.setOption1("1. Continue Playing\n");
	mainMenu.setDirections("\nEnter 1 or 2.\n");
	mainMenu.setOption3("Continue?  ");
	// Start arcade game
	if (choice == 1) {
		// First day has different order of events
		Arcade arcadePark;
		arcadePark.gameShop();
		arcadePark.firstDay();
		arcadePark.startOfDay();
		arcadePark.randomEvent();
		arcadePark.calculateProfit();
		arcadePark.outputNumbers();
		choice = mainMenu.getUserChoice();
		if (arcadePark.gameOver()) choice = 2;
		// Start regular days in the game
		while (choice == 1) {
			arcadePark.startOfDay();
			arcadePark.randomEvent();
			arcadePark.gameShop();
			arcadePark.calculateProfit();
			arcadePark.outputNumbers();
			choice = mainMenu.getUserChoice();
			if (arcadePark.gameOver()) choice = 2;
		}
		arcadePark.deleteArrays();
	}
}