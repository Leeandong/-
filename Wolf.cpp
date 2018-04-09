//
// Created by 李安东 on 2018/3/11.
//

#include "Wolf.h"

Wolf::Wolf(int serial_num, int strength,string& crops_) : Warriors(serial_num, strength,crops_) {
    name="wolf";
    attack=warriors_attack[4];
}


void Wolf::Hurted(int a) {
    Warriors::Hurted(a);
}

void Wolf::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(warriors_attack[4]);
    p->fightback(this);
}
