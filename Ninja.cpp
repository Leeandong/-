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
            sword= new Sword(int(warriors_attack[0]*0.2));
            arrow= new Arrow();
            break;
        }
        case 1: {
            arrow= new Arrow();
            bomb= new Bomb();
            break;
        }
        default:
        {
            bomb= new Bomb();
            sword= new Sword(int(strength*0.2));
        }

    }
    crops=crops_;
    attack=warriors_attack[1];
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
