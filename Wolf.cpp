//
// Created by 李安东 on 2018/3/11.
//

#include "Wolf.h"

Wolf::Wolf(int serial_num, int strength,string& crops_) : Warriors(serial_num, strength) {
    name="wolf";
    crops=crops_;
    attack_=warriors_attack[4];
}

void Wolf::fightback(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(int(warriors_attack[4]/2));
}

void Wolf::Hurted(int a) {
    Warriors::Hurted(a);
}

void Wolf::attack(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(warriors_attack[4]);
    p->fightback(this);
}
