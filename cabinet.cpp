/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include "game.hpp"
#include "cabinet.hpp"

// Default Constructor
Cabinet::Cabinet() {};

// Methods the game can use to overide virtual functions of the parent class
int Cabinet::getCost() {
	return Game::getCost();
}
int Cabinet::getFreeMachine() {
	return  Game::getFreeMachine();
}
int Cabinet::getMaintenanceCost() {
	return Game::getMaintenanceCost();
}
int Cabinet::getRevenue() {
	return Game::getCost() / Game::getRevenue();
}
void Cabinet::setAge(int ageIn) {
	Game::setAge(Game::getAge() + ageIn);

}

