//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_ICEMAN_H
#define WAR2_0_ICEMAN_H


#include "Warriors.h"
#include <string>
#include "Global.h"
using namespace std;

class Iceman: public Warriors {

public:
    Iceman(int serial_num, int strength,string & crops_);
    virtual ~Iceman();
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p); //攻击函数
};


#endif //WAR2_0_ICEMAN_H
