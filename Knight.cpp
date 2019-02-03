//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Knight.h"
#include <iostream>

Knight::Knight() = default;

Knight::Knight(const string &name, double health, double specialAttackAmount) : Player(name, health), specialAttackAmount(specialAttackAmount) {}

Knight::~Knight() = default;

const string Knight::specialAttackName = "Lighting Bolt";

const string &Knight::getSpecialAttackName() {
    return specialAttackName;
}

double Knight::getSpecialAttackAmount() const {
    return specialAttackAmount;
}

void Knight::setSpecialAttackAmount(double specialAttackAmount) {
    Knight::specialAttackAmount = specialAttackAmount;
}

void Knight::specialAttack() {
    cout << "You used a power attack at the enemy!" << endl;
}
