//
// Created by 李安东 on 2018/3/11.
//

#include <iostream>
#include "Dragon.h"
#include "Global.h"
using namespace std;

Dragon::Dragon(int serial_num, int strength,int remain_lives) : Warriors(serial_num, strength) {
    int tmp=serial_num%3;
    switch (tmp)
    {
        case 0: {
            weapon[0]= new Sword(int(warriors_attack[0]*0.2));
            weapon[1]= new Arrow();
            break;
        }
        case 1: {
            weapon[1]= new Arrow();
            weapon[2]= new Bomb();
            break;
        }
        default:
        {
            weapon[2]= new Bomb();
            weapon[0]= new Sword(int(strength*0.2));
        }

    }
    morale=remain_lives/warriors_strength[0];


}

Dragon::~Dragon() {
    for(int i=0;i<3;i++)
    {
        if(weapon[i])
            delete(weapon[i]);
    }

}

void Dragon::fightback(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(int(warriors_attack[0]/2));

}

void Dragon::Hurted(int a) {
    Warriors::Hurted(a);

}

void Dragon::attack(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(warriors_attack[0]);
    p->fightback(this);
    if((strength>0)&&(morale>0.8))
    {
        morale+=0.2;
        cout<<"cheer"<<endl;
    }

}


