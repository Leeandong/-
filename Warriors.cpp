//
// Created by 李安东 on 2018/3/11.
//

#include "Warriors.h"
#include <iostream>
#include "Crops.h"

//
//Warriors::Warriors(int serial_num, int strength,string & crops_) : serial_num(serial_num), strength(strength) ,crops(crops_){
//    sword = NULL;
//    arrow = NULL;
//    bomb =NULL;
//    if(crops_=="red")
//    {
//        city_num=-1;
//    }
//    else
//    {
//        city_num=N;
//    }
//
//}



Warriors::Warriors(int serial_num, int strength, Crops * c_) : serial_num(serial_num), strength(strength), c(c_) {


    sword = NULL;
    arrow = NULL;
    bomb =NULL;
    if(c->get_name() == "red")
    {
        city_num=1;
    }
    else
    {
        city_num=N;
    }
    crops = c->get_name();
    for(int i=0;i<3;i++)
    {
        weapon[i]=NULL;
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
        }
        p->Hurted(int(attack/2));
        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout<<hours<<':';
        cout.width(2); // 设置宽度
        cout.fill('0');// 设置填充
        cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" fought back against ";
        p->cout_info();
        cout<<" in city "<<city_num<<endl;

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
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" attacked ";
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

void Warriors::cout_march() {
    //000:10 red iceman 1 marched to city 1 with 20 elements and force 30
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" marched to city "
         <<city_num<<" with "<<strength<<" elements"<<" and force "<<attack<<endl;


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
        cout.width(3); // 设置宽度
        cout.fill('0');// 设置填充
        cout<<hours<<':';
        cout.width(2); // 设置宽度
        cout.fill('0');// 设置填充
        cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num<<" shot";
        if(w->get_lives()<=0)
        {
            cout<<" and killed ";
            w->cout_info();
        }
        cout<<endl;

//        005:35 red dragon 5 shot and killed blue ninja 3
    }



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

        if(city_num<N) {
            cities[city_num-1]->red_to_null();
            city_num += 1;
            cities[city_num-1]->add_r(this);

        }


    }
    else
    {
        if(city_num>1)
        {
            cities[city_num-1]->blue_to_null();
            city_num-=1;
            cities[city_num-1]->add_b(this);

        }

    }



}

void Warriors::cout_reach(Crops * c) {

//    021:10 red lion 2 reached blue headquarter
// with 2 elements and force 4

    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
         <<" reached " << c->get_name() <<" headquarter with "<<strength
         <<" elements and force "<<attack<<endl;


}

void Warriors::add_lives(int lives_) {
    strength+=lives_;
}

void Warriors::cout_die() {
//    001:40 red lion 2 was killed in city 1
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
         <<" was killed in city "<<city_num<<endl;

}

Sword *Warriors::get_sword() {
    return sword;
}

Arrow *Warriors::get_arrow() {
    return arrow;
}

Bomb *Warriors::get_bomb() {
    return bomb;
}

void Warriors::win(Warriors *loser,City *c) {


}

void Warriors::lose(Warriors *winner,City *c) {

}

void Warriors::after_fight(Warriors *w) {

}

Crops *Warriors::get_crop() {
    return c;
}

void Warriors::cout_weapons() {
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
         <<" has ";
    if(num_weapons()==-1)
    {
        cout<<"no weapon"<<endl;
    }
    else
    {
        int i=0;
        int temp=num_weapons();
        while(temp>=0)
        {
            for(i;i<3;i++)
            {
                if(weapon[i])
                {
                    weapon[i]->cout_condition();
                    i++;
                    break;
                }
            }
            if(temp==0)
            {
                cout<<endl;
            }
            else
            {
                cout<<',';
            }
            temp--;
        }

    }




}

int Warriors::num_weapons() {
    int temp=-1;

    if(arrow)
    {
        if(!arrow->if_exist())
        {
            delete arrow;
            arrow=NULL;
        }
        else
        {
            temp++;
            weapon[temp]=arrow;
        }

    }
    if(bomb)
    {
        temp++;
        weapon[temp]=bomb;

    }

    if(sword)
    {
        if(!sword->if_exist())
        {
            delete sword;
            sword=NULL;

        }
        else
        {
            temp++;
            weapon[temp]=sword;

        }

    }
    return temp;

}

void Warriors::cout_win_lives() {
    //003:40 red lion 2 earned 10 elements for his headquarter
    cout.width(3); // 设置宽度
    cout.fill('0');// 设置填充
    cout<<hours<<':';
    cout.width(2); // 设置宽度
    cout.fill('0');// 设置填充
    cout << minutes << ' ' << crops << ' ' <<name<<' '<< serial_num
         <<" earned "<<cities[city_num-1]->get_lives_info()<<" elements for his headquarter"<<endl;

}













