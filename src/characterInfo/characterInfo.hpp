#ifndef CHARACTER_INFO_
#define CHARACTER_INFO_

#include <string>
#include <cmath>

class characterInfo {
    public:
        characterInfo();
        std::string getCharacterName() const;
        std::string getCharacterClass() const;
        float getCharacterLevel() const;
        short getProficiencyBonus() const;
        short getHitDiceSize() const;
        short getStrengthScore() const;
        short getDexterityScore() const;
        short getConstitutionScore() const;
        short getIntelligenceScore() const;
        short getWisdomScore() const;
        short getCharismaScore() const;
        short getStrengthModifier() const;
        short getDexterityModifier() const;
        short getConstitutionModifier() const;
        short getIntelligenceModifier() const;
        short getWisdomModifier() const;
        short getCharismaModifier() const;
        short getStrengthSave() const;
        short getDexteritySave() const;
        short getConstitutionSave() const;
        short getIntelligenceSave() const;
        short getWisdomSave() const;
        short getCharismaSave() const;
        short getAthletics() const;
        short getInitiative() const;
        short getAcrobatics() const;
        short getSleightOfHand() const;
        short getStealth() const;
        short getArcana() const;
        short getHistory() const;
        short getInvestigation() const;
        short getNature() const;
        short getReligion() const;
        short getAnimalHandling() const;
        short getInsight() const;
        short getMedicine() const;
        short getPerception() const;
        short getSurvival() const;
        short getDeception() const;
        short getIntimidation() const;
        short getPerformance() const;
        short getPersuasion() const;
        short getPassivePerception() const;
        short getPassiveInsight() const;
        short getPassiveInvestigation() const;
        void setCharacterInfo(std::string, std::string, float);
        void setAbilityScores(short, short, short, short, short, short);
        void setSavingThrows(bool, bool, bool, bool, bool, bool);
        void setStrengthSkills(short);
        void setDexteritySkills(short, short, short, short);
        void setIntelligenceSkills(short, short, short, short, short);
        void setWisdomSkills(short, short, short, short, short);
        void setCharismaSkills(short, short, short, short);

    private:
        std::string characterName;
        std::string characterClass;
        float characterLevel;
        short proficiencyBonus;
        short hitDiceCount;
        short hitDiceSize;
        short strengthScore;
        short dexterityScore;
        short constitutionScore;
        short intelligenceScore;
        short wisdomScore;
        short charismaScore;
        short strengthModifier;
        short dexterityModifier;
        short constitutionModifier;
        short intelligenceModifier;
        short wisdomModifier;
        short charismaModifier;
        short strengthSaveModifier;
        short dexteritySaveModifier;
        short constitutionSaveModifier;
        short intelligenceSaveModifier;
        short wisdomSaveModifier;
        short charismaSaveModifier;
        bool strengthSaveProficiency;
        bool dexteritySaveProficiency;
        bool constitutionSaveProficiency;
        bool intelligenceSaveProficiency;
        bool wisdomSaveProficiency;
        bool charismaSaveProficiency;
        short athleticsProf;
        short initiativeProf;
        short acrobaticsProf;
        short sleightOfHandProf;
        short stealthProf;
        short arcanaProf;
        short historyProf;
        short investigationProf;
        short natureProf;
        short religionProf;
        short animalHandlingProf;
        short insightProf;
        short medicineProf;
        short perceptionProf;
        short survivalProf;
        short deceptionProf;
        short intimidationProf;
        short performanceProf;
        short persuasionProf;
        short passivePerception;
        short passiveInsight;
        short passiveInvestigation;
};

// Constructor
characterInfo::characterInfo() {}

/**
 *
 *  Getter Functions
 *
 **/

// Character Info
std::string characterInfo::getCharacterName() const {
    return characterName;
}
std::string characterInfo::getCharacterClass() const {
    return characterClass;
}
float characterInfo::getCharacterLevel() const {
    return characterLevel;
}
short characterInfo::getProficiencyBonus() const {
    return proficiencyBonus;
}
short characterInfo::getHitDiceSize() const {
    return hitDiceSize;
}

// Raw Ability Scores
short characterInfo::getStrengthScore() const {
    return strengthScore;
}
short characterInfo::getDexterityScore() const {
    return dexterityScore;
}
short characterInfo::getConstitutionScore() const {
    return constitutionScore;
}
short characterInfo::getIntelligenceScore() const {
    return intelligenceScore;
}
short characterInfo::getWisdomScore() const {
    return wisdomScore;
}
short characterInfo::getCharismaScore() const {
    return charismaScore;
}

// Ability Score Modifiers
short characterInfo::getStrengthModifier() const {
    return strengthModifier;
}
short characterInfo::getDexterityModifier() const {
    return dexterityModifier;
}
short characterInfo::getConstitutionModifier() const {
    return constitutionModifier;
}
short characterInfo::getIntelligenceModifier() const {
    return intelligenceModifier;
}
short characterInfo::getWisdomModifier() const {
    return wisdomModifier;
}
short characterInfo::getCharismaModifier() const {
    return charismaModifier;
}

// Saving Throw Modifiers
short characterInfo::getStrengthSave() const {
    return strengthSaveModifier;
}
short characterInfo::getDexteritySave() const {
    return dexteritySaveModifier;
}
short characterInfo::getConstitutionSave() const {
    return constitutionSaveModifier;
}
short characterInfo::getIntelligenceSave() const {
    return intelligenceSaveModifier;
}
short characterInfo::getWisdomSave() const {
    return wisdomSaveModifier;
}
short characterInfo::getCharismaSave() const {
    return charismaSaveModifier;
}

