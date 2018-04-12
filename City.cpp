//
// Created by 李安东 on 2018/3/30.
//

#include <iostream>
#include "City.h"
#include "Warriors.h"
#include "Crops.h"

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
    step_b=0;
    step_r=0;
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
    if(r&&b)
    {

        if(which_first_attack())  //红方先进攻
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


}

int City::get_lives_info() {
    return lives;
}

void City::Fight_in_city() {
    if(r&&b)
    {
        if((r->get_lives()>0)&&(b->get_lives()>0))
        {
            if(which_first_attack())
            {
                r->Attack(b);
            }
            else
            {
                b->Attack(r);
            }
            if(r->get_lives()<=0)
            {
                r->cout_die();
            }
            if(b->get_lives()<=0)
            {
                b->cout_die();
            }
        }
        if(r->get_lives()<=0)
        {
            after_win(b,r);
        }
        if(b->get_lives()<=0)
        {
            after_win(r,b);
        }
        r->after_fight(b);
        b->after_fight(r);
        if(r->get_lives()<=0)
        {
            after_fight(b,r);
        }
        if(b->get_lives()<=0)
        {
            after_fight(r,b);
        }


    }



}

void City::after_win(Warriors *winner, Warriors *loser) {

    winner->win(loser, this);
    loser->lose(winner, this);

}

int City::which_first_attack() {
    if((index%2==1)||(flag==1))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void City::after_fight(Warriors *winner, Warriors *loser) {
//    001:40 blue dragon 2 earned 10 elements
//    for his headquarter

    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout << hours << ':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ';
    winner->cout_info();
    int temp= get_lives();
    cout<<" earned "<<temp <<" elements for his headquarter"<<endl;
    winner->get_crop()->Award(winner);
    winner->get_crop()->add_lives(temp);
    if(winner->get_crop()->get_name()=="blue")
    {
        if(flag!=2)
        {
            step_b++;
            if(step_b==2)
            {
                flag=2;
                step_b=0;
                // 004:40 blue flag raised in city 4
                cout.width(3); // 设置宽度
                cout.fill('0');// 设置填充
                cout << hours << ':';
                cout.width(2); // 设置宽度
                cout.fill('0');// 设置填充
                cout << minutes << " blue flag raise in city"<< index;
            }

        }
    }
    else
    {
        if(flag!=1)
        {
            step_r++;
            if(step_r==2)
            {
                flag=1;
                step_r=0;
                // 004:40 blue flag raised in city 4
                cout.width(3); // 设置宽度
                cout.fill('0');// 设置填充
                cout << hours << ':';
                cout.width(2); // 设置宽度
                cout.fill('0');// 设置填充
                cout << minutes << " blue flag raise in city"<< index;
            }

        }

    }
    if(loser->get_crop()->get_name()=="blue")
    {
        b=NULL;
    }
    else
    {
        r=NULL;
    }
    delete(loser);
}

void City::cout_warriors_weapon() {
    if(r)
    {
        r->cout_weapons();
    }
    if(b)
    {
        b->cout_weapons();
    }

}

void City::red_to_null() {
    r=NULL;

}

void City::blue_to_null() {
    b=NULL;

}




