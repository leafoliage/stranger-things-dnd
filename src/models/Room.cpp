#include "Room.h"

Room::Room() {}

Room::Room(string name, bool isExit, int index, vector<Object*> objects)
    : name(name), isExit(isExit), index(index), objects(objects) {}

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

void Room::setNeighborRoom(Room* north, Room* south, Room* west, Room* east, Room* inner, Room* outer) {
    northRoom = north; 
    southRoom = south; 
    westRoom = west;
    eastRoom = east;
    innerRoom = inner;
    outerRoom = outer;
}

void Room::setIsExit(bool value) {
    isExit = value;
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
