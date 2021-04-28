#include "Game.h"
#include <string>
#include <iostream>
#include <iomanip>
/********************************************************************
*** FUNCTION: Game
*********************************************************************
*** DESCRIPTION :Constructor for a game
*** INPUT ARGS : const char *, const int, const int
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Game::Game(const char * name, const int price, const int quantity)	//name, price, quantity)
{
	setTitle(name);
	setCost(price);
	setQuantity(quantity);
}

/********************************************************************
*** FUNCTION: ~Game
*********************************************************************
*** DESCRIPTION :Destructor for a game
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Game::~Game()
{
	std::cout << "Destructor called!" << std::endl;
}

/********************************************************************
*** FUNCTION: Game
*********************************************************************
*** DESCRIPTION :Copy constructor for a game
*** INPUT ARGS : const Game &
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Game::Game(const Game & oldGame)
{
	*this = oldGame;
}

/********************************************************************
*** FUNCTION: operator=
*********************************************************************
*** DESCRIPTION :Overloaded = operator
*** INPUT ARGS : const Game & right
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : Game &
********************************************************************/
Game & Game::operator=(const Game & right)
{
	title = right.title;
	cost = right.cost;
	quantity = right.quantity;
	return (*this);
}

/********************************************************************
*** FUNCTION: operator<<
*********************************************************************
*** DESCRIPTION :Overloaded << operator
*** INPUT ARGS : ostream & sout, const Game & right
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : ostream &
********************************************************************/
std::ostream & operator<<(std::ostream & sout, const Game & right)
{
	sout << "Game: " << std::setw(30) << std::left << right.getTitle() << std::setw(15) << std::right << "Price: $" << right.getCost() << std::setw(15) << "Quantity: " << right.getQuantity() << std::endl;
	return sout;
}