//
// Created by 李安东 on 2018/3/11.
//

#include "Warriors.h"
#include <iostream>


Warriors::Warriors(int serial_num, int strength,string & crops_) : serial_num(serial_num), strength(strength) ,crops(crops_){
    sword = NULL;
    arrow = NULL;
    bomb =NULL;
    if(crops_=="red")
    {
        city_num=-1;
    }
    else
    {
        city_num=N;
    }

}

void Warriors::Hurted(int a){strength-=a;}

Warriors::~Warriors() {


}

void Warriors::fightback(Warriors *p) {
    //            001:40 blue dragon 2 fought back against
//            red lion 2 in city 1
    if(strength>0)
    {
        if(sword)
        {
            sword->Attack(p);
            p->Hurted(int(attack/2));
        }
        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout<<hours<<':';
        cout.width(2); // 设置宽度
        cout.fill('0');// 设置填充
        cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" fought back against ";
        p->cout_info();
        cout<<" in city "<< index<<endl;

    }

}

void Warriors::Attack(Warriors *p) {
//    000:40 red iceman 1 attacked blue lion 1 in
//    city 1 with 20 elements and force 30
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" attack ";
    p->cout_info();
    cout<< " in city "<<city_num<<" with "<<strength<<" elements"<<" and force "<<attack<<endl;

    if(sword)
    {
        sword->Attack(p);
    }

}

int Warriors::get_lives() {
    return strength;
}

void Warriors::cout_born() {
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
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
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" march to city "
         <<c->get_index()<<" with "<<strength<<" elements"<<" and force "<<attack<<endl;

}

void Warriors::Archery(Warriors *w) {
    if(arrow)
    {
        arrow->Attack(w);
        if(arrow->get_remain_times()<=0)
        {
            delete arrow;
            arrow=NULL;
        }
    }
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" shot ";
    if(w->get_lives()<=0)
    {
        w->cout_info();
    }

    cout<<endl;


}

void Warriors::cout_info() {

    cout << crops << ' ' <<name<<' '<< serial_num;


}

int Warriors::get_attack_value() {
    int sword_attack=0;
    if(sword)
    {
        sword_attack=sword->get_attack();
    }
    return sword_attack+attack;
}

int Warriors::get_fightback_value() {
    int sword_attack=0;
    if(sword)
    {
        sword_attack=sword->get_attack();
    }
    return sword_attack+attack/2;
}

bool Warriors::before_use_bomb(Warriors *w) {
    if(bomb)
    {
        if(w->get_fightback_value()>=strength)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

bool Warriors::after_use_bomb(Warriors *w) {
    if(bomb)
    {
        if(w->get_attack_value()>=strength)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

void Warriors::cout_get_lives(City * c) {
//    000:30 red iceman 1 earned 10 elements for his headquarter
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" earned "
         <<c->get_lives_info()<<" elements for his headquarter"<<endl;


}


void Warriors::forward() {

    if(crops=="red")
    {
        if(city_num<N-1)
        {
            city_num+=1;
            cities[city_num]->add_r(this);
        }
        else
        {


        }



    }
    else
    {
        if(city_num>0)
        {
            city_num-=1;
            cities[city_num]->add_r(this);

        }

    }



}









