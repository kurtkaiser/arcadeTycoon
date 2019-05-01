/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#ifndef Pinball_HPP
#define Pinball_HPP
#include "game.hpp"

// Class derived from game class
class Pinball : public Game
{
private:
public:
	// Defining public variables and methods
	Pinball();
	// Used all the required method/function names
	int getCost();
  int getFreeMachine();
  int getMaintenanceCost();
  int getRevenue();
  void setCost(int);
  void setAge(int);
};

#endif