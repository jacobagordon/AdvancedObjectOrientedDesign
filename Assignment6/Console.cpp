/********************************************************************
*** NAME : Jacob Gordon
*** CLASS : CSc 346
*** ASSIGNMENT : Assignment #6
*** DUE DATE : April 30 2018
*** INSTRUCTOR : GAMRADT
*********************************************************************
*** DESCRIPTION :Implementation file for the Console class. Holds the
info for the different types of consoles and the overall store
********************************************************************/
#include "Console.h"
#include <iostream>

/********************************************************************
*** FUNCTION: Console
*********************************************************************
*** DESCRIPTION :Constructor for the console
*** INPUT ARGS : const int
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Console::Console(const int amount) : GAME_OPTIONS(amount)
{
	games = new(std::nothrow) Game[GAME_OPTIONS];
}

/********************************************************************
*** FUNCTION: ~Console
*********************************************************************
*** DESCRIPTION :Destructor for the console
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
Console::~Console()
{

}

/********************************************************************
*** FUNCTION: processStart
*********************************************************************
*** DESCRIPTION :Starts the process of starting the store
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Console::processStart()
{
	while (selectedGame != -2)
	{
		processIntroduction();
		processSelection();
		if (selectedGame == -2)
		{
			selectedGame = -1;
			return;
		}
		if (selectedGame != -1)
		{
			processPayment();
			processChange();
			processDelivery();
		}
	}
}

/********************************************************************
*** FUNCTION: processIntroduction
*********************************************************************
*** DESCRIPTION :Displays a intro to the store
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Console::processIntroduction()
{
	std::cout << "This should never be used" << std::endl;
}

/********************************************************************
*** FUNCTION: processSelection
*********************************************************************
*** DESCRIPTION :Processes a selection of a game
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Console::processSelection()
{
	int gameChoice = 0;
	int gameQuantity = 0;

	for (int i = 0; i < GAME_OPTIONS; i++)
	{
		std::cout << i + 1 << ". " << games[i];
	}
	std::cout << GAME_OPTIONS + 1 << ". " << "Return to the Main Menu." << std::endl;
	std::cout << "Please select the number of the game you would like to buy: ";
	std::cin >> gameChoice;
	if (gameChoice == GAME_OPTIONS+1)
	{
		selectedGame = -2;
		return;
	}
	while (gameChoice < 1 || gameChoice > GAME_OPTIONS)
	{
		std::cout << "Invalid Input: Try again: ";
		std::cin >> gameChoice;
	}

	selectedGame = gameChoice-1;
	if (games[selectedGame].getQuantity() == 0)
	{
		std::cout << "I'm sorry, that game is currently out of stock." << std::endl;
		selectedGame = -1;
		system("pause");
	}
	else
	{
		gameQuantity = games[selectedGame].getQuantity();
		games[selectedGame].setQuantity(gameQuantity - 1);
	}
}

/********************************************************************
*** FUNCTION: processPayment
*********************************************************************
*** DESCRIPTION :Processes a payment of a game
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Console::processPayment()
{
	int counter;
	int numTwenty = 0;
	int numTen = 0;
	int current = 0;
	int left = 0;

	std::cout << "You have selected " << games[selectedGame].getTitle() << std::endl;
	left = games[selectedGame].getCost();
	std::cout << "Total due: $" << games[selectedGame].getCost() << std::endl;
	std::cout << "Bills accepted: $20, $10" << std::endl;
	std::cout << "Please enter the number of $20 bills: ";
	std::cin >> numTwenty;
	current = current + (20 * numTwenty);
	left = left - (20 * numTwenty);
	if (left < 0)
		std::cout << "Total due: $0" << std::endl;
	else
		std::cout << "Total due: $" << left << std::endl;
	std::cout << "Please enter the number of $10 bills: ";
	std::cin >> numTen;
	current = current + (10 * numTen);
	left = left - (10 * numTen);
	if (left <= 0)
		std::cout << "Total due: $0" << std::endl;
	else
	{
		std::cout << std::endl << "I'm sorry, that was not enough money. \nTotal due: $" << left << std::endl;
		system("pause");
	}
	amountPaid = current;
	std::cout << "Amount Paid: " << amountPaid << std::endl;
	counter = games[selectedGame].getQuantity();
	if (current < games[selectedGame].getCost())
		games[selectedGame].setQuantity(counter + 1);
}

/********************************************************************
*** FUNCTION: processChange
*********************************************************************
*** DESCRIPTION :Processes the change of a game
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Console::processChange()
{
	int numTen = 0;
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
		if (change >= 10)
		{
			std::cout << "$10 "; 
			numTen++;
			change = change - 10;
		}
		else if (change > 0 && change < 10)
		{
			std::cout << "$1 ";
			numOne++;
			change = change - 1;
		}
	}
	std::cout << std::endl << "Change given: (" << numTen << ") $10, (" << numOne << ") $1" << std::endl;
}

/********************************************************************
*** FUNCTION: processDelivery
*********************************************************************
*** DESCRIPTION :Processes the delivery of a game
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void Console::processDelivery() const
{
	if (amountPaid >= games[selectedGame].getCost())
	{
		std::cout << std::endl << "Thank you for visiting!" << std::endl;
		std::cout << "Enjoy " << games[selectedGame].getTitle() << "!" << std::endl;
		system("pause");
	}
}