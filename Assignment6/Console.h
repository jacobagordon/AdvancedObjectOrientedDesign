/********************************************************************
*** NAME : Jacob Gordon
*** CLASS : CSc 346
*** ASSIGNMENT : Assignment #6
*** DUE DATE : April 30 2018
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION :Header file for the Console class. Holds the info
for the different types of consoles and the overall store
********************************************************************/
#pragma once
#include "Game.h"
class Console
{
public:
	/********************************************************************
	*** FUNCTION: Console
	*********************************************************************
	*** DESCRIPTION :Constructor for the console
	*** INPUT ARGS : const int
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	Console(const int = 0);

	/********************************************************************
	*** FUNCTION: ~Console
	*********************************************************************
	*** DESCRIPTION :Destructor for the console
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	~Console();

	/********************************************************************
	*** FUNCTION: processStart
	*********************************************************************
	*** DESCRIPTION :Starts the process of starting the store
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	void processStart();
protected:
	/********************************************************************
	*** FUNCTION: processIntroduction
	*********************************************************************
	*** DESCRIPTION :Displays a intro to the store
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processIntroduction() = 0;

	/********************************************************************
	*** FUNCTION: processSelection
	*********************************************************************
	*** DESCRIPTION :Processes a selection of a game
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	void processSelection();

	/********************************************************************
	*** FUNCTION: processPayment
	*********************************************************************
	*** DESCRIPTION :Processes a payment of a game
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processPayment();

	/********************************************************************
	*** FUNCTION: processChange
	*********************************************************************
	*** DESCRIPTION :Processes the change of a game
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processChange();

	/********************************************************************
	*** FUNCTION: processDelivery
	*********************************************************************
	*** DESCRIPTION :Processes the delivery of a game
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	void processDelivery() const;

	const int GAME_OPTIONS;
	Game * games;
	int selectedGame;
	int amountPaid;
};

