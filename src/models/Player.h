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

    // add armor to the wardrobe
    void addArmor(Armor);

    // add weapons to the weapons list
    void addWeapon(Weapon);

    // add item to the item list
    void addItem(Item);

    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    // int initiate();
    // int attackCheck();
    // int damage();

    // switch the weapon of the given number with the first weapon in the weapons list
    void switchWeapon(int);

    // get the first weapon in the weapons list
    Weapon getCurrWeapon() const;

    // switch the armor of the given number with the first armor in the wardrobe
    void switchArmor(int);

    // get the first armor in the wardrobe
    Armor getCurrArmor() const;

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
