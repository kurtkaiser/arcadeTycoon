/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>
#include "menu.hpp"
using std::cout;
using std::string;
using std::endl;
using std::cin;

// Constructor for the Menu class
Menu::Menu() {
	// Declaring private member variables and arrays of variables
	directions = "You can purchase 0, 1, or 2 of each game.\n";
	option1 = "1. Play Game <------ EXTRA CREDIT - Maintenance Choices\n";
	option2 = "";
	option3 = "";
	start = 0;
	end = 2;
}

// Defining methods to access and set class variables
std::string Menu::getOption1() {
	return option1;
}
std::string Menu::getOption2() {
	return option2;
}
void Menu::setOption1(std::string option1In) {
	option1 = option1In;
}
void Menu::setOption2(std::string option2In) {
	option2 = option2In;
}

void Menu::setOption3(std::string option3In) {
	option3 = option3In;
}

void Menu::setStart(int startIn) {
	start = startIn;
}

void Menu::setEnd(int endIn) {
	end = endIn;
}
int Menu::getEnd() {
	return end;
}

void Menu::setDirections(string directionsIn) {
	directions = directionsIn;
}

// Prompt user for input, validate input and return it
int Menu::getUserChoice() {
	if (directions != "")
		cout << directions;
	while (true) {
		int choice = 0;
		cout << option1;
		// Check if second and third prompts / option exists, if so output it
		if (option2 != "")
			cout << option2;
		if (option3 != "")
			cout << option3;
		while (true) {

			// if input is an int and in the acceptable range break
			if (cin >> choice) {
				if (choice > (start - 1) && choice < (end + 1)) {
					break;
				}
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter a number from " << start << " to " << end << "." << endl;
		}
		// Return acceptable user input
		return choice;
	}
}
