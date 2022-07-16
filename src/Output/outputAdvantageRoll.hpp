#ifndef OUTPUT_ADVANTAGE_ROLL_
#define OUTPUT_ADVANTAGE_ROLL_

#include <iostream>
#include <string>
#include "../Processing/generateRoll.hpp"

/**
 * @brief Outputs two different d20 rolls using the passed in modifier.
 *
 * @param charName
 * @param skillName
 * @param modifier
 * @param damageFlag
 *
 */
void outputAdvantageRoll(std::string charName, std::string skillName, short modifier, bool damageFlag) {
    // generate a random number from (1, 20) and add the appropriate modifier
    short roll1 = generateRoll(1, 20); // LHS d20 roll
    roll1 = roll1 + modifier;

    // Have to do some work between the the two rolls to
    // allow the seed to produce new random numbers.
    std::cout << charName << ":" << std::endl;
    std::cout << "┏┅┅┅┅┅┅┅┅┅┅┯┅┅┅┅┅┅┅┅┅┅┓" << std::endl;

    // get the length of roll1
    size_t split1 = 5 - ((std::to_string(roll1).length()) / 2);

    // generate another random number from (1, 20) and add the appropriate modifier
    short roll2 = generateRoll(1, 20); // RHS d20 roll
    roll2 = roll2 + modifier;

    // Get the length of roll2
    size_t split2 = 5 - ((std::to_string(roll2).length()) / 2);

    // Format the output based on if the rolls are single/double digit(s)
    std::cout << "┊";
    for (size_t i = 0; i < split1; i++)
        std::cout << " ";
    std::cout << roll1;

    // If the roll is a single digit
    if (roll1 < 10 && roll1 > -1) {
        for (size_t i = 0; i < split1 - 1; i++)
            std::cout << " ";
    }
    // If the roll is two digits
    else {
        for (size_t i = 0; i < split1; i++)
            std::cout << " ";
    }
    std::cout << "┊";

    for (size_t i = 0; i < split2; i++)
        std::cout << " ";
    std::cout << roll2;

    // If the roll is a single digit
    if (roll2 < 10 && roll2 > -1) {
        for (size_t i = 0; i < split2 - 1; i++)
            std::cout << " ";
    }
    // If the roll is two digits
    else {
        for (size_t i = 0; i < split2; i++)
            std::cout << " ";
    }
    std::cout << "┊" << std::endl;

    std::cout << "┊┅┅┅┅┅┅┅┅┅┅┻┅┅┅┅┅┅┅┅┅┅┊" << std::endl;

    // Adds the length of (__) to split.
    size_t split = skillName.length();
    if (modifier > 9 || modifier < 0)
        split = split + 4;
    else
        split = split + 3;
    split = 21 - split;

    // Formats the skill name to be centered in the box.
    std::cout << "┊";
    for (size_t i = 0; i < split / 2; i++)
        std::cout << " ";
    std::cout << skillName << "(" << modifier << ")";
    for (size_t i = 0; i < split / 2; i++)
        std::cout << " ";

    // adds an additional space if the length of the skill name is odd.
    if (split % 2 != 0)
        std::cout << " ";

    std::cout << "┊" << std::endl;
    std::cout << "┗┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┛" << std::endl << std::endl;
}

#endif