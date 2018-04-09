//
// Created by 李安东 on 2018/3/11.
//

#include <iostream>
#include <iomanip>
#include "Dragon.h"
#include "Global.h"
using namespace std;

Dragon::Dragon(int serial_num, int strength,int remain_lives,string & crops_) : Warriors(serial_num, strength,crops_) {
    int tmp=serial_num%3;
    switch (tmp)
    {
        case 0: {
            sword= new Sword(int(warriors_attack[0]*0.2));
            arrow= new Arrow();
            break;
        }
        case 1: {
            arrow= new Arrow();
            bomb= new Bomb();
            break;
        }
        default:
        {
            bomb= new Bomb();
            sword= new Sword(int(strength*0.2));
        }

    }
    morale=remain_lives/warriors_strength[0];
    name="dragon";
    attack=warriors_attack[0];



}

Dragon::~Dragon() {
    if(sword)
        delete(sword);
    if(arrow)
        delete(arrow);
    if(bomb)
        delete(bomb);


}


void Dragon::Hurted(int a) {
    Warriors::Hurted(a);



}

void Dragon::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(warriors_attack[0]);
    if(p->get_lives()<=0)
    {
        morale+=0.2;
    }
    else
    {
        morale-=0.2;
    }
    p->fightback(this);
    //   003:40 blue dragon 2 yelled in city 4
    if((strength>0)&&(morale>0.8))
    {

        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout<<hours<<':';
        cout.width(2); // 设置宽度
        cout.fill('0');// 设置填充
        cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
             <<" yelled in city "<<city_num;

    }



}

void Dragon::cout_born() {
    Warriors::cout_born();
    cout<<"Its morale is "<<fixed<<setprecision(2)<<morale<<endl;
}

void Dragon::fightback(Warriors *p) {
    Warriors::fightback(p);
    if(p->get_lives()<=0)
    {
        morale+=0.2;
    }
    else
    {
        morale-=0.2;
    }
}






