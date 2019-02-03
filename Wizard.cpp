//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Wizard.h"
#include <iostream>

Wizard::Wizard() {}

Wizard::Wizard(const string &name, double health, double specialAttackAmount) : Player(name, health), specialAttackAmount(specialAttackAmount) {}

Wizard::~Wizard() {

}

const string Wizard::specialAttackName = "Lighting Bolt";

const string &Wizard::getSpecialAttackName() {
    return specialAttackName;
}

double Wizard::getSpecialAttackAmount() const {
    return specialAttackAmount;
}

void Wizard::setSpecialAttackAmount(double specialAttackAmount) {
    Wizard::specialAttackAmount = specialAttackAmount;
}

void Wizard::specialAttack() {
    cout << "You used a fireball at the enemy!" << endl;
}
