//
// Created by 李安东 on 2018/3/11.
//

#include "Crops.h"
#include <iostream>
#include <iomanip>
#include "Global.h"


Crops::Crops(int lives, int *p_warriors, const string &name
             ) : lives(lives), p_warriors(p_warriors),
                                        name(name)  {
    for(int i=0;i<5;i++)
    {
        num_warriors[i]=0;

    }
    warriors=NULL;
    enemys=NULL;
    num=0;
    flag=0;
    index=0;
    num_enemy=0;
}

//
//int Crops::which_to_creat() {
//    int i;
//    for (i=0;i<5;i++)
//    {
//        if(warriors_strength[p_warriors[(flag+i)%5]]<=lives)
//            break;
//    }
//    if(i==5)
//    {
//        return 5;
//    }
//    else
//    {
//        lives -= warriors_strength[p_warriors[flag]];
//        num_warriors[p_warriors[flag]] += 1;
//        num++;
//        flag++;
//        return p_warriors[(flag-1)%5];
//    }
//}


int Crops::which_to_creat() {
    if(warriors_strength[p_warriors[(flag)%5]]<=lives)
    {

        lives -= warriors_strength[p_warriors[flag]];
        num_warriors[p_warriors[flag]] += 1;
        num++;
        flag++;
        return p_warriors[(flag-1)%5];

    }
    else
    {
        return 5;

    }
}

int Crops::get_num() {
    return num;
}


int *Crops::get_num_warriors() {
    return num_warriors;
}

int Crops::get_lives() {
    return lives;
}


Warriors *Crops::get() {
    Warriors* temp=warriors;
    return temp;
}



void Crops::add(Warriors *w) {
    warriors=w;

}



string &Crops::get_name() {
    return name;
}

Crops::~Crops() {
    if(warriors)
        delete(warriors);
    if(enemys)
        delete(enemys);

}

void Crops::add_lives(int i) {
    lives+=i;
}



bool Crops::lose() {
    if(num_enemy>=2)
    //003:10 blue headquarter was taken
    {
        cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << name <<" headquarter was taken"<<endl;
    return true;
    }
    else
    {
        return false;
    }

}

void Crops::delete_run() {

    if(warriors)
    {
        if(warriors->run_away())
        {
            delete warriors;
            warriors=NULL;
        }

    }

}

void Crops::add_enemy(Warriors * w) {
    enemys = w;

}

void Crops::cout_reach() {
    if(enemys)
    {
        enemys->cout_reach(this);
        delete(enemys);
        enemys=NULL;
        num_enemy++;
        if(num_enemy>=2)
        {
            cout.width(3); // 设置宽度
            cout.fill('0');// 设置填充
            cout<<hours<<':';
            cout.width(2); // 设置宽度
            cout.fill('0');// 设置填充
            cout << minutes << ' ' << name <<" headquarter was taken"<<endl;
            exit(0);
        }
    }


}

void Crops::warriors_to_null() {
    warriors = NULL;

}

void Crops::cout_lives() {
//    000:50 100 elements in red headquarter
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << lives <<" elements in "<<name<<" headquarter";

}






