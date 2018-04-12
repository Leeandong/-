//
// Created by 李安东 on 2018/3/14.
//

#include "Warriors.h"


Weapon::Weapon(int attack) : attack(attack) {}

int Weapon::get_attack() {
    return attack;
}

void Weapon::Attack(Warriors *p) {

}

void Weapon::cout_condition() {

}

bool Weapon::if_exist() {
    return true;
}



