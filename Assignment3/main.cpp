#include <iostream>
#include "FighterView.h"
using namespace AdventurerNS;

int main()
{
    Fighter None;
    Fighter One("One");
    Fighter Two("Two", Fighter::NORD);
    Fighter Three("Three", Fighter::NORD, 66);
    Fighter Four("Four", Fighter::REDGUARD, 44, 11);
    Fighter Five("Five", Fighter::IMPERIAL, 22, 33, Fighter::DAGGER);
    Fighter copiedFighter(One);
    FighterView Nada;
    FighterView Uno(One);
    FighterView Dos(Two);
    FighterView Tres(Three);
    FighterView Cuatro(Four);
    FighterView Cinco(Five);
    FighterView Unoriginal(Cinco);
    FighterView cF(copiedFighter);
    Nada.viewFighter();
    Uno.viewFighter();
    Dos.viewFighter();
    Tres.viewFighter();
    Cuatro.viewFighter();
    Cinco.viewFighter();
    Unoriginal.viewFighter();
    cF.viewFighter();
    Fighter Tester;
    Tester.setName("NewName");
    std::cout << "Tester Name: " << Tester.getName() << std::endl;
    Tester.setRace(Fighter::NORD);
    std::cout << "Tester Race: " << Tester.getRace() << std::endl;
    Tester.setHealth(9);
    std::cout << "Tester Health: " << Tester.getHealth() << std::endl;
    Tester.setStamina(1);
    std::cout << "Tester Stamina: " << Tester.getStamina() << std::endl;
    Tester.setTool(Fighter::DAGGER);
    std::cout << "Tester Tool: " << Tester.getTool() << std::endl;
    std::cout << "Now back to defaults" << std::endl;
    Tester.setName();
    std::cout << "Tester Name: " << Tester.getName() << std::endl;
    Tester.setRace();
    std::cout << "Tester Race: " << Tester.getRace() << std::endl;
    Tester.setHealth();
    std::cout << "Tester Health: " << Tester.getHealth() << std::endl;
    Tester.setStamina();
    std::cout << "Tester Stamina: " << Tester.getStamina() << std::endl;
    Tester.setTool();
    std::cout << "Tester Tool: " << Tester.getTool() << std::endl;
    FighterView ViewTester(Tester);
    ViewTester.viewFighter();
    ViewTester.setFighter(One);
    ViewTester.viewFighter();
    return 0;
}
