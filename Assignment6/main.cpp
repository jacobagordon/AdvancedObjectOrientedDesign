#include <iostream>
#include "PS4Pro.h"
#include "Switch.h"
#include "Game.h"
using namespace std;

int main()
{
	PS4Pro playstation;
	Switch nintendo;
	int choice = 0;

	do {
		system("cls");
		cout << "Welcome to Vending Games!" << endl;
		cout << "Please start by selecting a console" << endl;
		cout << "	1.) Playstation 4 Pro" << endl;
		cout << "	2.) Nintendo Switch" << endl;
		cout << "	3.) Quit" << endl;
		cout << "Enter the number of your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			playstation.processStart();
			break;
		case 2:
			nintendo.processStart();
			break;
		case 3:
			cout << "Please come again!" << endl;
			break;
		default:
			cout << "Invalid Entry" << endl;
			system("pause");
		}
	} while (choice != 3);
	return 0;
}