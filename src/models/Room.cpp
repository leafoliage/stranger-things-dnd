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

void Room::setUpRoom(Room* room) {
    upRoom = room;
    room->setDownRoom(this);
}

void Room::setDownRoom(Room* room) {
    downRoom = room;
    room->setUpRoom(this);
}

void Room::setLeftRoom(Room* room) {
    leftRoom = room;
    room->setRightRoom(this);
}

void Room::setRightRoom(Room* room) {
    rightRoom = room;
    room->setLeftRoom(this);
}

void Room::setInnerRoom(Room* room) {
    innerRoom = room;
    room->setOuterRoom(this);
}

void Room::setOuterRoom(Room* room) {
    outerRoom = room;
}

void Room::setNeighborRoom(Room* up, Room* down, Room* left, Room* right, Room* inner, Room* outer) {
    upRoom = up; up->setDownRoom(this);
    downRoom = down; down->setUpRoom(this);
    leftRoom = left; left->setRightRoom(this);
    rightRoom = right; right->setLeftRoom(this);
    innerRoom = inner; inner->setOuterRoom(this);
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

Room* Room::getUpRoom() const {
    return upRoom;
}

Room* Room::getDownRoom() const {
    return downRoom;
}

Room* Room::getLeftRoom() const {
    return leftRoom;
}

Room* Room::getRightRoom() const {
    return rightRoom;
}

Room* Room::getInnerRoom() const {
    return innerRoom;
}

Room* Room::getOuterRoom() const {
    return outerRoom;
}
