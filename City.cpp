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



City::City(int index) : index(index) {
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
