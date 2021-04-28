#include <iostream>
#include "FighterView.h"
using namespace AdventurerNS;

int main()
{
    Fighter One("Jake", 50, 50);
	Fighter Two;
	Fighter Four("John");
	Fighter Five("Amy", 11);
	Fighter Six;
	Six.setRaceOrsimer();
	Six.setToolSword();
	FighterView Seis(Six); 
	Seis.viewFighter(); //1
	Six.setToolBattleaxe();
	Seis.setFighter(Six);
	Seis.viewFighter(); //2
	One.setRaceOrsimer();
	Fighter Three(One);
	FighterView Uno(One);
	FighterView Dos(Two);
	FighterView Tres(Three);
	FighterView Cuatro(Four);
	FighterView Cinco(Five);
	Fighter Seven("Test", 1, 1);
	Seven.setToolBattleaxe();
	Seven.setToolDagger();
	Seven.setRaceOrsimer();
	Seven.setRaceKhajiit();
	FighterView Siete(Seven);
	Uno.viewFighter(); //3
	Dos.viewFighter(); //4
	Tres.viewFighter(); //5
	Cuatro.viewFighter(); //6
	Cinco.viewFighter(); //7
	Siete.viewFighter(); //8
	Fighter Eight;
	Eight.setName("Tony");
	Eight.setHealth(9);
	Eight.setStamina(3);
	std::cout << "Name: " << Eight.getName() << std::endl;
	std::cout << "Health: " << Eight.getHealth() << std::endl;
	std::cout << "Stamina: " << Eight.getStamina() << std::endl;
	FighterView Ocho(Eight);
	Ocho.viewFighter(); //9
	Fighter Nine(Eight);
	Nine.setName();
	Nine.setHealth();
	Nine.setStamina();
	FighterView Nueve(Nine);
	Nueve.viewFighter(); //10
	FighterView Diez(Ocho);
	Diez.viewFighter(); //11
	return 0;
}
