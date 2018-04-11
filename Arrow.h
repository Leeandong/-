//
// Created by 李安东 on 2018/3/14.
//

#ifndef WAR2_0_ARROW_H
#define WAR2_0_ARROW_H


#include "Weapon.h"
#include <string>
using namespace std;

class Arrow : public Weapon{
    int remains;
    string name;
public:
    Arrow();
    void Attack(Warriors *p) ;
    int get_remain_times();

    virtual void cout_condition();

};


#endif //WAR2_0_ARROW_H
