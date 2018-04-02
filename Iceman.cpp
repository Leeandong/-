//
// Created by 李安东 on 2018/3/11.
//

#include "Iceman.h"

Iceman::Iceman(int serial_num, int strength,string & crops_) : Warriors(serial_num, strength) {
    int tmp=serial_num%3;
    name="iceman";
    crops=crops_;
    switch (tmp)
    {
        case 0: {
            weapon[0]= new Sword(int(warriors_attack[2]*0.2));
            break;
        }
        case 1: {
            weapon[1]= new Arrow();
            break;
        }
        default:
        {
            weapon[2]= new Bomb();
        }

    }
}

Iceman::~Iceman() {
    for(int i=0;i<3;i++)
    {
        if(weapon[i])
            delete(weapon[i]);
    }

}

void Iceman::fightback(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(int(warriors_attack[2]));
}

void Iceman::Hurted(int a) {
    Warriors::Hurted(a);
}

void Iceman::attack(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(warriors_attack[2]);
    p->fightback(this);
}
