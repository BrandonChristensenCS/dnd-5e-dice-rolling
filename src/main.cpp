#include "../lib/NamedConstants.hpp"
#include "rollData/rollData.hpp"
#include "characterInfo/characterInfo.hpp"
#include "Output/outputAdvantageRoll.hpp"
#include "Output/outputHelp.hpp"
#include "Output/outputSingleRoll.hpp"
#include "Processing/commandLoop.hpp"
#include "Processing/generateRoll.hpp"
#include "Processing/processRoll.hpp"
#include "Processing/rollNewCharacter.hpp"
#include "Processing/setCharacterStats.hpp"

// Driver Code
int main() {

    // Pulls character info from an input file and loads it into the characterInfo class.
    characterInfo character;
    character = setCharacterStats(character);

    // Continuously prompts the user for a command, and makes the appropriate
    // function call and/or roll. Returns when the user types 'terminate'.
    commandLoop(character);

    return 0;
}