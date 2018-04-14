# include<iostream>
# include <string>
# include "Lion.h"
# include "Wolf.h"
#include "Dragon.h"
#include "Crops.h"
#include "City.h"
#include "Ninja.h"
#include "Iceman.h"

void creat_warriors(Crops * c)  //制造士兵

{
    Warriors* temp=NULL;
    int i=c->which_to_creat();
    switch(i)
    {
        case 0:
        {
            temp=new Dragon(c->get_num(),warriors_strength[0],c->get_lives(),c);

            break;
        }
        case 1:
        {
            temp=new Ninja(c->get_num(),warriors_strength[1],c);
            break;
        }
        case 2:
        {
            temp=new Iceman(c->get_num(),warriors_strength[2],c);
            break;
        }
        case 3:
        {
            temp=new Lion(c->get_num(),warriors_strength[3],c,c->get_lives());
            break;
        }
        case 4:
        {
            temp = new Wolf(c->get_num(), warriors_strength[4],c);
            break;
        }

    }
    if(temp)
    {
        temp->cout_born();
        c->add(temp);
    }

}


int main() {
    int n;  //输入的测试组数目
    int lives;
    cin>>n;
    string a="blue";
    string b="red";
    int T;
    for(int i=1;i<=n;i++)
    {
        int stop=0;  //战争结束的标志,为1则表明战争结束
        hours=0;
        cin>>lives;
        cin>>N; //输入中间间隔的城市
        cin>>arrow_attack; //输入arrow的攻击值
        cin>>K; //输入狮子降低的忠诚值
        cin>>T; //游戏运行的次数
        for (int j=0;j<5;j++)
        {
            cin>>warriors_strength[j];
        };
        for (int j=0;j<5;j++)
        {
            cin>>warriors_attack[j];
        };
        Crops blue(lives,blue_sequence,a);
        Crops red(lives,red_sequence,b);
        cities=new City*[N];
        for(int i=0;i<N;i++)
        {
            cities[i] = new City(i+1);
        }
        cout<<"Case:"<<i<<endl;
        while(1) {
            minutes = 0;
            creat_warriors(&red);
            creat_warriors(&blue);
            minutes += 5;  //第5分钟lion逃跑
            T-=5;
            if(T<0)
            {
                break;
            }
            red.delete_run();
            for (int i = 0; i < N; i++) {
                cities[i]->delete_run();
            }
            blue.delete_run();
            minutes += 5; //第10分钟武士前进
            T-=5;
            if(T<0)
            {
                break;
            }
            if (cities[0]->get_b()) {
                red.add_enemy(cities[0]->get_b());
                cities[0]->blue_to_null();
            }
            if (cities[N - 1]->get_r()) {
                blue.add_enemy(cities[N - 1]->get_r());
                cities[N-1]->red_to_null();
            }
            for (int i = 1; i < N; i++) {
                if (cities[N - i - 1]->get_r()) {
                    cities[N - i - 1]->get_r()->forward();
                }
                if (cities[i]->get_b()) {
                    cities[i]->get_b()->forward();
                }
            }
            if (red.get()) {
                cities[0]->add_r(red.get());
                red.warriors_to_null();
            }
            if (blue.get()) {
                cities[N - 1]->add_b(blue.get());
                blue.warriors_to_null();
            }
            red.cout_reach();
//            if (red.lose()) {
//                for (int i = 0; i < N; i++) {
//                    delete cities[i];
//                }
//                delete[]cities;
//                break;
//            }
            if (red.lose()) {
                stop=1;
            }
            for (int i = 0; i < N; i++) {
                if (cities[i]->get_r()) {
                    cities[i]->get_r()->cout_march();

                }
                if (cities[i]->get_b()) {
                    cities[i]->get_b()->cout_march();

                }
            }
            blue.cout_reach();
            if (blue.lose()) {
                stop=1;
            }
            if (stop) {
                for (int i = 0; i < N; i++) {
                    delete cities[i];
                }
                delete[]cities;
                break;
            }
            minutes += 10;//第20分钟城市生产生命元
            T-=10;
            if(T<0)
            {
                break;
            }
            for (int i = 0; i < N; i++) {
                cities[i]->produce_lives();
            }
            minutes += 10;//第30分钟若城市中仅有一个武士，获得所有的生命元
            T-=10;
            if(T<0)
            {
                break;
            }
            for (int i = 0; i < N; i++) {
                if ((cities[i]->get_b() == NULL) && (cities[i]->get_r())) {
                    cities[i]->get_r()->cout_get_lives(cities[i]);
                    red.add_lives(cities[i]->get_lives());
                }
                if ((cities[i]->get_r() == NULL) && (cities[i]->get_b())) {
                    cities[i]->get_b()->cout_get_lives(cities[i]);

                    blue.add_lives(cities[i]->get_lives());
                }

            }
            minutes += 5; //第35分钟拥有arrows的士兵放箭
            T-=5;
            if(T<0)
            {
                break;
            }
            if (cities[0]->get_b()) {
                if (red.get()) {
                    red.get()->Archery(cities[0]->get_b());
                }
            }
            if(cities[1]->get_b())
            {
                if (cities[0]->get_r()) {
                    cities[0]->get_r()->Archery(cities[1]->get_b());
                }
            }
            for (int i = 1; i < N-1; i++) {
                if (cities[i+1]->get_b()) {
                    if (cities[i]->get_r()) {
                        cities[i]->get_r()->Archery(cities[i+1]->get_b());
                    }
                }
                if (cities[i-1]->get_r()) {
                    if (cities[i]->get_b()) {
                        cities[i]->get_b()->Archery(cities[i-1]->get_r());
                    }
                }
            }

            if (cities[N-2]->get_r()) {
                if (cities[N-1]->get_b()) {
                    cities[N-1]->get_b()->Archery(cities[N-2]->get_r());
                }
            }
            if (cities[N-1]->get_r()) {
                if (blue.get()) {
                    blue.get()->Archery(cities[N-1]->get_r());
                }
            }
            minutes += 3; //第38分钟拥有bombs的勇士自爆
            T-=3;
            if(T<0)
            {
                break;
            }
            {
                for (int i = 0; i < N; i++) {
                    cities[i]->self_bursting();
                }
            }
            minutes += 2; //第四十分钟两个武士之间相互战斗
            T-=2;
            if(T<0)
            {
                break;
            }
            for (int i = 0; i < N; i++) {
                cities[i]->Fight_in_city();
            }
            for( int i=0;i<N;i++)
            {
                red.Award(cities[N-1-i]);
                blue.Award(cities[i]);
            }
            for(int i=0;i<N;i++)
            {
                cities[i]->after_fight();
            }
            minutes += 10; //第50分钟司令部报告生命元数目
            T-=10;
            if(T<0)
            {
                break;
            }
            {
//            000:50 100 elements in red headquarter
                red.cout_lives();
                blue.cout_lives();

            }
            minutes += 5; //第55分钟武士报告武器情况
            T-=5;
            if(T<0)
            {
                break;
            }
            {

                for (int i = 0; i < N; i++) {
                    cities[i]->cout_r_weapon();

                }
                blue.cout_enemys_weapon();
                red.cout_enemys_weapon();
                for (int i = 0; i < N; i++) {
                    cities[i]->cout_b_weapon();

                }

            }
            T-=5;
            if(T<0)
            {
                break;
            }
            hours++;
        }


    }

    return 0;
}



