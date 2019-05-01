/*******************************************************************************
** Author: Kurt Kaiser
** Title: Arcade Tycoon
** Description: A text-based game where the player is the proud owner of
** a virtual arcade that has pinball, cabinet and coin drop machines.
*******************************************************************************/
#include <iostream>
#include "game.hpp"

// default constructor
Game::Game()
{
  age = 3;
  cost = 1000;
  freeMachine = 5;
  maintenanceCost = 10;
  revenue = 10;
}

Game::Game(int ageIn, int costIn, int freeMachineIn, int maintenanceCostIn, int revenueIn)
{
	age = ageIn;
	cost = costIn;
	freeMachine = freeMachineIn;
	maintenanceCost = maintenanceCostIn;
	revenue = revenueIn;
}
  // Setters
	void Game::setAge(int ageIn){
    age = ageIn;
  }
	void Game::setCost(int costIn){
    cost = costIn;
  }
  void Game::setFreeMachine(int freeMachineIn){
    freeMachine = freeMachineIn;
  }
  void Game::setMaintenanceCost(int maintenanceCostIn){
   maintenanceCost = maintenanceCostIn;
  }
  void Game::setRevenue(int revenueIn){
    revenue = revenueIn;
  }
  // Getters
	int Game::getAge(){
    return age;

  }
	int Game::getCost(){
    return cost;
  }
  int Game::getFreeMachine(){
    return freeMachine;
  }
  int Game::getMaintenanceCost(){
    return maintenanceCost;
  }
  int Game::getRevenue(){
    return revenue;
  }

