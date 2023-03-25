#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
#include "enums.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int itemType;
    int hardness;
    int visibility;
public:
    Item();
    Item(string, int, int, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object*);

    virtual int useHardness();

    /* Set & Get function*/
    void setItemType(int);
    void setHardness(int);
    void setVisibility(int);
    int getItemType() const;
    int getHardness() const;
    int getVisibility() const;
};

#endif // ITEM_H_INCLUDED
