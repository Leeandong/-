//
// Created by 李安东 on 2018/3/11.
//

#include "Iceman.h"

Iceman::Iceman(int serial_num, int strength,Crops * c_) : Warriors(serial_num, strength,c_) {
    int tmp=serial_num%3;
    name="iceman";
    switch (tmp)
    {
        case 0: {
            sword= new Sword(int(warriors_attack[0]*0.2));
            break;
        }
        case 1: {
            arrow= new Arrow();
            break;
        }
        default:
        {
            bomb= new Bomb();
        }

    }
    attack=warriors_attack[2];
    step=0;
}

Iceman::~Iceman() {
    if(sword)
        delete(sword);
    if(arrow)
        delete(arrow);
    if(bomb)
        delete(bomb);

}




void Iceman::Hurted(int a) {
    Warriors::Hurted(a);
}

void Iceman::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(warriors_attack[2]);
    p->fightback(this);
}

void Iceman::forward() {
    Warriors::forward();
    step++;
    if(step%2==0)
    {
        if(strength>9)
        {
            strength-=9;
        }
        else
        {
            strength=1;
        }
        attack+=20;

    }

}
