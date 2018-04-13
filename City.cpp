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
    winner=NULL;
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
        if((r->get_lives()>0)&&(b->get_lives()>0))
        {
            if(which_first_attack())  //红方先进攻
            {
                if(r->before_use_bomb(b))
                {
//            000:38 blue dragon 1 used a bomb and killed red lion 7
                    r->cout_self_bursting(b);
                    this->delete_b();
                    this->delete_r();


                }
                if(b->after_use_bomb(r))
                {
                    b->cout_self_bursting(r);
                    this->delete_b();
                    this->delete_r();


                }

            }
            else
            {

                if(b->before_use_bomb(r))
                {
                    b->cout_self_bursting(r);
                    this->delete_b();
                    this->delete_r();

                }
                if(r->after_use_bomb(b))
                {
                    r->cout_self_bursting(b);
                    this->delete_b();
                    this->delete_r();

                }

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
            b->cout_win_lives();
            if(step_r>0)
            {
                step_r=0;
            }
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
                    cout << minutes << " blue flag raised in city "<< index<<endl;
                }

            }

        }
        else if(b->get_lives()<=0)
        {
            r->cout_win_lives();
            if(step_b>0)
            {
                step_b=0;
            }

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
                    cout << minutes << " red flag raised in city "<< index<<endl;
                }

            }

        }
        else
        {
            step_b=0;
            step_r=0;
        }

        if(r->get_lives()<=0)
        {
            winner = b;
        }
        if(b->get_lives()<=0)
        {
            winner = r;
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

void City::after_fight() {
    if(winner)
    {

        winner->get_crop()->add_lives(get_lives());
//        if(winner->get_crop()->get_name()=="blue")
//        {
//            if(flag!=2)
//            {
//                step_b++;
//                if(step_b==2)
//                {
//                    flag=2;
//                    step_b=0;
//                    // 004:40 blue flag raised in city 4
//                    cout.width(3); // 设置宽度
//                    cout.fill('0');// 设置填充
//                    cout << hours << ':';
//                    cout.width(2); // 设置宽度
//                    cout.fill('0');// 设置填充
//                    cout << minutes << " blue flag raise in city"<< index<<endl;
//                }
//
//            }
//        }
//        else
//        {
//            if(flag!=1)
//            {
//                step_r++;
//                if(step_r==2)
//                {
//                    flag=1;
//                    step_r=0;
//                    // 004:40 blue flag raised in city 4
//                    cout.width(3); // 设置宽度
//                    cout.fill('0');// 设置填充
//                    cout << hours << ':';
//                    cout.width(2); // 设置宽度
//                    cout.fill('0');// 设置填充
//                    cout << minutes << " blue flag raise in city"<< index<<endl;
//                }
//
//            }

//        }
        if(winner->get_crop()->get_name()=="blue")
        {
            delete r;
            r=NULL;

        }
        else
        {
            delete b;
            b=NULL;
        }

        winner=NULL;
    }


}


void City::red_to_null() {
    r=NULL;

}

void City::blue_to_null() {
    b=NULL;

}

Warriors *City::get_winner() {
    return winner;
}

void City::cout_r_weapon() {
        if(r)
    {
        r->cout_weapons();
    }

}

void City::cout_b_weapon() {
    if(b)
    {
        b->cout_weapons();
    }
}



