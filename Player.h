//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include <string>
#include "Game.h"

#ifndef GAME1011_TRIPOVICHYBRUNNO_A1_PLAYER_H
#define GAME1011_TRIPOVICHYBRUNNO_A1_PLAYER_H

using namespace std;


class Player : public Game {

private:
    string name;
    double health;
public:

    Player();

    ~Player();

    Player(const string &name, double health);

    const string &getName() const;

    void setName(const string &name);

    double getHealth() const;

    void setHealth(double health);

    void normalAttack() override;

    virtual void specialAttack() = 0;

};


#endif //GAME1011_TRIPOVICHYBRUNNO_A1_PLAYER_H
