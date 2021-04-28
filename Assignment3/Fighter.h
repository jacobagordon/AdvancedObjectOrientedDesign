#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>
#include <string>

namespace AdventurerNS{ // declares namespace

class Fighter
{
public:
	Fighter(const std::string = "Shavir", const int = 80, const int = 70, const RaceType = KHAJIIT, const ToolType = DAGGER);
	Fighter(const Fighter &);
	~Fighter();
	inline void setName(const std::string newName) {
		name = newName;
	}
    std::string getName() const {
		return name;
	}
	void setHealth(const int newHealth) {
		health = newHealth;
	}
    int getHealth() const {
		return health;
	}
	void setStamina(const int newStamina) {
		stamina = newStamina;
	}
    int getStamina() const {
		return stamina;
	}
	inline void setRaceKhajiit();
	inline void setRaceOrsimer();
	inline bool isRaceKhajiit() const;
	inline bool isRaceOrsimer() const;
	void setToolBattleaxe();
	void setToolDagger();
	void setToolSword();
	bool isToolBattleaxe() const;
	bool isToolDagger() const;
	bool isToolSword() const;
private:
	//enumerated data types
	enum RaceType {KHAJIIT, ORSIMER};
	enum ToolType {BATTLEAXE, DAGGER, SWORD};
    std::string name;
    RaceType race;
    int health;
    int stamina;
    ToolType tool;
};

inline void Fighter::setRaceKhajiit()
{
	race = KHAJIIT;
}

inline void Fighter::setOrsimer()
{
	race = ORSIMER;
}

inline bool Fighter::isRaceKhajiit() const
{
	return race == KHAJIIT;
}

inline bool Fighter::isRaceOrsimer() const
{
	return race == KHAJIIT;
}

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

