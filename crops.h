//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_CROPS_H
#define WAR2_0_CROPS_H



#include <string>
#include "Warriors.h"

using namespace std;


class crops {

private:


    int lives;
    int num;//当前联盟中武士的个数
    int flag; //当前应该产生的武士
    int * p_warriors;  //产生武士的顺序；
    int num_warriors [5]; //联盟中各种武士的数目
    string name;   //crops的名字
    Warriors * warriors;  //挂着当前出现的武士
    int index; //当前联盟中停留在指挥部中的士兵个数



public:
    crops(int lives, int *p_warriors, const string &name);
    int which_to_creat();  //返回应该生产的士兵的序号，如果是5，则表示停止生产
    int get_num(); //获得联盟中当前的武士数目
    int * get_num_warriors(); //获得当前联盟中各种武士的指针
    int get_lives(); //获得联盟剩余的生命元数目
    void add(Warriors* w); //添加当前产生出来的士兵
    string & get_name(); //获得当前联盟的名称
    Warriors* get(); //获得联盟中停下的士兵,并将指针置为空指针
    void cout_stop(); //输出停止信息
    void delete_warriors();

    virtual ~crops();
    //删除主函数中new的warriors






};

#endif //WAR2_0_CROPS_H


