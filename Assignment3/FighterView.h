#ifndef FIGHTERVIEW_H
#define FIGHTERVIEW_H

#include <iostream>
#include "Fighter.h"
namespace AdventurerNS{ // declares namespace

class FighterView
{
private:
    Fighter oneFighter;
public:
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
	FighterView();
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
    FighterView(const Fighter &);
/*********************************************************
Function: Copy constructor
**********************************************************
Description: Instantiates a copy of a FighterView object
Input Args: FighterView &
Output Args: None
In/Out Args: None
Return : None
**********************************************************/
    FighterView(const FighterView &);
/*********************************************************
Function: Destructor
**********************************************************
Description: Destroys FighterView
Input Args: None
Output Args: None
In/Out Args: None
Return : None
**********************************************************/
    ~FighterView();
/*********************************************************
Function: setFighter
**********************************************************
Description: Sets values of Fighter in FighterView
Input Args: Fighter &
Output Args: None
In/Out Args: None
Return : void
**********************************************************/
    void setFighter(const Fighter &);
/*********************************************************
Function: viewFighter
**********************************************************
Description: Displays a Fighter
Input Args:  None
Output Args: None
In/Out Args: None
Return : Void
**********************************************************/
    void viewFighter() const;
};
}
#endif // FIGHTERVIEW_H

