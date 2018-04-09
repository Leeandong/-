//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_DRAGON_H
#define WAR2_0_DRAGON_H


#include "Warriors.h"
#include <string>

using namespace std;


class Dragon: public Warriors {

private:
    float morale;
public:
    Dragon(int serial_num, int strength,int remain_lives,Crops * c_);
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p); //攻击函数
    virtual ~Dragon();
    virtual void cout_born() ;

    virtual void fightback(Warriors *p);
};


#endif //WAR2_0_DRAGON_H
