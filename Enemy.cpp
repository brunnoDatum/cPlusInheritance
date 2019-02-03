//
// Created by Brunno Tripovichy on 2019-01-23.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(): Game() {}

Enemy::Enemy(double health) : health(health) {}

Enemy::~Enemy() {

}

double Enemy::getHealth() const {
    return health;
}

void Enemy::setHealth(double health) {
    Enemy::health = health;
}

void Enemy::normalAttack() {
    cout << "You punched the player!" << endl;
}
