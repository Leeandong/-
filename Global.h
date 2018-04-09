//
// Created by 李安东 on 2018/3/12.
//

#ifndef WAR2_0_GLOBAL_H
#define WAR2_0_GLOBAL_H




#endif //WAR2_0_GLOBAL_H

#include <string>
#include "City.h"

using namespace std;

//extern int game_time;
extern int hours;
extern int minutes;
extern string  warriors_name[5];
extern int   blue_sequence[5];
extern int  red_sequence[5];
extern int   warriors_strength[5];
extern string weapons_name[3];
extern int arrow_attack;
extern int warriors_attack[5];
extern int N; //城市数量
extern int lives; //初始的生命元数目
extern City ** cities; //城市的数目