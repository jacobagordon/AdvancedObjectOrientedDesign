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
    oneFighter.setRace(newFighter.getRace());
    oneFighter.setHealth(newFighter.getHealth());
    oneFighter.setStamina(newFighter.getStamina());
    oneFighter.setTool(newFighter.getTool());
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
	std::cout << std::setw(15) << "Class" << std::setw(15) << "Name" << std::setw(15) << "Race" << std::setw(10) << "Health" << std::setw(10) << "Stamina" << std::setw(10) << "Tool" << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	if(oneFighter.getRace() == Fighter::IMPERIAL)
		printrace = "Imperial";
	else if(oneFighter.getRace() == Fighter::NORD)
		printrace = "Nord";
	else
		printrace = "Redguard";

	if(oneFighter.getTool() == Fighter::DAGGER)
		printtool = "Dagger";
	else
		printtool = "Sword";

	std::cout << std::setw(15) << "Fighter" << std::setw(15) << oneFighter.getName() << std::setw(15) << printrace << std::setw(10) << oneFighter.getHealth() << std::setw(10) << oneFighter.getStamina() << std::setw(10) << printtool << std::endl << std::endl;
}

}
