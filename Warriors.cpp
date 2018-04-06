//
// Created by 李安东 on 2018/3/11.
//

#include "Warriors.h"
#include <iostream>


Warriors::Warriors(int serial_num, int strength) : serial_num(serial_num), strength(strength) {
    weapon=new Weapon*[3];
    for(int i=0;i<3;i++)
    {
        weapon[i]= NULL;
    }
}

void Warriors::Hurted(int a){strength-=a;}

Warriors::~Warriors() {
    delete [] weapon;

}

void Warriors::fightback(Warriors *p) {

}

void Warriors::attack(Warriors *p) {
    for(int i=0;i<3;i++)
    {
        if(weapon[i])
        {
            weapon[i]->Attack(p);
        }

    }

}

int Warriors::get_lives() {
    return strength;
}

void Warriors::cout_born() {
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
         <<' '<< "born"<< endl;

}

bool Warriors::run_away() {
    return false;
}

void Warriors::cout_march(City *c) {
    //000:10 red iceman 1 marched to city 1 with 20 elements and force 30
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" march to city "
         <<c->get_index()<<" with "<<strength<<" elements"<<" and force "<<attack_<<endl;

}



