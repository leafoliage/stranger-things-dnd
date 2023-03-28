#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Armor.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    int money;
    vector<Item*> inventory;
    Armor* armor;
public:
    Player();
    Player(string name, int strength, int dexterity, int constitution, int wisdom);

    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    void take(Item*);
    void wear(Armor*);
    void discard(int index);

    // int initiate();
    // int attackCheck();
    // int damage();

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item*>);
    Room* getCurrentRoom() const;
    Room* getPreviousRoom() const;
    vector<Item*> getInventory() const;
    Armor* getArmor() const;
};

#endif // PLAYER_H_INCLUDED
