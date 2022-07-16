#ifndef NAMED_CONSTANTS_
#define NAMED_CONSTANTS_

#include <string>

#define NEWCHAR     "NewCharacter"
#define NAME        "CharacterName"
#define CLASS       "Class"
#define LVL         "Level"
#define STR         "Strength"
#define DEX         "Dexterity"
#define CON         "Constitution"
#define INT         "Intelligence"
#define WIS         "Wisdom"
#define CHA         "Charisma"
#define STRSAVE     "StrengthSave"
#define DEXSAVE     "DexteritySave"
#define CONSAVE     "ConstitutionSave"
#define INTSAVE     "IntelligenceSave"
#define WISSAVE     "WisdomSave"
#define CHASAVE     "CharismaSave"
#define ATHLETICS   "Athletics"
#define INITIATIVE  "Initiative"
#define ACROBATICS  "Acrobatics"
#define SLEIGHT     "SleightOfHand"
#define STEALTH     "Stealth"
#define ARCANA      "Arcana"
#define HISTORY     "History"
#define INVESTIGATE "Investigation"
#define NATURE      "Nature"
#define RELIGION    "Religion"
#define ANIMAL_HAND "AnimalHandling"
#define INSIGHT     "Insight"
#define MEDICINE    "Medicine"
#define PERCEPTION  "Perception"
#define SURVIVAL    "Survival"
#define DECEPTION   "Deception"
#define INTIMIDATE  "Intimidation"
#define PERFORMANCE "Performance"
#define PERSUASION  "Persuasion"
#define HITDICE     "HitDice"
#define DEATHSAVE   "DeathSave"
#define PASSPERCEPT "PassivePerception"
#define PASSINSIGHT "PassiveInsight"
#define PASSINVEST  "PassiveInvestigation"

// Used in setCharacterStats
enum Commands : short {
    CharacterName,
    Class,
    Level,
    Strength,
    Dexterity,
    Constitution,
    Intelligence,
    Wisdom,
    Charisma,
    StrengthSave,
    DexteritySave,
    ConstitutionSave,
    IntelligenceSave,
    WisdomSave,
    CharismaSave,
    Athletics,
    Initiative,
    Acrobatics,
    SleightOfHand,
    Stealth,
    Arcana,
    History,
    Investigation,
    Nature,
    Religion,
    AnimalHandling,
    Insight,
    Medicine,
    Perception,
    Survival,
    Deception,
    Intimidation,
    Performance,
    Persuasion,
    HitDice,
    DeathSave,
    PassivePerception,
    PassiveInsight,
    PassiveInvestigation
};

// Used in outputHelp()
const std::string RollNames[50] = {
    NAME, CLASS, LVL, STR, DEX, CON, INT,
    WIS, CHA, STRSAVE, DEXSAVE, CONSAVE,
    INTSAVE, WISSAVE, CHASAVE,
    ATHLETICS, INITIATIVE, ACROBATICS, SLEIGHT,
    STEALTH, ARCANA, HISTORY, INVESTIGATE,
    NATURE, RELIGION, ANIMAL_HAND, INSIGHT,
    MEDICINE, PERCEPTION, SURVIVAL, DECEPTION,
    INTIMIDATE, PERFORMANCE, PERSUASION, HITDICE,
    DEATHSAVE, PASSPERCEPT, PASSINSIGHT, PASSINVEST
};

#endif