/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/

#ifndef CoinDrop_HPP
#define CoinDrop_HPP
#include "game.hpp"

// Class derived from game class
class CoinDrop : public Game
{
	private:
	public:
	// Default Constructor for the game
	CoinDrop();
	// Methods the game can use to overide virtual functions of the parent class
	int getCost();
	int getFreeMachine();
	int getMaintenanceCost();
	int getRevenue();
	void setAge(int);
};

#endif