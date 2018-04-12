//
// Created by 李安东 on 2018/3/14.
//

#include "Sword.h"
#include <math.h>
#include <iostream>
#include "Warriors.h"

Sword::Sword(int attack_) : Weapon(attack_) {name="sword";}

void Sword::Attack(Warriors *p) {
    p->Hurted(attack);
    attack=floor(0.8*attack);
}



void Sword::cout_condition() {
//    sword(23)

    cout<<"sword("<<attack<<")";

}

bool Sword::if_exist() {
    if(attack<=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}




