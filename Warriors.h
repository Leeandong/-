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
class Crops;


class Warriors {

protected:
    int attack; //士兵的攻击值
    int serial_num;   //编号
    int strength;     //生命值
    Arrow * arrow;
    Bomb *bomb;
    Sword *sword;
    string name; //武士名称
    string crops; //阵营的名称
    Crops * c; //阵营的指针
    int city_num; //当前所处的城市位置
    Weapon * weapon[3]; //维持一个武器的数组；


public:


    Warriors(int serial_num, int strength, Crops *c_);

    virtual ~Warriors();
    virtual void fightback(Warriors *p); //反击函数
    virtual void Hurted(int a);  //受伤函数
    virtual void Attack(Warriors *p); //攻击函数
    void cout_info(); //输出自己的信息，格式为 阵营+名字+编号
    int get_lives();
    virtual void cout_born();
    virtual void cout_march();  //输出前进的消息
    virtual void cout_reach(Crops * c); //输出到达敌方指挥部的消息
    virtual bool run_away();
    virtual void Archery(Warriors * w); //射箭
    virtual int get_attack_value(); //返回攻击值
    virtual int get_fightback_value(); //返回反击值
    bool before_use_bomb(Warriors *w); //是否先使用炸弹
    bool after_use_bomb(Warriors *w); //是否后使用炸弹
    void cout_get_lives(City * c); //输出获得生命元的信息
    virtual void forward(); // 前进
    virtual void add_lives(int lives_); //增加生命值
    virtual void cout_die(); //报告死亡
    virtual Sword* get_sword();//返回所持的武器
    virtual Arrow* get_arrow();//返回所持的武器
    virtual Bomb* get_bomb();//返回所持的武器
    virtual void win(Warriors * loser,City * c); //主要完成胜利后的操作
    virtual void lose(Warriors * winner,City * c); //主要完成失败后的对应操作
    virtual void after_fight(Warriors * w); //完成战斗完成后的操作
    Crops * get_crop(); //获得当前武士所在的City
    virtual void cout_weapons() ;//输出当前的武器信息
    virtual int num_weapons();  //返回武器的数目
    virtual void cout_win_lives(); //胜利时输出将生命元送回总部的消息
    virtual void cout_self_bursting(Warriors * w); //输出自爆时候的消息
    virtual void memory_lives(); //仅对应于狮子，存储当前生命值到temp_lives;


};


#endif //WAR2_0_WARRIORS_H
