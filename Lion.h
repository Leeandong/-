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
    int temp_lives; //存放战斗前狮子的生命值
public:
    Lion(int serial_num, int strength,Crops * c_,int loyalty_);
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p); //攻击函数

    virtual void cout_born();
    virtual bool run_away();

    virtual void fightback(Warriors *p);

    virtual void lose(Warriors *winner, City *c);

    virtual void after_fight(Warriors *w);

    virtual ~Lion();
    //忠诚度低于一定值时逃跑
};




#endif //WAR2_0_LION_H
