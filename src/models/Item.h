#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Player;
class GameCharacter;

class Item: public Object
{
private:
    int itemType;
    int quality;
    int price;
public:
    Item();
    Item(string name, int itemType, int quality, int price);

    virtual int useQuality(GameCharacter* user) = 0;
    virtual void workOn(GameCharacter* target, GameCharacter* user) = 0;

    int getType();

    /* Set & Get function*/
    void setItemType(int);
    void setQuality(int);
    void setPrice(int);
    int getItemType() const;
    int getQuality() const;
    int getPrice() const;
};

#endif // ITEM_H_INCLUDED
