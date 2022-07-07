#include "characterInfo.h"
#include <string>
#include <cmath>

using namespace std;

// Constructor
characterInfo::characterInfo() {}

/**
 *
 *  Getter Functions
 *
 **/

// Character Info
string characterInfo::getCharacterName() const {
    return characterName;
}
string characterInfo::getCharacterClass() const {
    return characterClass;
}
int characterInfo::getCharacterLevel() const {
    return characterLevel;
}
int characterInfo::getProficiencyBonus() const {
    return proficiencyBonus;
}

// Raw Ability Scores
int characterInfo::getStrengthScore() const {
    return strengthScore;
}
int characterInfo::getDexterityScore() const {
    return dexterityScore;
}
int characterInfo::getConstitutionScore() const {
    return constitutionScore;
}
int characterInfo::getIntelligenceScore() const {
    return intelligenceScore;
}
int characterInfo::getWisdomScore() const {
    return wisdomScore;
}
int characterInfo::getCharismaScore() const {
    return charismaScore;
}

// Ability Score Modifiers
int characterInfo::getStrengthModifier() const {
    return strengthModifier;
}
int characterInfo::getDexterityModifier() const {
    return dexterityModifier;
}
int characterInfo::getConstitutionModifier() const {
    return constitutionModifier;
}
int characterInfo::getIntelligenceModifier() const {
    return intelligenceModifier;
}
int characterInfo::getWisdomModifier() const {
    return wisdomModifier;
}
int characterInfo::getCharismaModifier() const {
    return charismaModifier;
}

// Saving Throw Modifiers
int characterInfo::getStrengthSave() const {
    return strengthSaveModifier;
}
int characterInfo::getDexteritySave() const {
    return dexteritySaveModifier;
}
int characterInfo::getConstitutionSave() const {
    return constitutionSaveModifier;
}
int characterInfo::getIntelligenceSave() const {
    return intelligenceSaveModifier;
}
int characterInfo::getWisdomSave() const {
    return wisdomSaveModifier;
}
int characterInfo::getCharismaSave() const {
    return charismaSaveModifier;
}

/**
 *  Skill Modifiers
**/

// Strength Skill
int characterInfo::getAthletics() const {
    if (athleticsProf == 0)
        return strengthModifier;
    if (athleticsProf == 1)
        return strengthModifier + proficiencyBonus;
    if (athleticsProf == 2)
        return strengthModifier + (2 * proficiencyBonus);

    return -1;
}

