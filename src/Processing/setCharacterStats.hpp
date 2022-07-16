#ifndef SET_CHARACTER_STATS_
#define SET_CHARACTER_STATS_

#include <iostream>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include "../characterInfo/characterInfo.hpp"
#include "../../lib/NamedConstants.hpp"

/**
 * @brief Reads a character from an input file and loads the data into the character class.
 *
 * @param character
 * @return characterInfo
 *
 */
characterInfo setCharacterStats(characterInfo character) {
    std::string data;
	std::ifstream input;
    input.open("../data/Character.txt");

    std::string name, className;
    short a, b, c, d, e = 0;
    short command = CharacterName;

    while (getline(input, data)) {
        // ignores comments and blank lines
        if (data[0] != '#' && data != "") {
            switch(command) {
                case CharacterName:
                    name = data;
                    break;
                case Class:
                    className = data;
                    break;
                case Level:
                    character.setCharacterInfo(name, className, stof(data));
                    break;
                case Strength:
                    a = boost::lexical_cast<short>(data);
                    break;
                case Dexterity:
                    b = boost::lexical_cast<short>(data);
                    break;
                case Constitution:
                    c = boost::lexical_cast<short>(data);
                    break;
                case Intelligence:
                    d = boost::lexical_cast<short>(data);
                    break;
                case Wisdom:
                    e = boost::lexical_cast<short>(data);
                    break;
                case Charisma:
                    character.setAbilityScores(a, b, c, d, e, boost::lexical_cast<short>(data));
                    break;
                case StrengthSave:
                    a = boost::lexical_cast<short>(data);
                    break;
                case DexteritySave:
                    b = boost::lexical_cast<short>(data);
                    break;
                case ConstitutionSave:
                    c = boost::lexical_cast<short>(data);
                    break;
                case IntelligenceSave:
                    d = boost::lexical_cast<short>(data);
                    break;
                case WisdomSave:
                    e = boost::lexical_cast<short>(data);
                    break;
                case CharismaSave:
                    character.setSavingThrows(a, b, c, d, e, boost::lexical_cast<short>(data));
                    break;
                case Athletics:
                    character.setStrengthSkills(stoi(data));
                    break;
                case Initiative:
                    a = boost::lexical_cast<short>(data);
                    break;
                case Acrobatics:
                    b = boost::lexical_cast<short>(data);
                    break;
                case SleightOfHand:
                    c = boost::lexical_cast<short>(data);
                    break;
                case Stealth:
                    character.setDexteritySkills(a, b, c, boost::lexical_cast<short>(data));
                    break;
                case Arcana:
                    a = boost::lexical_cast<short>(data);
                    break;
                case History:
                    b = boost::lexical_cast<short>(data);
                    break;
                case Investigation:
                    c = boost::lexical_cast<short>(data);
                    break;
                case Nature:
                    d = boost::lexical_cast<short>(data);
                    break;
                case Religion:
                    character.setIntelligenceSkills(a, b, c, d, boost::lexical_cast<short>(data));
                    break;
                case AnimalHandling:
                    a = boost::lexical_cast<short>(data);
                    break;
                case Insight:
                    b = boost::lexical_cast<short>(data);
                    break;
                case Medicine:
                    c = boost::lexical_cast<short>(data);
                    break;
                case Perception:
                    d = boost::lexical_cast<short>(data);
                    break;
                case Survival:
                    character.setWisdomSkills(a, b, c, d, boost::lexical_cast<short>(data));
                    break;
                case Deception:
                    a = boost::lexical_cast<short>(data);
                    break;
                case Intimidation:
                    b = boost::lexical_cast<short>(data);
                    break;
                case Performance:
                    c = boost::lexical_cast<short>(data);
                    break;
                case Persuasion:
                    character.setCharismaSkills(a, b, c, boost::lexical_cast<short>(data));
                    break;
            }
            command++;
        }
    }
    input.close();
    return character;
}
#endif