/**
 *  Skill Modifiers
**/

// Strength Skill
short characterInfo::getAthletics() const {
    if (athleticsProf == 0)
        return strengthModifier;
    if (athleticsProf == 1)
        return strengthModifier + proficiencyBonus;
    if (athleticsProf == 2)
        return strengthModifier + (2 * proficiencyBonus);

    return -1;
}

// Dexterity Skills
short characterInfo::getInitiative() const {
    if (initiativeProf == 0)
        return dexterityModifier;
    if (initiativeProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (initiativeProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getAcrobatics() const {
    if (acrobaticsProf == 0)
        return dexterityModifier;
    if (acrobaticsProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (acrobaticsProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getSleightOfHand() const {
    if (sleightOfHandProf == 0)
        return dexterityModifier;
    if (sleightOfHandProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (sleightOfHandProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getStealth() const {
    if (stealthProf == 0)
        return dexterityModifier;
    if (stealthProf == 1)
        return dexterityModifier + proficiencyBonus;
    if (stealthProf == 2)
        return dexterityModifier + (2 * proficiencyBonus);

    return -1;
}

// Intelligence Skills
short characterInfo::getArcana() const {
    if (arcanaProf == 0)
        return intelligenceModifier;
    if (arcanaProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (arcanaProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getHistory() const {
    if (historyProf == 0)
        return intelligenceModifier;
    if (historyProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (historyProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getInvestigation() const {
    if (investigationProf == 0)
        return intelligenceModifier;
    if (investigationProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (investigationProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getNature() const {
    if (natureProf == 0)
        return intelligenceModifier;
    if (natureProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (natureProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getReligion() const {
    if (religionProf == 0)
        return intelligenceModifier;
    if (religionProf == 1)
        return intelligenceModifier + proficiencyBonus;
    if (religionProf == 2)
        return intelligenceModifier + (2 * proficiencyBonus);

    return -1;
}

// Wisdom Skills
short characterInfo::getAnimalHandling() const {
    if (animalHandlingProf == 0)
        return wisdomModifier;
    if (animalHandlingProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (animalHandlingProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getInsight() const {
    if (insightProf == 0)
        return wisdomModifier;
    if (insightProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (insightProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getMedicine() const {
    if (medicineProf == 0)
        return wisdomModifier;
    if (medicineProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (medicineProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getPerception() const {
    if (perceptionProf == 0)
        return wisdomModifier;
    if (perceptionProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (perceptionProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getSurvival() const {
    if (survivalProf == 0)
        return wisdomModifier;
    if (survivalProf == 1)
        return wisdomModifier + proficiencyBonus;
    if (survivalProf == 2)
        return wisdomModifier + (2 * proficiencyBonus);

    return -1;
}

// Charisma Skills
short characterInfo::getDeception() const {
    if (deceptionProf == 0)
        return charismaModifier;
    if (deceptionProf == 1)
        return charismaModifier + proficiencyBonus;
    if (deceptionProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getIntimidation() const {
    if (intimidationProf == 0)
        return charismaModifier;
    if (intimidationProf == 1)
        return charismaModifier + proficiencyBonus;
    if (intimidationProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getPerformance() const {
    if (performanceProf == 0)
        return charismaModifier;
    if (performanceProf == 1)
        return charismaModifier + proficiencyBonus;
    if (performanceProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}
short characterInfo::getPersuasion() const {
    if (persuasionProf == 0)
        return charismaModifier;
    if (persuasionProf == 1)
        return charismaModifier + proficiencyBonus;
    if (persuasionProf == 2)
        return charismaModifier + (2 * proficiencyBonus);

    return -1;
}

// Passive Skills
short characterInfo::getPassivePerception() const {
    return 10 + getPerception();
}
short characterInfo::getPassiveInsight() const {
    return 10 + getInsight();
}
short characterInfo::getPassiveInvestigation() const {
    return 10 + getInvestigation();
}

/**
 *
 *  Setter Functions
 *
 **/

// Sets the character's name, class, level, proficiency bonus,
// and the hit dice data which is based on their class.
void characterInfo::setCharacterInfo(std::string name, std::string className, float level) {
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
void characterInfo::setAbilityScores(short STR_, short DEX_, short CON_, short INT_, short WIS_, short CHA_) {
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
void characterInfo::setStrengthSkills(short athletics) {
    athleticsProf = athletics;
}
void characterInfo::setDexteritySkills(short initiative, short acrobatics, short sleight, short stealth) {
    initiativeProf = initiative;
    acrobaticsProf = acrobatics;
    sleightOfHandProf = sleight;
    stealthProf = stealth;
}
void characterInfo::setIntelligenceSkills(short arcana, short history, short investigation, short nature, short religion) {
    arcanaProf = arcana;
    historyProf = history;
    investigationProf = investigation;
    natureProf = nature;
    religionProf = religion;
}
void characterInfo::setWisdomSkills(short animalHand, short insight, short medicine, short perception, short survival) {
    animalHandlingProf = animalHand;
    insightProf = insight;
    medicineProf = medicine;
    perceptionProf = perception;
    survivalProf = survival;
}
void characterInfo::setCharismaSkills(short deception, short intimidation, short performance, short persuasion) {
    deceptionProf = deception;
    intimidationProf = intimidation;
    performanceProf = performance;
    persuasionProf = persuasion;
}

#endif