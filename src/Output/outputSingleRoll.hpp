#ifndef OUTPUT_SINGLE_ROLL_
#define OUTPUT_SINGLE_ROLL_

#include <iostream>
#include <string>
#include "../Processing/generateRoll.hpp"

/**
 * @brief Similar to outputAdvantageRoll, but only rolls a single die
 *        and can roll damage.
 *
 * @param charName
 * @param skillName
 * @param modifier
 * @param numDice
 * @param dieSize
 * @param damageFlag
 *
 */
void outputSingleRoll(std::string charName, std::string skillName, short modifier, short numDice, short dieSize, bool damageFlag) {
    // generate a random number from (1, dieSize) and add the appropriate modifier
    short roll = generateRoll(numDice, dieSize);
    roll = roll + modifier;

    std::cout << charName << ":" << std::endl;
    std::cout << "┏┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┓" << std::endl;

    size_t split = 10 - ((std::to_string(roll).length()) / 2);

    // Format the output based on if the rolls are single/double digit(s)
    std::cout << "┊";
    for (size_t i = 0; i < split; i++)
        std::cout << " ";
    std::cout << roll;

    // If the roll is a single digit
    if (roll < 10 && roll > -1) {
        for (size_t i = 0; i < split; i++)
            std::cout << " ";
    }
    // If the roll is two digits
    else {
        for (size_t i = 0; i < split + 1; i++)
            std::cout << " ";
    }
    std::cout << "┊" << std::endl;

    // Formats the skill name to be centered in the box.
    if (skillName == "")
        std::cout << "┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛" << std::endl << std::endl;
    if (skillName != "") {
        std::cout << "┊┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┊" << std::endl;

        split = skillName.length();
        if (damageFlag == false) {
            // Adds the length of (__) to split.
            if (modifier > 9 || modifier < 0)
                split = split + 4;
            else
                split = split + 3;
            split = 21 - split;

            std::cout << "┊";
            for (size_t i = 0; i < split / 2; i++)
                std::cout << " ";

            std::cout << skillName << "(" << modifier << ")";
            for (size_t i = 0; i < split / 2; i++)
                std::cout << " ";
        }

        // We don't need to output the modifier if it's a damage roll.
        if (damageFlag == true) {
            split = 21 - skillName.length();

            std::cout << "┊";
            for (size_t i = 0; i < split / 2; i++)
                std::cout << " ";
            std::cout << skillName;
            for (size_t i = 0; i < split / 2; i++)
                std::cout << " ";
        }
        // adds an additional space if the length of the skill name is odd.
        if (split % 2 != 0)
            std::cout << " ";

        std::cout << "┊" << std::endl;
        std::cout << "┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛" << std::endl << std::endl;
    }
}

#endif