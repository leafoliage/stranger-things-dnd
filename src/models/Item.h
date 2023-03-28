#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int itemType;
    int quality;
    int visibility;
public:
    Item();
    Item(string name, int itemType, int quality, int visibility);

    virtual int useQuality(Player*) = 0;

    /* Set & Get function*/
    void setItemType(int);
    void setQuality(int);
    void setVisibility(int);
    int getItemType() const;
    int getQuality() const;
    int getVisibility() const;
};

#endif // ITEM_H_INCLUDED
