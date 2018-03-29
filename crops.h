//
// Created by 李安东 on 2018/3/11.
//

#ifndef WAR2_0_CROPS_H
#define WAR2_0_CROPS_H


#endif //WAR2_0_CROPS_H

#include <string>
using namespace std;


class crops {

private:


    int lives;
    int num;//当前联盟中武士的个数
    int flag; //当前应该产生的武士；
    int * p_warriors;  //产生武士的顺序；
    int num_warriors [5]; //联盟中各种武士的数目
    string name;


    bool stop_flag; //是否停止的标记符


public:
    crops(int lives, int *p_warriors, const string &name);
    void creat_warriors();
//    bool if_next();
    bool if_stop();



};

