//
// Created by Brunno Tripovichy on 2019-01-23.
//

#ifndef GAME1011_TRIPOVICHYBRUNNO_A1_UNDEAD_H
#define GAME1011_TRIPOVICHYBRUNNO_A1_UNDEAD_H


#include "Enemy.h"
#include <string>
#include <vector>

using namespace std;

class Undead: public Enemy {

private:
    static const string specieName;
    vector<string> taunts;

public:
    Undead();

    Undead(double health, const vector<string> &taunts);

    virtual ~Undead();

    static const string &getSpecieName();

    const vector<string> &getTaunts() const;

    void setTaunts(const vector<string> &taunts);

    void tauntPlayer() override;
};


#endif //GAME1011_TRIPOVICHYBRUNNO_A1_UNDEAD_H
