//
// Created by Brunno Tripovichy on 2019-01-23.
//

#ifndef GAME1011_TRIPOVICHYBRUNNO_A1_WIZARD_H
#define GAME1011_TRIPOVICHYBRUNNO_A1_WIZARD_H


#include "Player.h"
#include <string>

using namespace std;

class Wizard: public Player {

private:
    static const string specialAttackName;
    double specialAttackAmount;

public:
    Wizard();

    Wizard(const string &name, double health, double specialAttackAmount);

    virtual ~Wizard();

    static const string &getSpecialAttackName();

    double getSpecialAttackAmount() const;

    void setSpecialAttackAmount(double specialAttackAmount);

    void specialAttack() override;

};


#endif //GAME1011_TRIPOVICHYBRUNNO_A1_WIZARD_H
