//#include <iostream>
//#include<string>
//#include "Global.h"
//#include "crops.h"
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
//        crops blue(lives,blue_sequence,a);
//        crops red(lives,red_sequence,b);
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

int main()
{

    Dragon d(0,29,20);
    Wolf w(1,30);
    d.attack(&w);
    w.attack(&d);
    w.attack(&d);
    w.attack(&d);
    return 0;
}