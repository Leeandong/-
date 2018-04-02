//
// Created by 李安东 on 2018/3/30.
//

#ifndef WAR2_0_CITY_H
#define WAR2_0_CITY_H


#include "Warriors.h"

class City {

private:
    int lives;  //城市的生命元数
    int index; //城市的序数值
    int flag;  //0代表无旗帜，1代表红旗帜，2代表蓝色旗帜
    Warriors * b;  //指向蓝军士兵
    Warriors * r;  //指向红军士兵
public:
    void produce_lives();  //生产生命元
    void set_flag(int color);

    City(int index);

    //更改旗帜的颜色
    int get_lives();  //获得城市的所有生命元
    void attack();  //判断谁先进行攻击
    bool check_r();  //检查是否有红士兵,有红色士兵时返回true
    bool check_b();  //检查是否有蓝士兵，有蓝色士兵时返回true
    void delete_warroris();  //删除new的新对象

};




#endif //WAR2_0_CITY_H
