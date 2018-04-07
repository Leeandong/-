//
// Created by 李安东 on 2018/3/11.
//

#include "Ninja.h"



Ninja::Ninja(int serial_num, int strength,string& crops_) : Warriors(serial_num, strength) {
    name="ninja";
    int tmp=serial_num%3;
    switch (tmp)
    {
        case 0: {
            weapon[0]= new Sword(int(warriors_attack[1]*0.2));
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
    crops=crops_;
    attack=warriors_attack[1];
}



Ninja::~Ninja() {
    for(int i=0;i<3;i++)
    {
        if(weapon[i])
            delete(weapon[i]);
    }

}
void Ninja::fightback(Warriors *p) {


}

void Ninja::Hurted(int a) {
    Warriors::Hurted(a);

}

void Ninja::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(warriors_attack[1]);
    p->fightback(this);


}