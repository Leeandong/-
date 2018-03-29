//
// Created by 李安东 on 2018/3/14.
//

#include "Arrow.h"
#include "Warriors.h"
#include "Global.h"

Arrow::Arrow():Weapon(arrow_attack) { name="arrow"; remains=3;}
void Arrow::Attack(Warriors *p) {
    if(remains>0)
    {
        p->Hurted(attack);
        remains--;
    }
}
