#include "rollData.h"
#include <string>

using namespace std;

// Constructors
rollData::rollData() {
    number_of_dice = die_size = modifier = 0;
    arithmetic = damage_type = "";
}
rollData::rollData(int num, int size, string arth, int mod, string dt) {
    number_of_dice = num;
    die_size = size;
    arithmetic = arth;
    modifier = mod;
    damage_type = dt;
}

// Getter Functions
int rollData::getNumberOfDice() const {
    return number_of_dice;
}
int rollData::getDieSize() const {
    return die_size;
}
string rollData::getArithmetic() const {
    return arithmetic;
}
int rollData::getModifier() const {
    return modifier;
}
string rollData::getDamageType() const {
    return damage_type;
}

// Setter Functions
void rollData::setNumberOfDice(int num) {
    number_of_dice = num;
}
void rollData::setDieSize(int size) {
    die_size = size;
}
void rollData::setArithmetic(string arth) {
    arithmetic = arth;
}
void rollData::setModifier(int mod) {
    modifier = mod;
}
void rollData::setDamageType(string dt) {
    damage_type = dt;
}