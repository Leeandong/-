//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_LION_H
#define WAR2_0_LION_H


#include "Warriors.h"
#include "Global.h"
#include <string>
using namespace std;

class Lion: public Warriors {
private:
    int loyalty;
public:
    Lion(int serial_num, int strength,string & crops_,int loyalty_);
    virtual void fightback(Warriors *p); //反击函数
    virtual void Hurted(int a);  //受伤函数
    virtual void attack(Warriors *p); //攻击函数

    virtual void cout_born();
    virtual bool run_away(); //忠诚度低于一定值时逃跑
};



#endif //WAR2_0_LION_H