//_____________________ 此处为分割线



//# include<iostream>
//# include <string>
//# include "Lion.h"
//# include "Wolf.h"
//#include "Dragon.h"
//#include "Crops.h"
//#include "City.h"
//#include "Ninja.h"
//#include "Iceman.h"
//
//void creat_warriors(Crops * c)  //制造士兵
//
//{
//    Warriors* temp=NULL;
//    int i=c->which_to_creat();
//    switch(i)
//    {
//        case 0:
//        {
//            temp=new Dragon(c->get_num(),warriors_strength[0],c->get_lives(),c);
//
//            break;
//        }
//        case 1:
//        {
//            temp=new Ninja(c->get_num(),warriors_strength[1],c);
//            break;
//        }
//        case 2:
//        {
//            temp=new Iceman(c->get_num(),warriors_strength[2],c);
//            break;
//        }
//        case 3:
//        {
//            temp=new Lion(c->get_num(),warriors_strength[3],c,c->get_lives());
//            break;
//        }
//        case 4:
//        {
//            temp = new Wolf(c->get_num(), warriors_strength[4],c);
//            break;
//        }
//
//    }
//    if(temp)
//    {
//        temp->cout_born();
//        c->add(temp);
//    }
//
//}
//
//
//int main()
//{
//    lives=200;  //初始时候赋给司令部的数据
//    N=6; //两座司令部之间的城市个数
//    string a="blue";
//    string b="red";
//    Crops blue(lives,blue_sequence,a);
//    Crops red(lives,red_sequence,b);
//    cities=new City*[N];
//    for(int i=0;i<N;i++)
//    {
//        cities[i] = new City(i+1);
//    }
//    hours=0;
//    while(hours<10) {
//        minutes = 0;
//        creat_warriors(&red);
//        creat_warriors(&blue);
//        minutes += 5;  //第5分钟lion逃跑
//        red.delete_run();
//        for (int i = 0; i < N; i++) {
//            cities[i]->delete_run();
//        }
//        blue.delete_run();
//        minutes += 5; //第10分钟武士前进
//        if (cities[0]->get_b()) {
//            red.add_enemy(cities[0]->get_b());
//        }
//        if (cities[N - 1]->get_r()) {
//            blue.add_enemy(cities[N - 1]->get_r());
//        }
//        for (int i = 1; i < N; i++) {
//            if (cities[N - i - 1]->get_r()) {
//                cities[N - i - 1]->get_r()->forward();
//            }
//            if (cities[i]->get_b()) {
//                cities[i]->get_b()->forward();
//            }
//        }
//        if (red.get()) {
//            cities[0]->add_r(red.get());
//            red.warriors_to_null();
//        }
//        if (blue.get()) {
//            cities[N - 1]->add_b(blue.get());
//            blue.warriors_to_null();
//        }
//        red.cout_reach();
//        if (red.lose()) {
//            for (int i = 0; i < N; i++) {
//                delete cities[i];
//            }
//            delete[]cities;
//            return 0;
//        }
//        for (int i = 0; i < N; i++) {
//            if (cities[i]->get_r()) {
//                cities[i]->get_r()->cout_march();
//
//            }
//            if (cities[i]->get_b()) {
//                cities[i]->get_b()->cout_march();
//
//            }
//        }
//        blue.cout_reach();
//        if (blue.lose()) {
//            for (int i = 0; i < N; i++) {
//                delete cities[i];
//            }
//            delete[]cities;
//            return 0;
//        }
//
//        minutes += 10;//第20分钟城市生产生命元
//        for (int i = 0; i < N; i++) {
//            cities[i]->produce_lives();
//        }
//        minutes += 10;//第30分钟若城市中仅有一个武士，获得所有的生命元
//        for (int i = 0; i < N; i++) {
//            if ((cities[i]->get_b() == NULL) && (cities[i]->get_r())) {
//                cities[i]->get_r()->cout_get_lives(cities[i]);
//                red.add_lives(cities[i]->get_lives());
//            }
//            if ((cities[i]->get_r() == NULL) && (cities[i]->get_b())) {
//                cities[i]->get_b()->cout_get_lives(cities[i]);
//
//                blue.add_lives(cities[i]->get_lives());
//            }
//
//        }
//        minutes += 5; //第35分钟拥有arrows的士兵放箭
////        if (cities[0]->get_b()) {
////            if (red.get()) {
////                red.get()->Archery(cities[0]->get_b());
////            }
////        }
////        for (int i = 1; i < N; i++) {
////            if (cities[i]->get_b()) {
////                if (cities[i - 1]->get_r()) {
////                    cities[i - 1]->get_r()->Archery(cities[i]->get_b());
////                }
////
////            }
////            if (cities[N - i - 1]->get_r()) {
////                if (cities[N - i]->get_b()) {
////                    cities[N - i]->get_b()->Archery(cities[N - i - 1]->get_r());
////                }
////
////            }
////        }
////
////        if (cities[N - 1]->get_r()) {
////            if (blue.get()) {
////                blue.get()->Archery(cities[0]->get_r());
////                }
////
////        }
//        if (cities[0]->get_b()) {
//            if (red.get()) {
//                red.get()->Archery(cities[0]->get_b());
//            }
//        }
//        if(cities[1]->get_b())
//        {
//            if (cities[0]->get_r()) {
//                cities[0]->get_r()->Archery(cities[1]->get_b());
//            }
//        }
//        for (int i = 1; i < N-1; i++) {
//            if (cities[i+1]->get_b()) {
//                if (cities[i]->get_r()) {
//                    cities[i]->get_r()->Archery(cities[i+1]->get_b());
//                }
//            }
//            if (cities[i-1]->get_r()) {
//                if (cities[i]->get_b()) {
//                    cities[i]->get_b()->Archery(cities[i-1]->get_r());
//                }
//            }
//        }
//
//        if (cities[N-2]->get_r()) {
//            if (cities[N-1]->get_b()) {
//                cities[N-1]->get_b()->Archery(cities[N-2]->get_r());
//            }
//        }
//        if (cities[N-1]->get_r()) {
//            if (blue.get()) {
//                blue.get()->Archery(cities[N-1]->get_r());
//            }
//        }
//        minutes += 3; //第38分钟拥有bombs的勇士自爆
//        {
//            for (int i = 0; i < N; i++) {
//                cities[i]->self_bursting();
//            }
//        }
//        minutes += 2; //第四十分钟两个武士之间相互战斗
//        for (int i = 0; i < N; i++) {
//            cities[i]->Fight_in_city();
//        }
//        for( int i=0;i<N;i++)
//        {
//            red.Award(cities[N-1-i]);
//            blue.Award(cities[i]);
//        }
//        for(int i=0;i<N;i++)
//        {
//            cities[i]->after_fight();
//        }
//        minutes += 10; //第50分钟司令部报告生命元数目
//        {
////            000:50 100 elements in red headquarter
//            red.cout_lives();
//            blue.cout_lives();
//
//        }
//        minutes += 5; //第55分钟武士报告武器情况
//        {
//
//            for (int i = 0; i < N; i++) {
//                cities[i]->cout_r_weapon();
//
//            }
//            blue.cout_enemys_weapon();
//            red.cout_enemys_weapon();
//            for (int i = 0; i < N; i++) {
//                cities[i]->cout_b_weapon();
//
//            }
//
//        }
//
//
//        hours++;
//    }
//
//
//    for(int i=0;i<N;i++)
//    {
//        delete cities[i];
//    }
//    delete []cities;
//
//    return 0;
//}