// Dexterity Skills
int characterInfo::getInitiative() const {
    if (initiativeProf == 0)
        return dexterityModifier;
    if (initiativeProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (initiativeProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getAcrobatics() const {
    if (acrobaticsProf == 0)
        return dexterityModifier;
    if (acrobaticsProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (acrobaticsProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getSleightOfHand() const {
    if (sleightOfHandProf == 0)
        return dexterityModifier;
    if (sleightOfHandProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (sleightOfHandProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getStealth() const {
    if (stealthProf == 0)
        return dexterityModifier;
    if (stealthProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (stealthProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}

// Intelligence Skills
int characterInfo::getArcana() const {
    if (arcanaProf == 0)
        return intelligenceModifier;
    if (arcanaProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (arcanaProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getHistory() const {
    if (historyProf == 0)
        return intelligenceModifier;
    if (historyProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (historyProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getInvestigation() const {
    if (investigationProf == 0)
        return intelligenceModifier;
    if (investigationProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (investigationProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getNature() const {
    if (natureProf == 0)
        return intelligenceModifier;
    if (natureProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (natureProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getReligion() const {
    if (religionProf == 0)
        return intelligenceModifier;
    if (religionProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (religionProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}

// Wisdom Skills
int characterInfo::getAnimalHandling() const {
    if (animalHandlingProf == 0)
        return wisdomModifier;
    if (animalHandlingProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (animalHandlingProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getInsight() const {
    if (insightProf == 0)
        return wisdomModifier;
    if (insightProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (insightProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getMedicine() const {
    if (medicineProf == 0)
        return wisdomModifier;
    if (medicineProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (medicineProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getPerception() const {
    if (perceptionProf == 0)
        return wisdomModifier;
    if (perceptionProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (perceptionProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getSurvival() const {
    if (survivalProf == 0)
        return wisdomModifier;
    if (survivalProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (survivalProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}

// Charisma Skills
int characterInfo::getDeception() const {
    if (deceptionProf == 0)
        return charismaModifier;
    if (deceptionProf == 1)
        return charismaModifier + proficiencyBonus;
    if (deceptionProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getIntimidation() const {
    if (intimidationProf == 0)
        return charismaModifier;
    if (intimidationProf == 1)
        return charismaModifier + proficiencyBonus;
    if (intimidationProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getPerformance() const {
    if (performanceProf == 0)
        return charismaModifier;
    if (performanceProf == 1)
        return charismaModifier + proficiencyBonus;
    if (performanceProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}
int characterInfo::getPersuasion() const {
    if (persuasionProf == 0)
        return charismaModifier;
    if (persuasionProf == 1)
        return charismaModifier + proficiencyBonus;
    if (persuasionProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}

// Passive Skills
int characterInfo::getPassivePerception() const {
    return 10 + getPerception();
}
int characterInfo::getPassiveInsight() const {
    return 10 + getInsight();
}
int characterInfo::getPassiveInvestigation() const {
    return 10 + getInvestigation();
}

/**
 *
 *  Setter Functions
 *
 **/

// Sets the character's name, class, level, proficiency bonus,
// and the hit dice data which is based on their class.
void characterInfo::setCharacterInfo(string name, string className, int level) {
    characterName = name;
    characterClass = className;
    characterLevel = level;

    // Sets the Proficiency Bonus
    proficiencyBonus = ceil(1 + (level / 4));

    // Sets the number of Hit Dice
    hitDiceCount = level;

    // Sets the size of the Hit Dice
    if (className == "Sorcerer" || className == "Wizard")
        hitDiceSize = 6;
    if (className == "Bard" || className == "Cleric" || className == "Druid" || className == "Monk"
        || className == "Rogue" || className == "Warlock" || className == "Artificer")
        hitDiceSize = 8;
    if (className == "Fighter" || className == "Paladin" || className == "Ranger" || className == "Blood Hunter")
        hitDiceSize = 10;
    if (className == "Barbarian")
        hitDiceSize = 12;
}

// Sets the characters ability scores and modifiers, and sets the initial
// saving throw modifier, which will be modified in setSavingThrows based on
// their saving throw proficiencies.
void characterInfo::setAbilityScores(int STR_, int DEX_, int CON_, int INT_, int WIS_, int CHA_) {
    strengthScore = STR_;
    dexterityScore = DEX_;
    constitutionScore = CON_;
    intelligenceScore = INT_;
    wisdomScore = WIS_;
    charismaScore = CHA_;

    strengthModifier = floor((STR_ - 10) / 2);
    dexterityModifier = floor((DEX_ - 10) / 2);
    constitutionModifier = floor((CON_ - 10) / 2);
    intelligenceModifier = floor((INT_ - 10) / 2);
    wisdomModifier = floor((WIS_ - 10) / 2);
    charismaModifier = floor((CHA_ - 10) / 2);
}

// Sets the saving throw modifiers based on proficiencies
void characterInfo::setSavingThrows(bool STR_, bool DEX_, bool CON_, bool INT_, bool WIS_, bool CHA_) {
    if (STR_ == true)
        strengthSaveModifier = strengthModifier + proficiencyBonus;
    else
        strengthSaveModifier = strengthModifier;

    if (DEX_ == true)
        dexteritySaveModifier = dexterityModifier + proficiencyBonus;
    else
        dexteritySaveModifier = dexterityModifier;

    if (CON_ == true)
        constitutionSaveModifier = constitutionModifier + proficiencyBonus;
    else
        constitutionSaveModifier = constitutionModifier;

    if (INT_ == true)
        intelligenceSaveModifier = intelligenceModifier + proficiencyBonus;
    else
        intelligenceSaveModifier = intelligenceModifier;

    if (WIS_ == true)
        wisdomSaveModifier = wisdomModifier + proficiencyBonus;
    else
        wisdomSaveModifier = wisdomModifier;

    if (CHA_ == true)
        charismaSaveModifier = charismaModifier + proficiencyBonus;
    else
        charismaSaveModifier = charismaModifier;
}

// Sets skill proficiencies to be used in the getter functions.
void characterInfo::setStrengthSkills(int athletics) {
    athleticsProf = athletics;
}
void characterInfo::setDexteritySkills(int initiative, int acrobatics, int sleight, int stealth) {
    initiativeProf = initiative;
    acrobaticsProf = acrobatics;
    sleightOfHandProf = sleight;
    stealthProf = stealth;
}
void characterInfo::setIntelligenceSkills(int arcana, int history, int investigation, int nature, int religion) {
    arcanaProf = arcana;
    historyProf = history;
    investigationProf = investigation;
    natureProf = nature;
    religionProf = religion;
}
void characterInfo::setWisdomSkills(int animalHand, int insight, int medicine, int perception, int survival) {
    animalHandlingProf = animalHand;
    insightProf = insight;
    medicineProf = medicine;
    perceptionProf = perception;
    survivalProf = survival;
}
void characterInfo::setCharismaSkills(int deception, int intimidation, int performance, int persuasion) {
    deceptionProf = deception;
    intimidationProf = intimidation;
    performanceProf = performance;
    persuasionProf = persuasion;
}