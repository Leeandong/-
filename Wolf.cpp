//
// Created by 李安东 on 2018/3/11.
//

#include "Wolf.h"

Wolf::Wolf(int serial_num, int strength,Crops * c_) : Warriors(serial_num, strength,c_) {
    name="wolf";
    attack=warriors_attack[4];
}


void Wolf::Hurted(int a) {
    Warriors::Hurted(a);
}

void Wolf::Attack(Warriors *p) {
    Warriors::Attack(p);
    p->Hurted(warriors_attack[4]);
    p->fightback(this);
//    if(p->get_lives()<=0)
//    {
//        if((sword==NULL)&&(p->get_sword()))
//        {
//            sword = new Sword(*(p->get_sword()));
//        }
//
//        if((arrow==NULL)&&(p->get_arrow()))
//        {
//            arrow = new Arrow(*(p->get_arrow()));
//        }
//
//        if((bomb==NULL)&&(p->get_bomb()))
//        {
//            bomb = new Bomb(*(p->get_bomb()));
//        }
//    }
}

void Wolf::fightback(Warriors *p) {
    Warriors::fightback(p);
//    if(p->get_lives()<=0)
//    {
//        if((sword==NULL)&&(p->get_sword()))
//        {
//            sword = new Sword(*(p->get_sword()));
//        }
//
//        if((arrow==NULL)&&(p->get_arrow()))
//        {
//            arrow = new Arrow(*(p->get_arrow()));
//        }
//
//        if((bomb==NULL)&&(p->get_bomb()))
//        {
//            bomb = new Bomb(*(p->get_bomb()));
//        }
//    }
}

void Wolf::win(Warriors *loser, City *c) {
    Warriors::win(loser, c);
    if((sword==NULL)&&(loser->get_sword()))
    {
        sword = new Sword(*(loser->get_sword()));
    }

    if((arrow==NULL)&&(loser->get_arrow()))
    {
        arrow = new Arrow(*(loser->get_arrow()));
    }

    if((bomb==NULL)&&(loser->get_bomb()))
    {
        bomb = new Bomb(*(loser->get_bomb()));
    }

}



