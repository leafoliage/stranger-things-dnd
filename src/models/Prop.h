#ifndef PROP_H_INCLUDED
#define PROP_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Prop: public Item {
    private:

    public:
        Prop();
        Prop(string name, int quality, int price);

        int useQuality(GameCharacter* user);
        void workOn(GameCharacter* target, GameCharacter* user);
        bool triggerEvent(Object*);
};

#endif // PROP_H_INCLUDED