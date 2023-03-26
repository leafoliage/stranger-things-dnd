#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
#include "Item.h"
#include "enums.h"
using namespace std;

class Armor: public Item {
    private:

    public:
        Armor();
        Armor(string, int, int);
        int useHardness();
        
};

#endif // ARMOR_H_INCLUDED