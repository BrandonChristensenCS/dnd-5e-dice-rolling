#ifndef GENERATE_ROLL_
#define GENERATE_ROLL_

#include <random>
#include <chrono>

/**
 * @brief Rolls diceSize-sided die diceCount number of times
 *
 * @param diceCount
 * @param diceSize
 * @return short
 *
 */
short generateRoll(short diceCount, short diceSize) {
    // Generate a psuedo-random seed based on the system clock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Set the range from 1 to the size of the die
    std::uniform_int_distribution<short> distribution(1, diceSize);

    // If there are multiple dice to be rolled, add them all together (e.g. 8d6)
    short total = 0;
    for (short i = 0; i < diceCount; i++)
        total = total + distribution(generator);

    return total;
}

#endif