/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include "game.hpp"
#include "coinDrop.hpp"

// Default Constructor for the game
CoinDrop::CoinDrop(){};



	int CoinDrop::getCost(){
    return Game::getCost() / 10;
  }
  int CoinDrop::getFreeMachine(){
    return  Game::getFreeMachine() * 2;
  }
  int CoinDrop::getMaintenanceCost(){
	  return Game::getMaintenanceCost() / 2;
  }
  int CoinDrop::getRevenue(){
    return CoinDrop::getCost() / 20;
  }
  void CoinDrop::setAge(int ageIn) {
	  Game::setAge(Game::getAge() + ageIn);
  }

