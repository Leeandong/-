//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_WARRIORS_H
#define WAR2_0_WARRIORS_H


#include "Weapon.h"
#include "Sword.h"
#include "Bomb.h"
#include "Arrow.h"
#include "Global.h"
#include "City.h"



class Warriors {

protected:
    int attack; //士兵的攻击值
    int serial_num;   //编号
    int strength;     //生命值
    Weapon** weapon; //武器
    string name; //武士名称
    string crops; //士兵所属的阵营


public:
    Warriors(int serial_num, int strength);
    virtual void fightback(Warriors *p); //反击函数
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p); //攻击函数
    void cout_info(); //输出自己的信息，格式为 阵营+名字+编号
    int get_lives();
    virtual void cout_born();
    virtual void cout_march(City *c);  //输出前进的消息
    virtual bool run_away();
    virtual void Archery(Warriors * w); //射箭
    virtual ~Warriors();


};


#endif //WAR2_0_WARRIORS_H
