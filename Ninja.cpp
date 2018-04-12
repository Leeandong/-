//
// Created by 李安东 on 2018/3/11.
//

#include "Ninja.h"



Ninja::Ninja(int serial_num, int strength,Crops * c_) : Warriors(serial_num, strength, c_) {
    name="ninja";
    int tmp=serial_num%3;
    attack=warriors_attack[1];
    switch (tmp)
    {
        case 0: {
            if((int(attack*0.2))>0)
            {
                sword= new Sword(int(attack*0.2));
            }

            bomb= new Bomb();
            break;
        }
        case 1: {
            bomb= new Bomb();
            arrow= new Arrow();
            break;
        }
        default:
        {
            arrow= new Arrow();
            if((int(attack*0.2))>0)
            {
                sword= new Sword(int(attack*0.2));
            }
        }

    }

}



Ninja::~Ninja() {
    if(sword)
        delete(sword);
    if(arrow)
        delete(arrow);
    if(bomb)
        delete(bomb);

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

int Ninja::get_fightback_value() {
   return 0;
}
