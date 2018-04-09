//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_NINJA_H
#define WAR2_0_NINJA_H


#include "Warriors.h"
#include<string>
#include "Global.h"
using namespace std;

class Ninja: public Warriors {
public:

    Ninja(int serial_num, int strength,Crops * c_);
    virtual ~Ninja();
    virtual void fightback(Warriors *p); //反击函数
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p);

    virtual int get_fightback_value() ;
    //攻击函数




};



#endif //WAR2_0_NINJA_H
