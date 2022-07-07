#include <string>

using namespace std;

class rollData {
    public:
        rollData();
        rollData(int, int, string, int, string);
        int getNumberOfDice() const;
        int getDieSize() const;
        int getModifier() const;
        string getArithmetic() const;
        string getDamageType() const;
        void setNumberOfDice(int);
        void setDieSize(int);
        void setArithmetic(string);
        void setModifier(int);
        void setDamageType(string);
    private:
        int number_of_dice;
        int die_size;
        string arithmetic;
        int modifier;
        string damage_type;
};