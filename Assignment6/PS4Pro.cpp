#include "PS4Pro.h"
#include <iostream>

/********************************************************************
*** FUNCTION: PS4Pro
*********************************************************************
*** DESCRIPTION :Constructor for the ps4
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
PS4Pro::PS4Pro() : Console(4)
{
	Game CallOfDutyWWII("Call of Duty WWII", 54, 3);
	Game FarCry5("Far Cry 5", 50, 4);
	Game GodOfWar("God of War", 46, 5);
	Game RedDeadRedemption2("Red Dead Redemption 2", 57, 2);
	games[0] = CallOfDutyWWII;
	games[1] = FarCry5;
	games[2] = GodOfWar;
	games[3] = RedDeadRedemption2;
}

/********************************************************************
*** FUNCTION: ~PS4Pro
*********************************************************************
*** DESCRIPTION :Destructor for the ps4
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : None
********************************************************************/
PS4Pro::~PS4Pro()
{

}

/********************************************************************
*** FUNCTION: processIntroduction
*********************************************************************
*** DESCRIPTION :Introduction to the PS4 store
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void PS4Pro::processIntroduction()
{
	system("cls");
	std::cout << "Welcome to the PS4Pro Store!" << std::endl;
	std::cout << "Select a game to purchase!" << std::endl << std::endl;
}

/********************************************************************
*** FUNCTION: processPayment
*********************************************************************
*** DESCRIPTION :Processes the payment for a given game in the store
*** INPUT ARGS : None
*** OUTPUT ARGS : None
*** IN/OUT ARGS : None
*** RETURN : void
********************************************************************/
void PS4Pro::processPayment()
{
	int counter;
	int numFive = 0;
	int numTen = 0;
	int numOne = 0;
	int current = 0;
	int left = 0;

	std::cout << "You have selected " << games[selectedGame].getTitle() << std::endl;
	left = games[selectedGame].getCost();
	std::cout << "Total due: $" << games[selectedGame].getCost() << std::endl;
	std::cout << "Bills accepted: $10, $5, $1" << std::endl;
	std::cout << "Please enter the number of $10 bills: ";
	std::cin >> numTen;
	current = current + (10 * numTen);
	left = left - (10 * numTen);
	if (left < 0)
		std::cout << "Total due: $0" << std::endl;
	else
		std::cout << "Total due: $" << left << std::endl;

	std::cout << "Please enter the number of $5 bills: ";
	std::cin >> numFive;
	current = current + (5 * numFive);
	left = left - (5 * numFive);
	if (left < 0)
		std::cout << "Total due: $0" << std::endl;
	else
		std::cout << "Total due: $" << left << std::endl;

	std::cout << "Please enter the number of $1 bills: ";
	std::cin >> numOne;
	current = current + (1 * numOne);
	left = left - (1 * numOne);
	if (left <= 0)
		std::cout << "Total due: $0" << std::endl;
	else
	{
		std::cout << std::endl << "I'm sorry, that was not enough money. \nTotal due: $" << left << std::endl;
		system("pause");
	}
	amountPaid = current;
	counter = games[selectedGame].getQuantity();
	std::cout << "Amount Paid: " << amountPaid << std::endl;
	if (current < games[selectedGame].getCost())
		games[selectedGame].setQuantity(counter + 1);
}