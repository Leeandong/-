//
// Created by 李安东 on 2018/3/14.
//

#ifndef WAR2_0_SWORD_H
#define WAR2_0_SWORD_H


# include "Weapon.h"
#include <string>
using namespace std;


class Sword: public Weapon {

private:
    string name;

public:
    Sword(int attack_);
    void Attack(Warriors *p);
    virtual void cout_condition();
};


#endif //WAR2_0_SWORD_H
