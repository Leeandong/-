//
// Created by 李安东 on 2018/3/14.
//

#include <iostream>
#include "Bomb.h"
#include "Warriors.h"



Bomb::Bomb() : Weapon(999) {name="Bomb";}

void Bomb::Attack(Warriors *p) {
    p->Hurted(p->get_lives());
}

void Bomb::cout_condition() {
    Weapon::cout_condition();
    cout<<"bomb";
}




