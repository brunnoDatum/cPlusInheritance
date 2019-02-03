//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Game.h"

#ifndef GAME1011_TRIPOVICHYBRUNNO_A1_ENEMY_H
#define GAME1011_TRIPOVICHYBRUNNO_A1_ENEMY_H

using namespace std;

class Enemy: public Game {

private:
    double health;

public:
    Enemy();

    Enemy(double health);

    virtual ~Enemy();

    void normalAttack() override;

    virtual void tauntPlayer() = 0;

    double getHealth() const;

    void setHealth(double health);
};


#endif //GAME1011_TRIPOVICHYBRUNNO_A1_ENEMY_H
