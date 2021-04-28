#pragma once
#include <iostream>
#include <string>

class Game
{
	/********************************************************************
	*** FUNCTION: operator <<
	*********************************************************************
	*** DESCRIPTION :Overloaded << operator
	*** INPUT ARGS : ostream &, const Game &
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : ostream &
	********************************************************************/
	friend std::ostream & operator<<(std::ostream &, const Game &);

public:
	/********************************************************************
	*** FUNCTION: Game
	*********************************************************************
	*** DESCRIPTION :Constructor for a game
	*** INPUT ARGS : const char *, const int, const int
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	Game(const char * = "", const int = 0, const int = 0);	//name, price, quantity

	/********************************************************************
	*** FUNCTION: ~Game
	*********************************************************************
	*** DESCRIPTION :Destructor for a game
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	~Game();

	/********************************************************************
	*** FUNCTION: Game
	*********************************************************************
	*** DESCRIPTION :Copy constructor for a game
	*** INPUT ARGS : const Game &
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	Game(const Game &);

	/********************************************************************
	*** FUNCTION: operator=
	*********************************************************************
	*** DESCRIPTION :Overloaded = operator
	*** INPUT ARGS : const Game & right
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : Game &
	********************************************************************/
	Game & operator=(const Game &);

	/********************************************************************
	*** FUNCTION: getter functions
	*********************************************************************
	*** DESCRIPTION :Getter functions for Game class attributes
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : string/int/int
	********************************************************************/
	inline std::string getTitle() const;
	inline int getCost() const;
	inline int getQuantity() const;

	/********************************************************************
	*** FUNCTION: setter functions
	*********************************************************************
	*** DESCRIPTION :Setter functions for Game class attributes
	*** INPUT ARGS : const char * / const int / const int
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	inline void setTitle(const char * = "");
	inline void setCost(const int = 0);
	inline void setQuantity(const int = 0);
private:
	std::string title;
	int cost;
	int quantity;
};

/********************************************************************
*** FUNCTION: getter functions
*********************************************************************
*** DESCRIPTION :Getter functions for Game class attributes
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : string/int/int
********************************************************************/
std::string Game::getTitle() const
{
	return title;
}

int Game::getCost() const
{
	return cost;
}

int Game::getQuantity() const
{
	return quantity;
}

/********************************************************************
*** FUNCTION: setter functions
*********************************************************************
*** DESCRIPTION :Setter functions for Game class attributes
*** INPUT ARGS : const char * / const int / const int
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Game::setTitle(const char * newTitle)
{
	title = newTitle;
}

void Game::setCost(const int value)
{
	cost = value;
}

void Game::setQuantity(const int newQuantity)
{
	quantity = newQuantity;
}