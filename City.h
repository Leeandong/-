//
// Created by 李安东 on 2018/3/30.
//

#ifndef WAR2_0_CITY_H
#define WAR2_0_CITY_H



class Warriors;

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
    int get_lives();  //获得城市的所有生命元 并且生命元归0
    int get_lives_info(); //获得城市的生命元数量
    Warriors * get_r();  //检查是否有红士兵,返回红色士兵
    Warriors * get_b();  //检查是否有蓝士兵，返回蓝色士兵
    int get_index();  //返回当前城市的编号
    void add_r(Warriors* w);  //更新红士兵
    void add_b(Warriors* w);    //更新蓝士兵
    void delete_run(); //删除掉逃跑的狮子；
    void delete_r();  //删除蓝士兵，并将指针置空
    void delete_b();  //删除红士兵，并将指针置空
    virtual ~City();
    void self_bursting(); //该城市是否有人自爆
    void Fight_in_city(); //在城市进行战斗


};




#endif //WAR2_0_CITY_H
