#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <chrono>
#include "rollData.h"

#define MAX 100

using namespace std;

void rollNewCharacter(rollData[], int);
void outputResults(rollData[], int, int);
int process_input(rollData[], string);

int main() {

    string user_input;
    cout << "Enter your roll: ";
    getline(cin, user_input);
    cout << endl;

    string command;
    istringstream iss(user_input);
    getline(iss, command, ' ');

    int actions = 0;
    rollData theRoll[MAX];

    // generates a pseudo-random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    // rolls 4d4 six times dropping the lowest d6 on each one,
    // then it outputs the results of the highest 3d6, then
    // adds up the sum of all six and outputs it.
    if (command == "/newcharacter") {

        // Stores 4d6 into the class fields
        rollNewCharacter(theRoll, 6);

        int rollTotal = 0;
        int storedRolls[4];
        int abilityScores[6];

        // runs this 6 times for each ability score:
        // Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
        for (int i = 0; i < 6; i++) {
            int lowestRoll, index;
            bool flag = false;
            rollTotal = 0;

            // generates 4 random numbers from (1, 6) dropping the lowest roll
            for (int j = 0; j < theRoll[i].getNumberOfDice(); j++) {

                // generates a random number from 1 to 6
                uniform_int_distribution<int> distribution(1, theRoll[i].getDieSize());
                storedRolls[j] = distribution(generator);

                // sets the first number as the lowest
                if (flag == false) {
                    flag = true;
                    lowestRoll = storedRolls[j];
                    index = j;
                }
                // determines the lowest roll and the index it's at in the array
                if (storedRolls[j] < lowestRoll) {
                    lowestRoll = storedRolls[j];
                    index = j;
                }
            }

            // adds up the three highest d6 rolls and saves it as an ability score
            for (int j = 0; j < theRoll[i].getNumberOfDice(); j++) {
                if (j != index)
                    rollTotal = rollTotal + storedRolls[j];
            }
            abilityScores[i] = rollTotal;
        }

        rollTotal = 0;

        // outputs each of the 6 ability scores and adds them up.
        cout << endl << "Your Ability Scores: [";
        for (int i = 0; i < 5; i++) {
            rollTotal = rollTotal + abilityScores[i];
            cout << abilityScores[i] << " ";
        }
        rollTotal = rollTotal + abilityScores[5];
        cout << abilityScores[5] << "]" << endl;

        cout << "The total value of your ability scores is " << rollTotal << "." << endl << endl;
    }

    // Handles standard rolls like: 2d6 + 5 Slashing or 3d6, etc.
    if (command == "/roll") {
        actions = process_input(theRoll, user_input);

        // if there was an input error, terminate.
        if (actions == -1)
            return 0;

        // generates a random number from (1, dieSize)
        uniform_int_distribution<int> distribution(1, theRoll[actions].getDieSize());

        int storedRolls[MAX];
        int rollTotal = 0;

        cout << "[";
        for (int i = 0; i < theRoll[actions].getNumberOfDice() - 1; i++) {
            storedRolls[i] = distribution(generator);
            rollTotal = rollTotal + storedRolls[i];
            cout << storedRolls[i] << " ";
        }
        storedRolls[theRoll[actions].getNumberOfDice() - 1] = distribution(generator);
        rollTotal = rollTotal + storedRolls[theRoll[actions].getNumberOfDice() - 1];

        cout << storedRolls[theRoll[actions].getNumberOfDice() - 1] << "]" << endl;

        // Outputs the result of the RNG roll and the expected average for the roll.
        outputResults(theRoll, rollTotal, actions);
    }
    return 0;
}

// Loads 4d6 six times into the class fields.
void rollNewCharacter(rollData theRoll[], int n) {

    for (int i = 0; i < n; i++) {
        theRoll[i].setNumberOfDice(4);
        theRoll[i].setDieSize(6);
    }
}

