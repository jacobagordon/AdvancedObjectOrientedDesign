#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>
#include <string>

namespace AdventurerNS{ // declares namespace

class Fighter
{
private:
	//enumerated data types
	enum RaceType {KHAJIIT, ORSIMER};
	enum ToolType {BATTLEAXE, DAGGER, SWORD};
    std::string name;
    RaceType race;
    int health;
    int stamina;
    ToolType tool;
public:
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
	Fighter(const std::string = "Shavir", const int = 80, const int = 70, const RaceType = KHAJIIT, const ToolType = DAGGER);
/*********************************************************
Function: Copy constructor
**********************************************************
Description: Instantiates a copy of a Fighter object
Input Args: Fighter &
Output Args: None
In/Out Args: None
Return : None
**********************************************************/	
	Fighter(const Fighter &);
/*********************************************************
Function: Destructor
**********************************************************
Description: Destroys a Fighter
Input Args: None
Output Args: None
In/Out Args: None
Return : None
**********************************************************/
	~Fighter();
/*********************************************************
Function: setName / getName
**********************************************************
Description: Sets or gets the name of a fighter
			written implicit inline
Input Args: string / none
Output Args: None
In/Out Args: None
Return : void / string
**********************************************************/	
	inline void setName(const std::string newName = "Shavir") {
		name = newName;
	}
    inline std::string getName() const {
		return name;
	}
/*********************************************************
Function: setHealth / getHealth
**********************************************************
Description: Sets or gets the health of a fighter
			written implicit inline
Input Args: int / None
Output Args: None
In/Out Args: None
Return : void / int
**********************************************************/
	inline void setHealth(const int newHealth = 80) {
		health = newHealth;
	}
    inline int getHealth() const {
		return health;
	}
/*********************************************************
Function: setStamina / getStamina
**********************************************************
Description: Sets or gets the stamina of a fighter
			written implicit inline
Input Args: int / None
Output Args: None
In/Out Args: None
Return : void / int
**********************************************************/
	inline void setStamina(const int newStamina = 70) {
		stamina = newStamina;
	}
    inline int getStamina() const {
		return stamina;
	}
/*********************************************************
Function: setRace Khajiit/Orsimer
**********************************************************
Description: Sets the RaceType race value
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : void
**********************************************************/
	inline void setRaceKhajiit();
	inline void setRaceOrsimer();
/*********************************************************
Function: isRace Khajiit/Orsimer
**********************************************************
Description: Checks the value of RaceType race
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : bool
**********************************************************/
	inline bool isRaceKhajiit() const;
	inline bool isRaceOrsimer() const;
/*********************************************************
Function: setTool Battleaxe/Dagger/Sword
**********************************************************
Description: Sets the ToolType tool value
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : void
**********************************************************/
	inline void setToolBattleaxe();
	inline void setToolDagger();
	inline void setToolSword();
/*********************************************************
Function: isTool Battleaxe/Dagger/Sword
**********************************************************
Description: Checks the value of ToolType tool
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : bool
**********************************************************/
	inline bool isToolBattleaxe() const;
	inline bool isToolDagger() const;
	inline bool isToolSword() const;
};

/*********************************************************
Function: setRace Khajiit/Orsimer
**********************************************************
Description: Sets the RaceType race value
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : void
**********************************************************/
inline void Fighter::setRaceKhajiit()
{
	race = KHAJIIT;
}

inline void Fighter::setRaceOrsimer()
{
	race = ORSIMER;
}
/*********************************************************
Function: isRace Khajiit/Orsimer
**********************************************************
Description: Checks the value of RaceType race
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : bool
**********************************************************/
inline bool Fighter::isRaceKhajiit() const
{
	return race == KHAJIIT;
}

inline bool Fighter::isRaceOrsimer() const
{
	return race == KHAJIIT;
}
/*********************************************************
Function: setTool Battleaxe/Dagger/Sword
**********************************************************
Description: Sets the ToolType tool value
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : void
**********************************************************/
inline void Fighter::setToolBattleaxe()
{
	tool = BATTLEAXE;
}

inline void Fighter::setToolDagger()
{
	tool = DAGGER;
}

inline void Fighter::setToolSword()
{
	tool = SWORD;
}
/*********************************************************
Function: isTool Battleaxe/Dagger/Sword
**********************************************************
Description: Checks the value of ToolType tool
			written explicit inline
Input Args: None
Output Args: None
In/Out Args: None
Return : bool
**********************************************************/
inline bool Fighter::isToolBattleaxe() const
{
	return tool == BATTLEAXE;
}

inline bool Fighter::isToolDagger() const
{
	return tool == DAGGER;
}

inline bool Fighter::isToolSword() const
{
	return tool == SWORD;
}

}
#endif // FIGHTER_H

