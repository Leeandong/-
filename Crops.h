//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_CROPS_H
#define WAR2_0_CROPS_H



#include <string>
#include "Warriors.h"

using namespace std;


class Crops {

private:


    int lives;
    int num;//当前联盟中武士的个数
    int flag; //当前应该产生的武士
    int * p_warriors;  //产生武士的顺序；
    int num_warriors [5]; //联盟中各种武士的数目
    string name;   //crops的名字
    Warriors * warriors;  //挂着当前出现的武士
    Warriors * enemys; //进入当前指挥部的最后一个敌人武士
    int index; //当前联盟中停留在指挥部中的士兵个数
    int num_enemy; //当前联盟中敌人的数量



public:
    Crops(int lives, int *p_warriors, const string &name);
    int which_to_creat();  //返回应该生产的士兵的序号，如果是5，则表示停止生产
    int get_num(); //获得联盟中当前的武士数目
    int * get_num_warriors(); //获得当前联盟中各种武士的指针
    int get_lives(); //获得联盟剩余的生命元数目
    void add_lives(int i); //获取生命元
    void add(Warriors* w); //添加当前产生出来的士兵
    string & get_name(); //获得当前联盟的名称
    Warriors* get(); //获得联盟中停下的士兵,并将指针置为空指针r
    void warriors_to_null(); //将联盟中的warriors指针置空
    bool lose(); //当前是否被攻克；
    void delete_run(); //删除逃跑的狮子
    void add_enemy(Warriors * w); //加入进入我方指挥部的敌人
    void cout_reach(); //宣布到达信息，并删除敌人节点
    void cout_lives(); //报告当前的生命元信息
    void Award(City * c); //奖励获胜的武士


    virtual ~Crops();
    //删除主函数中new的warriors






};

#endif //WAR2_0_CROPS_H


