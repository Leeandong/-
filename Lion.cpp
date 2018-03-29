//
// Created by 李安东 on 2018/3/11.
//

#include "Lion.h"
Lion::Lion(int serial_num, int strength):Warriors(serial_num, strength) {}

void Lion::fightback(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(int(warriors_attack[3]/2));
}

void Lion::Hurted(int a) {
    Warriors::Hurted(a);
}

void Lion::attack(Warriors *p) {
    Warriors::attack(p);
    p->Hurted(warriors_attack[3]);
    p->fightback(this);

}
