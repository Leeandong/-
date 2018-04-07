//
// Created by 李安东 on 2018/3/11.
//

#include <iostream>
#include "Lion.h"
Lion::Lion(int serial_num, int strength,string& crops_,int loyalty_):Warriors(serial_num, strength) {
     name="lion";
     crops=crops_;
     loyalty=loyalty_;
    attack=warriors_attack[3];
}

void Lion::fightback(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(int(warriors_attack[3]/2));

}

void Lion::Hurted(int a) {
    Warriors::Hurted(a);
}

void Lion::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(warriors_attack[3]);
    p->fightback(this);

}

void Lion::cout_born() {
    Warriors::cout_born();
    cout<<"Its loyalty is "<<loyalty<<endl;
}

bool Lion::run_away() {
    if(loyalty<=0)
    {
        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
             <<" run away"<< endl;
        return true;
    }
    else
    {
        return false;
    }

}
