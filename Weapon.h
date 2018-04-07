//
// Created by 李安东 on 2018/3/14.
//

#ifndef WAR2_0_WEAPON_H
#define WAR2_0_WEAPON_H

#include "Weapon.h"


class Warriors;


class Weapon {
protected:
    int attack; //攻击值
public:
    Weapon(int attack_);
    virtual void Attack(Warriors* p)=0;
    int get_attack(); //获得攻击力的值

};


#endif //WAR2_0_WEAPON_H
