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
    bool isExit;
    bool revealSecret;
    bool visited;
    int index;
    vector<Object*> objects;
    vector<string> plots;

    Room* northRoom;
    Room* southRoom;
    Room* eastRoom;
    Room* westRoom;
    Room* innerRoom;
    Room* outerRoom;
    Room* secretRoom;
public:
    Room();
    Room(string name, bool isExit, int index, vector<Object*> objects, vector<string> plots);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/

    void callEnemy(Battle*);
    bool hasEnemy() const;
    void add(Object* obj);
    void remove(Object* obj);
    Room* getRoom(int direction);
    void readPlots();

    /* Set & Get function*/
    void setNorthRoom(Room*);
    void setSouthRoom(Room*);
    void setWestRoom(Room*);
    void setEastRoom(Room*);
    void setInnerRoom(Room*);
    void setOuterRoom(Room*);
    void setNeighborRoom(Room*, Room*, Room*, Room*, Room*, Room*, Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    void setRevealSecret(bool);
    string getName() const;
    bool getIsExit() const;
    bool hasSecretRoom() const;
    int getIndex() const;
    vector<Object*> getObjects() const;
    Room* getNorthRoom() const;
    Room* getSouthRoom() const;
    Room* getWestRoom() const;
    Room* getEastRoom() const;
    Room* getInnerRoom() const;
    Room* getOuterRoom() const;
    Room* getSecretRoom() const;

    friend class Record;
};

#endif // ROOM_H_INCLUDED