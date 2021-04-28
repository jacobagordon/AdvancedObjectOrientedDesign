#pragma once
#include "Console.h"
class PS4Pro :
	public Console
{
public:
	/********************************************************************
	*** FUNCTION: PS4Pro
	*********************************************************************
	*** DESCRIPTION :Constructor for the ps4
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	PS4Pro();

	/********************************************************************
	*** FUNCTION: ~PS4Pro
	*********************************************************************
	*** DESCRIPTION :Destructor for the ps4
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : None
	********************************************************************/
	~PS4Pro();
protected:
	/********************************************************************
	*** FUNCTION: processIntroduction
	*********************************************************************
	*** DESCRIPTION :Introduction to the PS4 store
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processIntroduction();

	/********************************************************************
	*** FUNCTION: processPayment
	*********************************************************************
	*** DESCRIPTION :Processes the payment for a given game in the store
	*** INPUT ARGS : None
	*** OUTPUT ARGS : None
	*** IN/OUT ARGS : None
	*** RETURN : void
	********************************************************************/
	virtual void processPayment();
};

