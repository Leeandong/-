//
// Created by 李安东 on 2018/3/30.
//

#include "City.h"

void City::produce_lives() {
    lives+=10;

}

void City::set_flag(int color) {
    flag=color;

}

int City::get_lives() {
    int temp=lives;
    lives=0;
    return lives;
}

void City::attack() {
    if((index%2==1)||(flag==1))
    {
        b->attack(r);
    }
    else
    {
        r->attack(b);
    }

}

bool City::check_r() {
    if(r)
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool City::check_b() {

    if(b)
    {
        return false;
    }
    else
    {
        return true;
    }

}

City::City(int index) : index(index) {
    r=NULL;
    b=NULL;
    flag=0;
    lives=0;
}

void City::delete_warroris() {
    if(b)
    {
        delete(b);
    }
    if(r)
    {
        delete(r);
    }
}
