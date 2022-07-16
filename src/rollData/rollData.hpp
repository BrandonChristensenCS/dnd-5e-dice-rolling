#ifndef ROLL_DATA_
#define ROLL_DATA_

#include <string>

class rollData {
    public:
        rollData();
        short getNumberOfDice() const;
        short getDieSize() const;
        short getModifier() const;
        char getArithmetic() const;
        std::string getDamageType() const;
        void setNumberOfDice(short);
        void setDieSize(short);
        void setArithmetic(char);
        void setModifier(short);
        void setDamageType(std::string);
    private:
        short number_of_dice;
        short die_size;
        char arithmetic;
        short modifier;
        std::string damage_type;
};

// Constructor
rollData::rollData() {}

// Getter Functions
short rollData::getNumberOfDice() const {
    return number_of_dice;
}
short rollData::getDieSize() const {
    return die_size;
}
char rollData::getArithmetic() const {
    return arithmetic;
}
short rollData::getModifier() const {
    return modifier;
}
std::string rollData::getDamageType() const {
    return damage_type;
}

// Setter Functions
void rollData::setNumberOfDice(short num) {
    number_of_dice = num;
}
void rollData::setDieSize(short size) {
    die_size = size;
}
void rollData::setArithmetic(char arth) {
    arithmetic = arth;
}
void rollData::setModifier(short mod) {
    modifier = mod;
}
void rollData::setDamageType(std::string dt) {
    damage_type = dt;
}

#endif