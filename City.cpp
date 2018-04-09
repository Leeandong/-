//
// Created by 李安东 on 2018/3/30.
//

#include <iostream>
#include "City.h"
#include "Warriors.h"

void City::produce_lives() {
    lives+=10;

}

void City::set_flag(int color) {
    flag=color;

}

int City::get_lives() {
    int temp=lives;
    lives=0;
    return temp;
}




City::City(int index_) {
    index=index_;
    r=NULL;
    b=NULL;
    flag=0;
    lives=0;
}


void City::delete_run() {
    if(b)
    {
        if(b->run_away())
        {
            delete b;
            b=NULL;
        }

    }

}

City::~City() {

    if(b)
    {
        delete(b);
    }
    if(r)
    {
        delete(r);
    }


}

Warriors *City::get_r() {
    return r;
}

Warriors *City::get_b() {
    return b;
}

void City::add_r(Warriors *w) {
    r=w;
}

void City::add_b(Warriors *w) {
    b=w;

}

void City::delete_r() {
    if(r)
    {
        delete r;
        r=NULL;
    }

}

void City::delete_b() {
    if(b)
    {
        delete b;
        b=NULL;
    }

}

int City::get_index() {
    return index;
}



void City::self_bursting() {

    if((index%2==1)||(flag==1))  //红方先进攻
    {
        if(r->before_use_bomb(b))
        {
//            000:38 blue dragon 1 used a bomb and killed red lion 7
            cout.width(3); // 设置宽度
            cout.fill('0');// 设置填充
            cout << hours << ':';
            cout.width(2); // 设置宽度
            cout.fill('0');// 设置填充
            cout << minutes << ' ' ;
            r->cout_info();
            cout<<" use a bomb and killed ";
            b->cout_info();
            cout<<endl;
          this->delete_b();
          this->delete_r();

        }
        if(b->after_use_bomb(r))
        {
//           000:38 blue dragon 1 used a bomb and killed red lion 7
            cout.width(3); // 设置宽度
            cout.fill('0');// 设置填充
            cout << hours << ':';
            cout.width(2); // 设置宽度
            cout.fill('0');// 设置填充
            cout << minutes << ' ';
            b->cout_info();
            cout<<" use a bomb and killed ";
            r->cout_info();
            cout<<endl;
            this->delete_b();
            this->delete_r();

        }

    }
    if((index%2==0)||(flag==0))
    {

        if(b->before_use_bomb(r))
        {
//            000:38 blue dragon 1 used a bomb and killed red lion 7
            cout.width(3); // 设置宽度
            cout.fill('0');// 设置填充
            cout << hours << ':';
            cout.width(2); // 设置宽度
            cout.fill('0');// 设置填充
            cout << minutes << ' ' ;
            b->cout_info();
            cout<<" use a bomb and killed ";
            r->cout_info();
            cout<<endl;
            this->delete_b();
            this->delete_r();

        }
        if(r->after_use_bomb(b))
        {
//           000:38 blue dragon 1 used a bomb and killed red lion 7
            cout.width(3); // 设置宽度
            cout.fill('0');// 设置填充
            cout << hours << ':';
            cout.width(2); // 设置宽度
            cout.fill('0');// 设置填充
            cout << minutes << ' ';
            r->cout_info();
            cout<<" use a bomb and killed ";
            b->cout_info();
            cout<<endl;
            this->delete_b();
            this->delete_r();

        }

    }


}

int City::get_lives_info() {
    return lives;
}

void City::Fight_in_city() {
    if((index%2==1)||(flag==1))
    {
        r->Attack(b);

    }
    else
    {
        b->Attack(r);
    }


}
