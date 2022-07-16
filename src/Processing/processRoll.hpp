#ifndef PROCESS_ROLL_
#define PROCESS_ROLL_

#include <iostream>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "../rollData/rollData.hpp"

/**
 * @brief used for the command '/roll', loads the appropritate data into the class fields
 *
 * @param theRoll
 * @param data
 * @return rollData object
 *
 */
rollData processRoll(rollData theRoll, std::string data) {
    std::string token;
    std::istringstream iss(data);
    short parse_input = 0;

    // Splits the line of input into individual tokens delimited by ' '
    while(getline(iss, token, ' ')) {
        // parse_input == 0 is ignored since it just contains the command /roll.

        // Splits up the dice count and size of dice, and loads them into the
        // number_of_dice and die_size fields. (ex. 12d10 gets split into 12 and 10)
        if (parse_input == 1) {
            size_t length = token.length();

            // Handles the case where the number of dice isn't
            // specified since '/roll d20' is the same as '/roll 1d20'
            if (token[0] == 'd') {
                theRoll.setNumberOfDice(1);

                std::string dSplit = "";
                for (size_t i = 1; i < length; i++)
                    dSplit = dSplit + token[i];

                theRoll.setDieSize(boost::lexical_cast<short>(dSplit));
            }
            else {
                std::string token_split;
                char delimiter = 'd';
                size_t last = 0, next = 0;

                // parses through the string to find 'd', then splits into two tokens.
                while((next = token.find(delimiter, last)) != std::string::npos) {
                    token_split = token.substr(last, next - last);
                    last = next + 1;
                    theRoll.setNumberOfDice(boost::lexical_cast<short>(token_split));
                }

                token_split = token.substr(last);
                theRoll.setDieSize(boost::lexical_cast<short>(token_split));
            }
        }

        // Used to determine if the modifier is additive or subtractive, and
        // loads it into the arithmetic field.
        if (parse_input == 2) {
            if (token[0] == '+' || token[0] == '-')
                theRoll.setArithmetic(token[0]);
            // There's no modifier, so set the damage type.
            else
                parse_input = 4;
        }

        // Loads the modifier into the class modifier field.
        if (parse_input == 3) {
            size_t length = token.length();
            theRoll.setModifier(boost::lexical_cast<short>(token));
        }

        // Loads the damage type into the damage_type field, ensuring
        // the string is properly formatted using ASCII arithmetic.
        if (parse_input == 4) {
            size_t length = token.length();

            for (size_t i = 0; i < length; i++) {
                // If the first letter is lowercase, change to uppercase
                if ((i == 0 && int(token[i]) < 123) && int(token[i]) > 96)
                    token[i] = token[i] - 32;
                // Change the rest to lowercase
                if ((i != 0 && int(token[i]) < 91) && int(token[i]) > 64)
                    token[i] = token[i] + 32;
            }
            theRoll.setDamageType(token);
        }
        parse_input++;
    }
    return theRoll;
}

#endif