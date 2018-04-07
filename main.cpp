//#include <iostream>
//#include<string>
//#include "Global.h"
//#include "Crops.h"
//
//using namespace std;
//
//
//int main() {
//    int n=0;  //输入的测试组数目
//    int lives;
//    cin>>n;
//    string a="blue";
//    string b="red";
//    for(int i=1;i<=n;i++)
//    {
//        game_time=0;
//        cin>>lives;
//        for (int j=0;j<5;j++)
//        {
//            cin>>warriors_strength[j];
//        };
//        Crops blue(lives,blue_sequence,a);
//        Crops red(lives,red_sequence,b);
//        cout<<"Case:"<<i<<endl;
//        while(!(red.if_stop()&&blue.if_stop()))
//        {
//            red.creat_warriors();
//            blue.creat_warriors();
//            game_time++;
//        }
//
//
//    }
//
//    return 0;
//}



//_____________________ 此处为分割线



# include<iostream>
# include <string>
# include "Lion.h"
# include "Wolf.h"
#include "Dragon.h"
#include "Crops.h"
#include "City.h"
#include "Ninja.h"
#include "Iceman.h"

void creat_warriors(Crops&c)  //制造士兵

{
    Warriors* temp=NULL;
    int i=c.which_to_creat();
    switch(i)
    {
        case 0:
        {
            temp=new Dragon(c.get_num(),warriors_strength[0],c.get_lives(),c.get_name());

            break;
        }
        case 1:
        {
            temp=new Ninja(c.get_num(),warriors_strength[1],c.get_name());
            break;
        }
        case 2:
        {
            temp=new Iceman(c.get_num(),warriors_strength[2],c.get_name());
            break;
        }
        case 3:
        {
            temp=new Lion(c.get_num(),warriors_strength[3],c.get_name(),c.get_lives());
            break;
        }
        case 4:
        {
            temp = new Wolf(c.get_num(), warriors_strength[4],c.get_name());
            break;
        }

    }
    if(temp)
    {
        temp->cout_born();
        c.add(temp);
    }

}


int main()
{
    int lives=20;  //初始时候赋给司令部的数据
    int N=1; //两座司令部之间的城市个数
    string a="blue";
    string b="red";
    Crops blue(lives,blue_sequence,a);
    Crops red(lives,red_sequence,b);
    City ** cities=new City*[N];
    for(int i=0;i<N;i++)
    {
        cities[i] = new City(i+1);
    }
    hours=0;
    minutes=0; //第0分钟制造士兵
    creat_warriors(red);
    creat_warriors(blue);
    while(hours<3)
    {
        minutes+=5;  //第5分钟lion逃跑
        for(int i=0;i<N;i++)
        {
            cities[i]->delete_run();
        }
        minutes+=5; //第10分钟武士前进
        if(cities[N-1]->get_r())  //如果某方司令部被攻陷，则结束程序
        {
            blue.add_enemy();
            if(blue.lose())
            {
                for(int i=0;i<N;i++)
                {
                    delete cities[i];
                }
                delete []cities;
                return 0;
            }

        }
        cities[N-1]->delete_r();
        if(cities[0]->get_b())
        {
            red.add_enemy();
            if(red.lose())
            {
                for(int i=0;i<N;i++)
                {
                    delete cities[i];
                }
                delete []cities;
                return 0;
            }

        }
        cities[0]->delete_b();
        for(int i=0;i<N-1;i++)
        {
            cities[N-1-i]->add_r(cities[N-i-2]->get_r());
            cities[i]->add_b(cities[i+1]->get_b());
        }
        cities[0]->add_r(red.get());
        cities[N-1]->add_b(blue.get());
        for(int i=0;i<N;i++)
        {
            if(cities[i]->get_r())
            {
                cities[i]->get_r()->cout_march(cities[i]);
            }
            if(cities[i]->get_b())
            {
                cities[i]->get_b()->cout_march(cities[i]);
            }

        }
        minutes+=10;//第20分钟城市生产生命元
        for(int i=0;i<N;i++)
        {
            cities[i]->produce_lives();
        }
        minutes+=10;//第30分钟若城市中仅有一个武士，获得所有的生命元
        for(int i=0;i<N;i++)
        {
            if((cities[i]->get_r()==NULL)&&(cities[i]->get_b()))
            {
                blue.add_lives(cities[i]->get_lives());
            }
            if((cities[i]->get_b()==NULL)&&(cities[i]->get_r()))
            {
                red.add_lives(cities[i]->get_lives());
            }
        }
        minutes+=5; //第35分钟拥有arrows的士兵放箭
        for(int i=1;i<N;i++)
        {
            if(cities[i]->get_b())
            {
                cities[i-1]->get_r()->Archery(cities[i]->get_b());
                if(cities[i]->get_b()->get_lives()<=0)
                {
                    cities[i]->delete_b();
                }
            }
            if(cities[N-i-1]->get_r())
            {
                cities[N-i]->get_b()->Archery(cities[N-i-1]->get_r());
                if(cities[N-i-1]->get_r()->get_lives()<=0)
                {
                    cities[i]->delete_r();
                }
            }
        }
        minutes+=3; //第38分钟拥有bombs的勇士自爆
        {
            for(int i=0;i<N;i++)
            {
                cities[i]->self_bursting();
            }
        }
        minutes+=2; //第四十分钟两个武士之间相互战斗



























    hours++;
    }




































    for(int i=0;i<N;i++)
    {
        delete cities[i];
    }
    delete []cities;
    return 0;





}
