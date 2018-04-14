//
// Created by 李安东 on 2018/3/11.
//

#include <iostream>
#include "Lion.h"
Lion::Lion(int serial_num, int strength,Crops * c_,int loyalty_):Warriors(serial_num, strength,c_) {
     name="lion";
     loyalty=loyalty_;
    attack=warriors_attack[3];
    temp_lives=strength;
}



void Lion::Hurted(int a) {
//    temp_lives=strength;
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

void Lion::fightback(Warriors *p) {
    Warriors::fightback(p);
}

void Lion::lose(Warriors *winner, City *c) {
    Warriors::lose(winner, c);
    winner->add_lives(temp_lives);


}

void Lion::after_fight(Warriors *w) {
    Warriors::after_fight(w);
    if(w->get_lives()>0)
    {
        memory_lives();
        loyalty-=K;
    }

}

Lion::~Lion() {
    if(sword)
        delete(sword);
    if(arrow)
        delete(arrow);
    if(bomb)
        delete(bomb);

}

void Lion::memory_lives() {
    Warriors::memory_lives();
    temp_lives=strength;
}
