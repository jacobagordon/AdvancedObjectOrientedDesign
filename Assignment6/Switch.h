#pragma once
#include "Console.h"
class Switch :
	public Console
{
public:
	/********************************************************************
	*** FUNCTION: Switch
	*********************************************************************
	*** DESCRIPTION :Constructor for the switch
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	Switch();

	/********************************************************************
	*** FUNCTION: ~Switch
	*********************************************************************
	*** DESCRIPTION :Destructor for the switch
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	~Switch();
protected:
	/********************************************************************
	*** FUNCTION: processIntroduction
	*********************************************************************
	*** DESCRIPTION :Introduction to the Switch store
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processIntroduction();

	/********************************************************************
	*** FUNCTION: processChange
	*********************************************************************
	*** DESCRIPTION :Processes the change for a given game in the store
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processChange();
};

