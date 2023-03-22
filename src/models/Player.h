#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    int money;
    vector<Armor> wardrobe;
    vector<Weapon> weapons;
    vector<Item> inventory;
public:
    Player();
    Player(string,int,int,int,int);
    void addWeapon(Weapon);
    void addItem(Item);
    void increaseStates(int,int,int);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    int initiate();
    int attackCheck();
    int damage();

    void switchWeapon(int);
    Weapon getCurrWeapon() const;

    void switchArmor(int);
    Weapon getCurrArmor() const;

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setArmor(vector<Armor>);
    void setWeapons(vector<Weapon>);
    void setInventory(vector<Item>);
    Room* getCurrentRoom() const;
    Room* getPreviousRoom() const;
    vector<Armor> getWardrobe() const;
    vector<Weapon> getWeapons() const;
    vector<Item> getInventory() const;
};

#endif // PLAYER_H_INCLUDED
