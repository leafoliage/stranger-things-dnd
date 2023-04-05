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
    int job;
    vector<Item*> inventory;
    Armor* armor;
public:
    Player();
    Player(string name, int job);
    Player(string name, int strength, int dexterity, int constitution, int wisdom);

    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);
    void attack(GameCharacter* rival, Item* equipment);
    int armorClass();
    int abilityCheck(int ability);
    Item* getWeapon();

    void take(Item*);
    void wear(Armor*);
    void discard(int index);
    bool pay(int money);
    bool acquire(Item*);
    int inputNumPrompt(int lowbound, int upbound);
    void listInventory();

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item*>);
    void setMoney(int);
    Room* getCurrentRoom() const;
    Room* getPreviousRoom() const;
    vector<Item*> getInventory() const;
    Armor* getArmor() const;
    int getMoney() const;
    int getJob() const;
};

#endif // PLAYER_H_INCLUDED
