#ifndef COMMAND_LOOP_
#define COMMAND_LOOP_

#include "../../lib/NamedConstants.hpp"
#include "../Output/outputAdvantageRoll.hpp"
#include "../Output/outputHelp.hpp"
#include "../Output/outputSingleRoll.hpp"
#include "processRoll.hpp"
#include "rollNewCharacter.hpp"
#include "../rollData/rollData.hpp"
#include "../characterInfo/characterInfo.hpp"
#include <iostream>
#include <string>

/**
 * @brief Continuously prompts the user for a command, and makes the appropriate
 * function call and/or roll. Returns when the user types 'terminate'
 *
 * @param character
 *
 */
void commandLoop(characterInfo character) {
    std::string input;

    std::cout << std::endl << "Please enter your custom roll, or the command for a common " << std::endl
                 << "skill  check.  Enter '-h'  for a list of commands  or  the " << std::endl
                 << "proper  way to format your custom roll.  Enter 'terminate' " << std::endl
                 << "when you want to quit." << std::endl << std::endl << "> ";

    // If a user clicks a button(TODO) on the character sheet(TODO), it will roll
    // the appropriate dice and output the result of the roll using the correct modifier.
    while(getline(std::cin, input)) {

        // flag is used to prevent double output of '> ' after the outputHelp() call.
        bool flag = false;

        // User can ctrl+c to terminate, or just type 'terminate'
        if (input == "terminate")
            return;

        // Calls the outputHelp function which displays the commands
        // the user can type to make rolls.
        if (input == "-h" || input == "/help" || input == "help") {
            outputHelp();
            flag = true;
        }
        // A custom roll based on what the user typed, starting with /roll
        if (input[0] == '/' && input[1] == 'r' && input[2] == 'o' && input[3] == 'l' && input[4] == 'l') {
            rollData theRoll;
            theRoll = processRoll(theRoll, input);

            outputSingleRoll(character.getCharacterName(),
                theRoll.getDamageType(), theRoll.getModifier(),
                theRoll.getNumberOfDice(), theRoll.getDieSize(), true);
        }

        // Erases the '/' so we can use the typedefs
        if (input[0] == '/') {
            input.erase(0, 1);

            // Generates 6 ability scores using 4d6 dropping the lowest d6.
            if (input == NEWCHAR)
                rollNewCharacter();

            // This is the 'common' rolls section:
            if (input == STR)
                outputAdvantageRoll(character.getCharacterName(),
                    STR, character.getStrengthModifier(), false);
            if (input == DEX)
                outputAdvantageRoll(character.getCharacterName(),
                    DEX, character.getDexterityModifier(), false);
            if (input == CON)
                outputAdvantageRoll(character.getCharacterName(),
                    CON, character.getConstitutionModifier(), false);
            if (input == INT)
                outputAdvantageRoll(character.getCharacterName(),
                    INT, character.getIntelligenceModifier(), false);
            if (input == WIS)
                outputAdvantageRoll(character.getCharacterName(),
                    WIS, character.getWisdomModifier(), false);
            if (input == CHA)
                outputAdvantageRoll(character.getCharacterName(),
                    CHA, character.getCharismaModifier(), false);
            if (input == STRSAVE)
                outputAdvantageRoll(character.getCharacterName(),
                    STRSAVE, character.getStrengthSave(), false);
            if (input == DEXSAVE)
                outputAdvantageRoll(character.getCharacterName(),
                    DEXSAVE, character.getDexteritySave(), false);
            if (input == CONSAVE)
                outputAdvantageRoll(character.getCharacterName(),
                    CONSAVE, character.getConstitutionSave(), false);
            if (input == INTSAVE)
                outputAdvantageRoll(character.getCharacterName(),
                    INTSAVE, character.getIntelligenceSave(), false);
            if (input == WISSAVE)
                outputAdvantageRoll(character.getCharacterName(),
                    WISSAVE, character.getWisdomSave(), false);
            if (input == CHASAVE)
                outputAdvantageRoll(character.getCharacterName(),
                    CHASAVE, character.getCharismaSave(), false);
            if (input == ATHLETICS)
                outputAdvantageRoll(character.getCharacterName(),
                    ATHLETICS, character.getAthletics(), false);
            if (input == INITIATIVE)
                outputSingleRoll(character.getCharacterName(),
                    INITIATIVE, character.getInitiative(), 1, 20, false);
            if (input == ACROBATICS)
                outputAdvantageRoll(character.getCharacterName(),
                    ACROBATICS, character.getAcrobatics(), false);
            if (input == SLEIGHT)
                outputAdvantageRoll(character.getCharacterName(),
                    SLEIGHT, character.getSleightOfHand(), false);
            if (input == STEALTH)
                outputAdvantageRoll(character.getCharacterName(),
                    STEALTH, character.getStealth(), false);
            if (input == ARCANA)
                outputAdvantageRoll(character.getCharacterName(),
                    ARCANA, character.getArcana(), false);
            if (input == HISTORY)
                outputAdvantageRoll(character.getCharacterName(),
                    HISTORY, character.getHistory(), false);
            if (input == INVESTIGATE)
                outputAdvantageRoll(character.getCharacterName(),
                    INVESTIGATE, character.getInvestigation(), false);
            if (input == NATURE)
                outputAdvantageRoll(character.getCharacterName(),
                    NATURE, character.getNature(), false);
            if (input == RELIGION)
                outputAdvantageRoll(character.getCharacterName(),
                    RELIGION, character.getReligion(), false);
            if (input == ANIMAL_HAND)
                outputAdvantageRoll(character.getCharacterName(),
                    ANIMAL_HAND, character.getAnimalHandling(), false);
            if (input == INSIGHT)
                outputAdvantageRoll(character.getCharacterName(),
                    INSIGHT, character.getInsight(), false);
            if (input == MEDICINE)
                outputAdvantageRoll(character.getCharacterName(),
                    MEDICINE, character.getMedicine(), false);
            if (input == PERCEPTION)
                outputAdvantageRoll(character.getCharacterName(),
                    PERCEPTION, character.getPerception(), false);
            if (input == SURVIVAL)
                outputAdvantageRoll(character.getCharacterName(),
                    SURVIVAL, character.getSurvival(), false);
            if (input == DECEPTION)
                outputAdvantageRoll(character.getCharacterName(),
                    DECEPTION, character.getDeception(), false);
            if (input == INTIMIDATE)
                outputAdvantageRoll(character.getCharacterName(),
                    INTIMIDATE, character.getIntimidation(), false);
            if (input == PERFORMANCE)
                outputAdvantageRoll(character.getCharacterName(),
                    PERFORMANCE, character.getPerformance(), false);
            if (input == PERSUASION)
                outputAdvantageRoll(character.getCharacterName(),
                    PERSUASION, character.getPersuasion(), false);
            if (input == HITDICE)
                outputSingleRoll(character.getCharacterName(),
                    HITDICE, character.getConstitutionModifier(),
                    1, character.getHitDiceSize(), false);
            if (input == DEATHSAVE)
                outputSingleRoll(character.getCharacterName(),
                    DEATHSAVE, 0, 1, 20, false);
        }

        // prevents double output of '> ' after the help command.
        if (flag == false)
            std::cout << "> ";
        if (flag == true)
            flag = false;
    }
}
#endif