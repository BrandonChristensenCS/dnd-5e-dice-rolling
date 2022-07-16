#ifndef ROLL_NEW_CHARACTER_
#define ROLL_NEW_CHARACTER_

#include <iostream>
#include <chrono>
#include <random>
#include "generateRoll.hpp"

/**
 * @brief Generates all six ability scores by rolling 4d6 for
 * each one, dropping the lowest 1d6. Then adds them all together
 * and outputs the result of each 3d6 and the total value of the 18d6.
 *
 */
void rollNewCharacter() {
    // Generate a pseudo-random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    short rollTotal = 0;
    short storedRolls[4];
    short abilityScores[6];

    // runs this 6 times for each ability score:
    // Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    for (short i = 0; i < 6; i++) {
        short lowestRoll, index;
        bool flag = false;
        rollTotal = 0;

        // generates 4 random numbers from (1, 6) dropping the lowest roll
        for (short j = 0; j < 4; j++) {
            std::uniform_int_distribution<short> distribution(1, 6);
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
        for (short j = 0; j < 4; j++) {
            if (j != index)
                rollTotal = rollTotal + storedRolls[j];
        }
        abilityScores[i] = rollTotal;
    }
    rollTotal = 0;

    // outputs each of the 6 ability scores and adds them up.
    std::cout << std::endl << "Your Ability Scores: [";
    for (short i = 0; i < 5; i++) {
        rollTotal = rollTotal + abilityScores[i];
        std::cout << abilityScores[i] << " ";
    }
    rollTotal = rollTotal + abilityScores[5];

    std::cout << abilityScores[5] << "]" << std::endl;
    std::cout << "The total value of your ability scores is " << rollTotal
            << "." << std::endl << std::endl;
}

#endif