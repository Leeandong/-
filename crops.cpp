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
    warriors=NULL;
    num=0;
    flag=0;
    index=0;

}


int crops::which_to_creat() {
    int i;
    for (i=0;i<5;i++)
    {
        if(warriors_strength[p_warriors[(flag+i)%5]]<=lives)
            break;
    }
    if(i==5)
    {
        return 5;
    }
    else
    {
        lives -= warriors_strength[p_warriors[flag]];
        num_warriors[p_warriors[flag]] += 1;
        num++;
        flag++;
        return p_warriors[(flag-1)%5];
    }
}

int crops::get_num() {
    return num;
}


int *crops::get_num_warriors() {
    return num_warriors;
}

int crops::get_lives() {
    return lives;
}


Warriors *crops::get() {
    Warriors* temp=warriors;
    warriors=NULL;
    return temp;
}

void crops::add(Warriors *w) {
    warriors=w;

}

void crops::cout_stop() {

    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<minutes<<' '<< name <<" headquarter stops making warriors"<<endl;

};



void crops::delete_warriors() {
    if(warriors)
    {
        delete(warriors);
    }

}

string &crops::get_name() {
    return name;
}

crops::~crops() {
    if(warriors)
        delete(warriors);

}




