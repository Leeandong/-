//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_WOLF_H
#define WAR2_0_WOLF_H


#include "Warriors.h"
#include <string>
#include "Global.h"
using namespace std;

class Wolf: public Warriors {

public:
    Wolf(int serial_num, int strength,Crops * c_);
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p); //攻击函数
    void fightback(Warriors *p) override;

};


#endif //WAR2_0_WOLF_H
