//
// Created by 李安东 on 2018/3/11.
//

#include <iostream>
#include "Iceman.h"

Iceman::Iceman(int serial_num, int strength,Crops * c_) : Warriors(serial_num, strength,c_) {
    int tmp=serial_num%3;
    name="iceman";
    attack=warriors_attack[2];
    switch (tmp)
    {
        case 0:
        {
            if((int(attack*0.2))>0)
            {
                sword= new Sword(int(attack*0.2));
            }

            break;
        }
        case 1: {
            bomb= new Bomb();
            break;
        }
        default:
        {
            arrow= new Arrow();
        }

    }
    step=1;
}

Iceman::~Iceman() {
    if(sword)
        delete(sword);
    if(arrow)
        delete(arrow);
    if(bomb)
        delete(bomb);

}




void Iceman::Hurted(int a) {
    Warriors::Hurted(a);
}

void Iceman::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(attack);
    p->fightback(this);
}

void Iceman::forward() {
    Warriors::forward();
    step++;
    if(step%2==0)
    {
        if(strength>9)
        {
            strength-=9;
        }
        else
        {
            strength=1;
        }
        attack+=20;
    }

}

void Iceman::cout_reach(Crops *c) {
    step++;
    if(step%2==0)
    {
        if(strength>9)
        {
            strength-=9;
        }
        else
        {
            strength=1;
        }
        attack+=20;
    }

    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
         <<" reached " << c->get_name() <<" headquarter with "<<strength
         <<" elements and force "<<attack<<endl;
}
