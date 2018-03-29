//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_NINJA_H
#define WAR2_0_NINJA_H


#include "Warriors.h"
#include<string>
#include "Global.h"
using namespace std;

class Ninja: Warriors {
public:

    Ninja(int serial_num, int strength);
    virtual ~Ninja();
    virtual void fightback(Warriors *p); //反击函数
    virtual void Hurted(int a);  //受伤函数
    virtual void attack(Warriors *p); //攻击函数


private:
    string name="ninja";

};


#endif //WAR2_0_NINJA_H
