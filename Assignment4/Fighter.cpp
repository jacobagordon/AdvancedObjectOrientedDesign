#include <iostream>
#include <string>
#include "Fighter.h"
namespace AdventurerNS{

/*********************************************************
Function: Default constructor
**********************************************************
Description: Instantiates Fighter object with default
			 values or passed in values.
Input Args: string, RaceType, int, int, ToolType
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

Fighter::Fighter(const std::string newName, const int newHealth, const int newStamina, const RaceType newRace, const ToolType newTool) : name(newName), health(newHealth), stamina(newStamina), race(newRace), tool(newTool)
{
	return;
}

/*********************************************************
Function: Copy constructor
**********************************************************
Description: Instantiates a copy of a Fighter object
Input Args: Fighter &
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

Fighter::Fighter(const Fighter &old) : name(old.name), health(old.health), stamina(old.stamina), race(old.race), tool(old.tool)
{
    return;
}

/*********************************************************
Function: Destructor
**********************************************************
Description: Destroys a Fighter
Input Args: None
Output Args: None
In/Out Args: None
Return : None
**********************************************************/

Fighter::~Fighter()
{
    std::cout << "Fighter class instance destroyed" << std::endl;
}

}
