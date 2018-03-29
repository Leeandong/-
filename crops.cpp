//
// Created by 李安东 on 2018/3/11.
//

#include "crops.h"
#include <iostream>
#include <iomanip>
#include "Global.h"


crops::crops(int lives, int *p_warriors, const string &name
             ) : lives(lives), p_warriors(p_warriors),
                                        name(name)  {
    for(int i=0;i<5;i++)
    {
        num_warriors[i]=0;

    }
    num=0;
    flag=0;
    stop_flag=false;
}


void crops::creat_warriors() {
    for (int i=0;i<5;i++)
    {
        if(warriors_strength[p_warriors[(flag+i)%5]]<=lives)
        {
            break;
        }
    }
    lives -= warriors_strength[p_warriors[flag]];
    if(lives>=0)
    {
        num_warriors[p_warriors[flag]] += 1;
        num++;
        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout << game_time << ' ' << name << ' ' << warriors_name[p_warriors[flag]]
             << ' ' << num << " born with strength " << warriors_strength[p_warriors[flag]]
             << ',' << num_warriors[p_warriors[flag]] << ' ' << warriors_name[p_warriors[flag]]
             << " in " << name << " headquarter" << endl;
        flag=(flag+1)%5;

    }
    else
    {
        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout<<game_time<<' '<<name<<" headquarter stops making warriors"<<endl;
        stop_flag=true;

    }

};

bool crops::if_stop(){
        return stop_flag;
};