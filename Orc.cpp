//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Orc.h"
#include <time.h>
#include <iostream>

Orc::Orc() {}

Orc::Orc(double health, const vector <string> &taunts) : Enemy(health), taunts(taunts) {}

Orc::~Orc() = default;

const string Orc::specieName = "Orc Marauder";

const string &Orc::getSpecieName() {
    return specieName;
}

const vector <string> &Orc::getTaunts() const {
    return taunts;
}

void Orc::setTaunts(const vector <string> &taunts) {
    Orc::taunts = taunts;
}

void Orc::tauntPlayer() {
    srand((unsigned) time(NULL));
    cout << Orc::taunts[arc4random() % taunts.size()] << endl;
}
