//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Undead.h"
#include <time.h>
#include <iostream>

Undead::Undead(): Enemy() {}

Undead::Undead(double health, const vector<string> &taunts) : Enemy(health), taunts(taunts) {}

Undead::~Undead() = default;

const string Undead::specieName = "Zombie";

const string &Undead::getSpecieName() {
    return specieName;
}

const vector<string> &Undead::getTaunts() const {
    return taunts;
}

void Undead::setTaunts(const vector<string> &taunts) {
    Undead::taunts = taunts;
}

void Undead::tauntPlayer() {
    srand((unsigned) time(NULL));
    cout << Undead::taunts[arc4random() % taunts.size()] << endl;
}
