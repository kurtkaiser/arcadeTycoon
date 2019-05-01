/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#ifndef GAME_HPP
# define GAME_HPP

// Defines the interface of the Game class
class Game {

private:
	// Defining private variables
	int age;
	int cost;
	int freeMachine;
	int maintenanceCost;
	int revenue;

public:
	// Defining public variables and methods
	Game();
	Game(int, int, int, int, int);
	// Used all the required method/function names

	// Setters
	virtual void setAge(int);
	void setCost(int);
	void setFreeMachine(int);
	void setMaintenanceCost(int);
	void setRevenue(int);
	// Getters
	virtual int getAge();
	virtual int getCost();
	virtual int getFreeMachine();
	virtual int getMaintenanceCost();
	virtual int getRevenue();

};

#endif
