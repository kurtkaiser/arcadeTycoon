/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
using std::string;

class Menu
{
private:
	// Declaring private member variables
	string directions;
	string option1;
	string option2;
	string option3;
	int start;
	int end;

public:
	// Declaring constructor for the class
	Menu();
	int getUserChoice();
	std::string getOption1();
	std::string getOption2();
	void setOption1(string);
	void setOption2(string); 
	void setOption3(string);
	void setStart(int);
	void setEnd(int);
	int getEnd();
	void setDirections(string);
};
#endif
