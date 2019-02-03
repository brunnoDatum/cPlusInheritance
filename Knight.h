//
// Created by Brunno Tripovichy on 2019-01-23.
//

#ifndef GAME1011_TRIPOVICHYBRUNNO_A1_KNIGHT_H
#define GAME1011_TRIPOVICHYBRUNNO_A1_KNIGHT_H


#include "Player.h"
#include <string>

using namespace std;

class Knight: public Player {

private:
    static const string specialAttackName;
    double specialAttackAmount;

public:
    Knight();

    Knight(const string &name, double health, double specialAttackAmount);

    virtual ~Knight();

    static const string &getSpecialAttackName();

    double getSpecialAttackAmount() const;

    void setSpecialAttackAmount(double specialAttackAmount);

    void specialAttack() override;
};


#endif //GAME1011_TRIPOVICHYBRUNNO_A1_KNIGHT_H
