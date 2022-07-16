#ifndef OUTPUT_HELP_
#define OUTPUT_HELP_

#include <iostream>
#include "../../lib/NamedConstants.hpp"

/**
 * @brief Outputs a list of commands for the user to make a roll.
 *
 */
void outputHelp() {
    std::cout << "Command categories:" << std::endl;
    std::cout << "   > Enter  terminate  when  you want  to  quit." << std::endl;
    std::cout << "   > Roll  a  new   character  by  rolling  4d6," << std::endl;
    std::cout << "     dropping   the  lowest  d6:   /newCharacter" << std::endl;
    std::cout << "   > Make a custom roll using any number of dice" << std::endl;
    std::cout << "     and any  die size.  You may also  include a" << std::endl;
    std::cout << "     modifier  and/or a damage type.  The format" << std::endl;
    std::cout << "     for the roll must include spaces,  and must" << std::endl;
    std::cout << "     have the die size. Examples: " << std::endl;
    std::cout << "         > /roll 10d6 + 40 Force" << std::endl;
    std::cout << "         > /roll 4d4 + 4" << std::endl;
    std::cout << "         > /roll 8d6 Fire" << std::endl;
    std::cout << "         > /roll 1d20" << std::endl;
    std::cout << "   > Make a  'common' roll,  like a saving throw" << std::endl;
    std::cout << "     or skill check.  Would you like to see  the" << std::endl;
    std::cout << "     list of 'common' roll commands [Y/n]? ";

    char cont;
    std::cin >> cont;
    std::cout << std::endl;

    // Print out the commands for 'common' rolls
    if (cont == 'y' || cont == 'Y') {
        std::cout << "Ability Checks:" << std::endl;
        for (short i = Strength; i <= Charisma; i++)
            std::cout << "    > /" << RollNames[i] << std::endl;
        std::cout << std::endl;

        std::cout << "Saving Throws:" << std::endl;
        for (short i = StrengthSave; i <= CharismaSave; i++)
            std::cout << "    > /" << RollNames[i] << std::endl;
        std::cout << std::endl;

        std::cout << "Skill Checks:" << std::endl;
        for (short i = Athletics; i <= Persuasion; i++)
            std::cout << "    > /" << RollNames[i] << std::endl;
        std::cout << std::endl;

        std::cout << "Miscellaneous Rolls:" << std::endl;
        for (short i = HitDice; i <= DeathSave; i++)
            std::cout << "    > /" << RollNames[i] << std::endl;

        std::cout << "___________________________________________________________" << std::endl << std::endl;
    }
}

#endif