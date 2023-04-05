#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Battle.h"

using namespace std;

class Room
{
private:
    string name;
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    Room* innerRoom;
    Room* outerRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(string name, bool isExit, int index, vector<Object*> objects);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/

    void callEnemy(Battle*);

    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setInnerRoom(Room*);
    void setOuterRoom(Room*);
    void setNeighborRoom(Room*, Room*, Room*, Room*, Room*, Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    bool getIsExit();
    int getIndex();
    vector<Object*> getObjects();
    Room* getUpRoom() const;
    Room* getDownRoom() const;
    Room* getLeftRoom() const;
    Room* getRightRoom() const;
    Room* getInnerRoom() const;
    Room* getOuterRoom() const;
};

#endif // ROOM_H_INCLUDED