// Outputs the result of the RNG roll and the expected average for the roll
void outputResults(rollData theRoll[], int rollTotal, int actions) {

    // When the modifier is additive.
    if (theRoll[actions].getArithmetic() == "+") {
        if (theRoll[actions].getDamageType() != "") {
            cout << "Your Roll = " << rollTotal + theRoll[actions].getModifier() <<
                " " << theRoll[actions].getDamageType() << endl;

            // Adds 0.5 to the average if the number of dice is odd
            if ((theRoll[actions].getNumberOfDice() % 2) == 0)
                cout << "Average = " << (theRoll[actions].getDieSize() / 2) * theRoll[actions].getNumberOfDice()
                    + theRoll[actions].getModifier() << " " << theRoll[actions].getDamageType() << endl;
            else
                cout << "Average = " << (((theRoll[actions].getDieSize() / 2) + 0.5) * theRoll[actions].getNumberOfDice()
                    + theRoll[actions].getModifier()) + 0.5 << " " << theRoll[actions].getDamageType() << endl;

        }
        if (theRoll[actions].getDamageType() == "") {
            cout << "Your Roll = " << rollTotal + theRoll[actions].getModifier() << endl;

            // Adds 0.5 to the average if the number of dice is odd
            if ((theRoll[actions].getNumberOfDice() % 2) == 0)
                cout << "Average = " << (theRoll[actions].getDieSize() / 2) * theRoll[actions].getNumberOfDice()
                    + theRoll[actions].getModifier() << endl;
            else
                cout << "Average = " << (((theRoll[actions].getDieSize() / 2) + 0.5) * theRoll[actions].getNumberOfDice()
                    + theRoll[actions].getModifier()) + 0.5 << endl;
        }
    }
    // When the modifier is subtractive.
    if (theRoll[actions].getArithmetic() == "-") {
        if (theRoll[actions].getDamageType() != "") {
            cout << "Your Roll = " << rollTotal - theRoll[actions].getModifier() <<
                " " << theRoll[actions].getDamageType() << endl;

            // Adds 0.5 to the average if the number of dice is odd
            if ((theRoll[actions].getNumberOfDice() % 2) == 0)
                cout << "Average = " << (theRoll[actions].getDieSize() / 2) * theRoll[actions].getNumberOfDice()
                    - theRoll[actions].getModifier() << " " << theRoll[actions].getDamageType() << endl;
            else
                cout << "Average = " << (((theRoll[actions].getDieSize() / 2) + 0.5) * theRoll[actions].getNumberOfDice()
                    - theRoll[actions].getModifier()) + 0.5 << " " << theRoll[actions].getDamageType() << endl;

        }
        if (theRoll[actions].getDamageType() == "") {
            cout << "Your Roll = " << rollTotal - theRoll[actions].getModifier() << endl;

            // Adds 0.5 to the average if the number of dice is odd
            if ((theRoll[actions].getNumberOfDice() % 2) == 0)
                cout << "Average = " << (theRoll[actions].getDieSize() / 2) * theRoll[actions].getNumberOfDice()
                    - theRoll[actions].getModifier() << endl;
            else
                cout << "Average = " << (((theRoll[actions].getDieSize() / 2) + 0.5) * theRoll[actions].getNumberOfDice()
                    - theRoll[actions].getModifier()) + 0.5 << endl;
        }
    }

    // handles rolls without a modifier or a damage type
    if (theRoll[actions].getArithmetic() == "") {
        cout << "Your Roll = " << rollTotal << endl;

        if ((theRoll[actions].getNumberOfDice() % 2) == 0)
            cout << "Average = " << (theRoll[actions].getDieSize() / 2) * theRoll[actions].getNumberOfDice() << endl;
        else
            cout << "Average = " << (((theRoll[actions].getDieSize() / 2) + 0.5) * theRoll[actions].getNumberOfDice()) + 0.5 << endl;
    }
}

// used for the command '/roll', loads the appropritate data into the class fields
int process_input(rollData theRoll[], string data) {
    string token;
    istringstream iss(data);

    static int actions = 0;
    actions++;
    int parse_input = 0;

    while(getline(iss, token, ' ')) {

        // parse_input == 0 is ignored since it just contains the command (such as /roll)

        // Splits up the dice count and size of dice, and loads them into the
        // number_of_dice and die_size fields. (ex. 12d10 gets split into 12 and 10)
        if (parse_input == 1) {
            size_t last = 0, next = 0, length = token.length();
            string delimiter = "d";

            bool flag = false;
            // checks for format 12d10, if the 'd' isn't found, throw an error.
            for (size_t i = 0; i < length; i++) {
                if (token[i] == 'd')
                    flag = true;
            }
            if (flag == false) {
                cout << "Error: expected a 'd' between dice count and die size, but got '"
                    << token << "'." << endl;
                return -1;
            }

            string token_split;
            // parses through the string to find 'd', then splits into two tokens.
            while((next = token.find(delimiter, last)) != std::string::npos) {
                token_split = token.substr(last, next - last);
                last = next + 1;
                theRoll[actions].setNumberOfDice(stoi(token_split));
            }
            token_split = token.substr(last);
            theRoll[actions].setDieSize(stoi(token_split));
        }

        // Used to determine if the modifier is additive or subtractive, and
        // loads it into the arithmetic field.
        if (parse_input == 2) {
            if (token == "+" || token == "-")
                theRoll[actions].setArithmetic(token);
            else { // Throw an Error if the input is not a '+' or a '-'
                cout << "ERROR: expected '+' or '-' but got '" << token << "'." << endl;
                return -1;
            }
        }

        // Loads the modifier into the class modifier field.
        if (parse_input == 3) {
            size_t length = token.length();

            // Throw an error if the modifier is not numeric
            for (size_t i = 0; i < length; i++) {
                if (int(token[i]) < 48 || int(token[i]) > 57) {
                    cout << "Error: expected a numeric value for the modifer '"
                        << token << "'." << endl;
                    return -1;
                }
            }
            theRoll[actions].setModifier(stoi(token));
        }

        // Loads the damage type into the damage_type field, ensuring
        // the string is properly formatted using ASCII arithmetic.
        if (parse_input == 4) {
            size_t length = token.length();
            for (size_t i = 0; i < length; i++) {

                // If the first letter is lowercase, change to uppercase
                if ((i == 0 && int(token[i]) < 123) && int(token[i]) > 96) {
                    token[i] = token[i] - 32;
                }
                // Change the rest to lowercase
                if ((i != 0 && int(token[i]) < 91) && int(token[i]) > 64) {
                    token[i] = token[i] + 32;
                }
                // if the character is not alphabetical, throw an error.
                if ((int(token[i]) < 65 || int(token[i]) > 122)
                    || (int(token[i]) > 90 && int(token[i]) < 97)) {
                        cout << "ERROR: expected alphabetical character but got '"
                            << token[i] << "' for input '" << token << "'." << endl;
                        return -1;
                }
            }
            theRoll[actions].setDamageType(token);
        }
        parse_input++;
    }
    return actions;
}