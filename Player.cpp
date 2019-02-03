//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Player.h"
#include <iostream>

Player::Player() = default;

Player::Player(const string &name, double health) : name(name), health(health) {}

Player::~Player() = default;

void Player::normalAttack() {
    cout << "You slash the enemy!" << endl;
}

const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}

double Player::getHealth() const {
    return health;
}

void Player::setHealth(double health) {
    Player::health = health;
}
