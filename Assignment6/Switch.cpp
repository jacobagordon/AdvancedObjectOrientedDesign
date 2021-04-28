#include "Switch.h"
#include <iostream>

/********************************************************************
*** FUNCTION: Switch
*********************************************************************
*** DESCRIPTION :Constructor for the switch
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Switch::Switch() : Console(3)
{
	Game LegendOfZelda("Legend of Zelda", 46, 3);
	Game Skyrim("Skyrim", 50, 5);
	Game SuperMarioOdyssey("Super Mario Odyssey", 57, 1);
	games[0] = LegendOfZelda;
	games[1] = Skyrim;
	games[2] = SuperMarioOdyssey;
}

/********************************************************************
*** FUNCTION: ~Switch
*********************************************************************
*** DESCRIPTION :Destructor for the switch
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Switch::~Switch()
{
}

/********************************************************************
*** FUNCTION: processIntroduction
*********************************************************************
*** DESCRIPTION :Introduction to the Switch store
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Switch::processIntroduction()
{
	system("cls");
	std::cout << "Welcome to the Nintendo Switch Store!" << std::endl;
	std::cout << "Select a game to purchase!" << std::endl << std::endl;
}

/********************************************************************
*** FUNCTION: processChange
*********************************************************************
*** DESCRIPTION :Processes the change for a given game in the store
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Switch::processChange()
{
	int numFive = 0;
	int numTwo = 0;
	int numOne = 0;
	int change = 0;
	if (amountPaid >= games[selectedGame].getCost())
	{
		change = amountPaid - games[selectedGame].getCost();
		std::cout << std::endl << "Change to be dispensed: $" << change << std::endl;
	}
	else
	{
		change = amountPaid;
		amountPaid = 0;
		std::cout << "Returning money..." << std::endl;
	}
	while (change > 0)
	{
		if (change >= 5)
		{
			std::cout << "$5 ";
			numFive++;
			change = change - 5;
		}
		else if (change > 1 && change < 5)
		{
			std::cout << "$2 ";
			numTwo++;
			change = change - 2;
		}
		else
		{
			std::cout << "$1 ";
			numOne++;
			change = change - 1;
		}
	}
	std::cout << std::endl << "Change given: (" << numFive << ") $5, (" << numTwo << ") $2, (" << numOne << ") $1" << std::endl;
}