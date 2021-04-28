#include <iostream>
#include <string>
#include <iomanip>
#include "FighterView.h"
namespace AdventurerNS{

/*********************************************************
Function: Default constructor
**********************************************************
Description: Instantiates Fighter View object with default
			 values
Input Args: None
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

FighterView::FighterView()
{
	return;
}

/*********************************************************
Function: Constructor
**********************************************************
Description: Instantiates Fighter View object with a
			 passed in Fighter object
Input Args: Fighter &
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

FighterView::FighterView(const Fighter &copiedFighter)
{
    setFighter(copiedFighter);
}

/*********************************************************
Function: Copy constructor
**********************************************************
Description: Instantiates a copy of a FighterView object
Input Args: FighterView &
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

FighterView::FighterView(const FighterView &copiedFighter)
{
   setFighter(copiedFighter.oneFighter);
}

/*********************************************************
Function: Destructor
**********************************************************
Description: Destroys FighterView
Input Args: None
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

FighterView::~FighterView()
{
    std::cout << "FighterView class instance destroyed" << std::endl;
}

/*********************************************************
Function: setFighter
**********************************************************
Description: Sets values of Fighter in FighterView
Input Args: Fighter &
Output Args: None
In/Out Args: None
Return : void
**********************************************************/

void FighterView::setFighter(const Fighter &newFighter)
{
    oneFighter.setName(newFighter.getName());
    oneFighter.setHealth(newFighter.getHealth());
    oneFighter.setStamina(newFighter.getStamina());
	if (newFighter.isToolBattleaxe())
		oneFighter.setToolBattleaxe();
	else if (newFighter.isToolSword())
		oneFighter.setToolSword();
	else
		oneFighter.setToolDagger();

	if (newFighter.isRaceOrsimer())
		oneFighter.setRaceOrsimer();
	else
		oneFighter.setRaceKhajiit();
}

/*********************************************************
Function: viewFighter
**********************************************************
Description: Displays a Fighter
Input Args:  None
Output Args: None
In/Out Args: None
Return : Void
**********************************************************/

void FighterView::viewFighter() const
{
    std::string printrace;
	std::string printtool;
	std::cout << std::setw(15) << std::left << "Class" << std::setw(15) << "Name" << std::setw(15) << "Race" << std::setw(10) << "Health" << std::setw(10) << "Stamina" << std::setw(10) << "Tool" << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	if(oneFighter.isToolSword())
		printtool = "Sword";
	else if(oneFighter.isToolBattleaxe())
		printtool = "Battleaxe";
	else
		printtool = "Dagger";

	if(oneFighter.isRaceOrsimer())
		printrace = "Orsimer";
	else
		printrace = "Khajiit";

	std::cout << std::setw(15) << std::left << "Fighter" << std::setw(15) << oneFighter.getName() << std::setw(15) << printrace << std::setw(10) << oneFighter.getHealth() << std::setw(10) << oneFighter.getStamina() << std::setw(10) << printtool << std::endl << std::endl;
}

}
