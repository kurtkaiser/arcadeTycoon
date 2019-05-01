/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include "game.hpp"
#include "pinball.hpp"

// Default Constructor for the game
Pinball::Pinball(){};

// Methods the game can use to overide virtual functions of the parent class
	int Pinball::getCost(){
		return Game::getCost() * 10;
  }
  int Pinball::getFreeMachine(){
    return  Game::getFreeMachine() / 5;
  }
  int Pinball::getMaintenanceCost(){
	  return Game::getMaintenanceCost() * 5;
  }
  int Pinball::getRevenue(){
   return Pinball::getCost() / 5;
  }

  void Pinball::setCost(int costIn) {
	  Game::setCost(costIn);
  }

  void Pinball::setAge(int ageIn) {
	  Game::setAge(Game::getAge() + ageIn);
  }