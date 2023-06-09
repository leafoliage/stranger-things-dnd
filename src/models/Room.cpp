#include "Room.h"

Room::Room() {}

Room::Room(string name, bool isExit, int index,  vector<string> plots)
    : name(name), isExit(isExit), index(index), plots(plots),
    northRoom(NULL), southRoom(NULL), eastRoom(NULL), westRoom(NULL), 
    innerRoom(NULL), outerRoom(NULL), secretRoom(NULL), revealSecret(true), visited(false) {}

Room::Room(string name, bool isExit, int index, vector<Object*> objects, vector<string> plots)
    : name(name), isExit(isExit), index(index), objects(objects), plots(plots),
    northRoom(NULL), southRoom(NULL), eastRoom(NULL), westRoom(NULL), 
    innerRoom(NULL), outerRoom(NULL), secretRoom(NULL), revealSecret(true), visited(false) {}

bool Room::popObject(Object* obj) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (*it == obj) {
            objects.erase(it);
            return true;
        }
    }
    return false;
}

void Room::callEnemy(Battle* battle) {
    for (auto it=objects.begin();it!=objects.end();++it) {
        Object* obj = *it;
        if (obj->getObjectType()==ObjectType::CHARACTER) {
            GameCharacter* character = dynamic_cast<GameCharacter*>(obj);
            if (character->getCharacterType() == CharacterType::ENEMY) {
                battle->add(character);
            }
        }
    }
}

bool Room::hasEnemy() const {
    for (int i=0;i<objects.size();i++) {
        if (objects[i]->getType() == tENEMY) return true;
    }
    return false;
}

void Room::add(Object* obj) {
    objects.push_back(obj);
}

void Room::remove(Object* obj) {
    int size = objects.size();
    for (int i=0;i<size;i++) {
        if (objects[i]==obj) {
            objects.erase(objects.begin() + i);
        }
    }
}

Room* Room::getRoom(int direction) {
    switch (direction)
    {
    case Direction::NORTH: return northRoom;
    case Direction::SOUTH: return southRoom;
    case Direction::EAST: return eastRoom;
    case Direction::WEST: return westRoom;
    case Direction::IN: return innerRoom;
    case Direction::OUT: return outerRoom;
    default: return NULL;
    }
}

void Room::readPlots() {
    if (visited || plots.empty()) return;
    visited = true;
    log("");
    for (auto it=plots.begin();it!=plots.end();++it) {
        log(*it);
    }
}

void Room::setNorthRoom(Room* room) {
    northRoom = room;
    room->setSouthRoom(this);
}

void Room::setSouthRoom(Room* room) {
    southRoom = room;
}

void Room::setWestRoom(Room* room) {
    westRoom = room;
}

void Room::setEastRoom(Room* room) {
    eastRoom = room;
}

void Room::setInnerRoom(Room* room) {
    innerRoom = room;
}

void Room::setOuterRoom(Room* room) {
    outerRoom = room;
}

void Room::setNeighborRoom(Room* north, Room* south, Room* east, Room* west, Room* inner, Room* outer, Room* secret) {
    northRoom = north; 
    southRoom = south; 
    westRoom = west;
    eastRoom = east;
    innerRoom = inner;
    outerRoom = outer;
    secretRoom = secret;
}

void Room::setIsExit(bool value) {
    isExit = value;
}

void Room::setRevealSecret(bool reveal) {
    revealSecret = reveal;
}

void Room::setIndex(int value) {
    index = value;
}

void Room::setObjects(vector<Object*> objs) {
    objects = objs;
}

string Room::getName() const {
    return name;
}

bool Room::getIsExit() const {
    return isExit;
}

bool Room::hasSecretRoom() const {
    return revealSecret && secretRoom != NULL;
}

int Room::getIndex() const {
    return index;
}

vector<Object*> Room::getObjects() const {
    return objects;
}

Room* Room::getNorthRoom() const {
    return northRoom;
}

Room* Room::getSouthRoom() const {
    return southRoom;
}

Room* Room::getWestRoom() const {
    return westRoom;
}

Room* Room::getEastRoom() const {
    return eastRoom;
}

Room* Room::getInnerRoom() const {
    return innerRoom;
}

Room* Room::getOuterRoom() const {
    return outerRoom;
}

Room* Room::getSecretRoom() const {
    if (revealSecret) return secretRoom;
    return NULL;
}
